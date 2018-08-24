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
        if (y()-PixelsY >= 0) { setPos(x(), y()-PixelsY); }
    }

    else if (direction == "south") {
        if (y()+PixelsY < nbBlocksY*PixelsY) { setPos(x(), y()+PixelsY); }
    }

    else if (direction == "west") {
        if (x()-PixelsX >= 0) { setPos(x()-PixelsX, y()); }
    }

    else if (direction == "east") {
        if (x()+PixelsX < nbBlocksX*PixelsX) { setPos(x()+PixelsX, y()); }
    }

}
