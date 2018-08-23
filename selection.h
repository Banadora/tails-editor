#ifndef SELECTION_H
#define SELECTION_H

#include "block.h"

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class xSelection : public QObject, public QGraphicsPixmapItem {

public:
    xSelection();

    void move(QString direction);
};

#endif // SELECTION_H
