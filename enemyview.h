#ifndef ENEMYVIEW_H
#define ENEMYVIEW_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>


class xEnemyView : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    QString name;
    QObject *p; //parent object

    int hp;
    QString weapon;

public:
    xEnemyView();
    xEnemyView(QObject *parent=nullptr, QString viewName="");

    QObject* getParent();

    QString getViewName();

    int getHP();
    void setHP(int nHP);

    QString getWeapon();
    void setWeapon(QString nWeapon);
};

#endif // ENEMYVIEW_H
