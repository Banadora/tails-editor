#include "selection.h"
#include "editor.h"

#include <QDebug>

extern xEditor *editor;


xSelection::xSelection()
{ }

////////// get pressed key and take actions (only on focused item)
void xSelection::keyPressEvent(QKeyEvent *e) {

    //key up pressed
    if (    (e->key() == Qt::Key_Up)     ||     (e->key() == Qt::Key_Z)    ) {
        if (y()-32 >= 0) { setPos(x(), y()-32); }
    }

    //key down pressed
    else if (   (e->key() == Qt::Key_Down)     ||     (e->key() == Qt::Key_S)    ) {
        if (y()+32 < 384) { setPos(x(), y()+32); }
    }

    //key left pressed
    else if (   (e->key() == Qt::Key_Left)     ||     (e->key() == Qt::Key_Q)    ) {
        if (x()-32 >= 0) { setPos(x()-32, y()); }
    }

    //key right pressed
    else if (   (e->key() == Qt::Key_Right)     ||     (e->key() == Qt::Key_D)    ) {
        if (x()+32 < 384) { setPos(x()+32, y()); }
    }


    else if (e->key() == Qt::Key_Space) {  }
}
