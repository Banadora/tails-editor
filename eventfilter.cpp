#include "eventfilter.h"
#include "editor.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QKeyEvent>
#include <QList>
#include <QDebug>

extern xEditor *editor;

xEventFilter::xEventFilter(QObject *parent, xMainWindow *nW) :
    QObject(parent),
    w(nW)
{
    qDebug() << w;
}

bool xEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    /*QList<QWidget *> apps = QApplication::topLevelWidgets();
    xMainWindow *mw = dynamic_cast<xMainWindow*>(apps[0]);
    w = mw;*/

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

        case Qt::Key_Space:     { w->on_placeBtn_clicked(); break; }

    }

    return true;
}
