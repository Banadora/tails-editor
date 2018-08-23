#ifndef EDITOR_H
#define EDITOR_H

#include "selection.h"
#include "block.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class xEditor: public QGraphicsView {

public:
    xEditor(int viewWidth, int viewHeight);

    void setSelectPos(int nX, int nY);
    void placeBlock(QString name, bool isObs);

    QGraphicsScene *scene;
    xSelection *selection;
    xBlock *block;
};

#endif // EDITOR_H
