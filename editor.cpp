#include "editor.h"

#include <QBrush>
#include <QImage>
#include <QPointF>
#include <QString>
#include <QList>
#include <QDebug>

xEditor::xEditor(int viewWidth, int viewHeight): QGraphicsView () {

    //create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, viewWidth, viewHeight);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //draw selection
    selection = new xSelection;
    selection->setPixmap(QPixmap(":/img/selection.png"));
    selection->setFlag(QGraphicsItem::ItemIsFocusable);
    selection->setFocus();
    selection->setZValue(10);
    selection->setPos(0, 0);
    scene->addItem(selection);

    //fill map editor with blank blocks to have blocks everywhere at everytime
    map = new xMap();
    fillMap("blank", false);
}

void xEditor::fillMap(QString blockName, bool isObs) {
    //store selection pos to restore it after filling
    QPointF lastSelectionPos = selection->pos();
    //fill map
    for (int x = 0; x < nbBlocksX; x++) {
        for (int y = 0; y < nbBlocksY; y++) {
            setSelectPos(x*PixelsX, y*PixelsY);
            placeBlock(blockName, isObs);
        }
    }
    //restore selection pos
    selection->setPos(lastSelectionPos);
}

void xEditor::setSelectPos(int nX, int nY) {
    selection->setPos(nX/PixelsX*PixelsX, nY/PixelsY*PixelsY);
    qDebug() << nX/PixelsX;
    qDebug() << nY/PixelsY;
}

void xEditor::placeBlock(QString name, bool isObs) {
    //place new block
    block = new xBlock(name, isObs);
    block->setPos(selection->pos().x(), selection->pos().y());
    block->setZValue(1);
    scene->addItem(block);

    //remove old block
    QList<QGraphicsItem *> colliding_items = block->collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(xBlock)) {
            scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }

    //add redfilter if xblock is an obstacle
    if (block->getIsObstacle()) {
        redfilter = new xBlock("redfilter", false);
        redfilter->setPixmap(QPixmap(":/img/redfilter.png"));
        redfilter->setPos(selection->pos().x(), selection->pos().y());
        redfilter->setZValue(2);
        scene->addItem(redfilter);
    }
}

void xEditor::placeEnemy(QString name, int hp, int dmg) {
    //place new enemy
    enemy = new xEnemyView(nullptr, name);
    enemy->setPos(selection->pos().x(), selection->pos().y());
    enemy->setZValue(3);
    enemy->setHP(hp);
    enemy->setDmg(dmg);
    scene->addItem(enemy);
    qDebug() << enemy->getHP() << enemy->getDmg();

    //remove old enemy
    QList<QGraphicsItem *> colliding_items = enemy->collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(xEnemyView)) {
            scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
    //if deleting enemy, delete blank enemy too
    if (name == "blank") { scene->removeItem(enemy); delete enemy; }
}

void xEditor::saveMap(QString nName, QString north, QString east, QString south, QString west) {
    //map = new xMap();

    map->clearArrays();

    //add blocks and enemies to map before saving
    xBlock *testblock = new xBlock();
    xEnemyView *testenemy = new xEnemyView(nullptr, "blank");

    QList<QGraphicsItem *> sceneItems = scene->items();
    for (int i = 0, n = sceneItems.size(); i < n; ++i) {
        //search blocks
        if (typeid(*(sceneItems[i])) == typeid(xBlock)) {
            testblock = qgraphicsitem_cast<xBlock *>(sceneItems[i]);
            if (testblock->getName() != "redfilter") { map->setBlock(*testblock); }
        }
        //search enemies
        if (typeid(*(sceneItems[i])) == typeid(xEnemyView)) {
            testenemy = qgraphicsitem_cast<xEnemyView *>(sceneItems[i]);
            map->setEnemy(*testenemy);
        }
    }

    map->saveJson(nName, north, east, south, west);

    testblock = nullptr; delete testblock;
    testenemy = nullptr; delete testenemy;
}

void xEditor::loadMap(QString nName) {
    //map = new xMap();

    xEnemyView *testenemy = new xEnemyView(nullptr, "blank");

    QList<QGraphicsItem *> sceneItems = scene->items();
    for (int i = 0, n = sceneItems.size(); i < n; ++i) {
        //search enemies
        if (typeid(*(sceneItems[i])) == typeid(xEnemyView)) {
            testenemy = qgraphicsitem_cast<xEnemyView *>(sceneItems[i]);
            scene->removeItem(testenemy);
            delete testenemy;
        }
    }

    map->loadJson(nName);
}

