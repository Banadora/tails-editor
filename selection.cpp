#include "selection.h"
#include "editor.h"
#include "mainwindow.h"

#include <QDebug>

extern xEditor *editor;


xSelection::xSelection()
{ }

////////// get pressed key and take actions (only on focused item)
void xSelection::move(QString direction) {

    if (direction == "north") {
        if (y()-32 >= 0) { setPos(x(), y()-32); }
    }

    else if (direction == "south") {
        if (y()+32 < 384) { setPos(x(), y()+32); }
    }

    else if (direction == "west") {
        if (x()-32 >= 0) { setPos(x()-32, y()); }
    }

    else if (direction == "east") {
        if (x()+32 < 384) { setPos(x()+32, y()); }
    }

}
