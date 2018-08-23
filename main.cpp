#include "mainwindow.h"
#include "eventfilter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    xMainWindow w;
    w.show();

    xEventFilter *filter = new xEventFilter(&a, &w);
    a.installEventFilter(filter);

    return a.exec();
}
