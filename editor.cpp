#include "editor.h"

#include <QBrush>
#include <QImage>
#include <QPointF>
#include <QString>
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
    selection->setPos(0, 0);
    scene->addItem(selection);
}

void xEditor::setSelectPos(int nX, int nY) {
    selection->setPos(nX/32*32, nY/32*32);
    qDebug() << nX/32;
    qDebug() << nY/32;
}

void xEditor::placeBlock(QString name, bool isObs) {
    block = new xBlock(name, isObs);
    //qDebug() << ui->ImagesList->currentText();
    block->setPos(selection->pos().x(), selection->pos().y());
    scene->addItem(block);
}

