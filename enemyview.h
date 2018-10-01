#ifndef ENEMYVIEW_H
#define ENEMYVIEW_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>


class xEnemyView : public QGraphicsPixmapItem {

    QString name;
    QObject *p; //parent object

public:
    xEnemyView();
    xEnemyView(QObject *parent=nullptr, QString viewName="");

    QObject* getParent();

    QString getViewName();
    void setViewName(QString nName);
};

#endif // ENEMYVIEW_H
