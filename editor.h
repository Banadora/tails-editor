#ifndef EDITOR_H
#define EDITOR_H

#include "selection.h"
#include "block.h"

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class xEditor: public QGraphicsView {

    Q_OBJECT

public:
    xEditor(int viewWidth, int viewHeight);

    void fillMap(QString blockName, bool isObs);

    void setSelectPos(int nX, int nY);
    void placeBlock(QString name, bool isObs);

    QGraphicsScene *scene;
    xSelection *selection;
    xBlock *block;
};

#endif // EDITOR_H
