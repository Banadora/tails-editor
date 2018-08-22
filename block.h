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
    bool isObstacle;

public:
    xBlock(QString blockName, bool isObs);
};

#endif // BLOCK_H
