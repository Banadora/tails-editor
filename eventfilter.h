#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QObject>

class xEventFilter : public QObject
{
    Q_OBJECT

public:
    explicit xEventFilter(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // EVENTFILTER_H
