#ifndef EDITOR_H
#define EDITOR_H

#include "selection.h"
#include "block.h"
#include "map.h"

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>

#define nbBlocksX 12
#define nbBlocksY 12
#define PixelsX 32      //blocks width in pixels
#define PixelsY 32      //blocks height in pixels
//#define PixelsMove 8   //move distance in pixels

class xEditor: public QGraphicsView {

    Q_OBJECT

public:
    xEditor(int viewWidth, int viewHeight);

    void fillMap(QString blockName, bool isObs);

    void setSelectPos(int nX, int nY);
    void placeBlock(QString name, bool isObs);

    void saveMap(QString nName);
    void loadMap(QString nName);

    QGraphicsScene *scene;
    xSelection *selection;
    xBlock *block;
    xBlock *redfilter;
};

#endif // EDITOR_H
