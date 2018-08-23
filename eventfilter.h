#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>

class xEventFilter : public QObject
{
    Q_OBJECT

    xMainWindow *w;

public:
    explicit xEventFilter(QObject *parent = nullptr, xMainWindow *nW = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // EVENTFILTER_H
