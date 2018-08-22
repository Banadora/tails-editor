#ifndef EDITOR_H
#define EDITOR_H

#include "selection.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>

class xEditor: public QGraphicsView {

public:
    xEditor(int viewWidth, int viewHeight);

    void setSelectPos(int nX, int nY);

    QGraphicsScene *scene;
    xSelection *selection;
};

#endif // EDITOR_H
