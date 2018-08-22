#ifndef SELECTION_H
#define SELECTION_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class xSelection : public QObject, public QGraphicsPixmapItem {

public:
    xSelection();

    void keyPressEvent(QKeyEvent *e);
};

#endif // SELECTION_H
