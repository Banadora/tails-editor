#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>



class xBlock : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

protected:
    QString name;
    bool isObstacle;

public:
    xBlock(QString blockName, bool isObs);

    QString getName();
    bool getIsObstacle();
};

#endif // BLOCK_H
