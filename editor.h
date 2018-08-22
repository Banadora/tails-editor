#ifndef EDITOR_H
#define EDITOR_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class xEditor: public QGraphicsView {

public:
    xEditor(int viewWidth, int viewHeight);
    void setSelectPos(int nX, int nY);

    QGraphicsScene *scene;
    QGraphicsPixmapItem *selection;
};

#endif // EDITOR_H
