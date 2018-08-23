#include "eventfilter.h"
#include "editor.h"

#include <QKeyEvent>
#include <QDebug>

extern xEditor *editor;

xEventFilter::xEventFilter(QObject *parent) :
    QObject(parent)
{ }

bool xEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() != QEvent::KeyPress)
        return QObject::eventFilter(obj, event);

    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

    switch(keyEvent->key()) {
        //selection movements
        case Qt::Key_Z:         { editor->selection->move("north"); break; }
        case Qt::Key_Up:        { editor->selection->move("north"); break; }
        case Qt::Key_S:         { editor->selection->move("south"); break; }
        case Qt::Key_Down:      { editor->selection->move("south"); break; }
        case Qt::Key_Q:         { editor->selection->move("west"); break; }
        case Qt::Key_Left:      { editor->selection->move("west"); break; }
        case Qt::Key_D:         { editor->selection->move("east"); break; }
        case Qt::Key_Right:     { editor->selection->move("east"); break; }

        case Qt::Key_Space:     { break; }
    }

    return true;
}
