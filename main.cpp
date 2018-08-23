#include "mainwindow.h"
#include "eventfilter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    xEventFilter *filter = new xEventFilter(&a);
    a.installEventFilter(filter);

    xMainWindow w;
    w.show();

    return a.exec();
}
