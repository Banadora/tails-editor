#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>


class xBlock : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

protected:
    QString name;
    int width;
    int height;
    int x;
    int y;
    bool obstacle;

public:
    xBlock(QString blockName);

    void setName (QString nName);
    QString getName();

    void setX (int nX);
    void setY (int nY);
    int getX();
    int getY();

    void defineIfObstacle(QString blockName);
    bool isObstacle();

    //virtual exit funcs:
    virtual int getDestinationLayout() const;
    virtual int getDestinationX() const;
    virtual int getDestinationY() const;
};

#endif // BLOCK_H
