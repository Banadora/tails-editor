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
    fillMap("blank", true);
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
    scene->addItem(block);

    //remove old block
    QList<QGraphicsItem *> colliding_items = block->collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(xBlock)) {
            scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }

    qDebug() << "~~~~ New block placed ~~~~";
    QString blockID;
    blockID = "name:" + block->getName() + ", isObs:" + QString::number(block->getIsObstacle());
    qDebug() << blockID;
}

void xEditor::saveMap(QString nName) {
    xMap map;
    xBlock *testblock = new xBlock();

    QList<QGraphicsItem *> sceneItems = scene->items();
    for (int i = 0, n = sceneItems.size(); i < n; ++i) {
        if (typeid(*(sceneItems[i])) == typeid(xBlock)) {
            testblock = qgraphicsitem_cast<xBlock *>(sceneItems[i]);
            map.setBlock(*testblock);
        }
    }

    map.saveJson(nName);

    testblock = nullptr;
    delete testblock;
}

