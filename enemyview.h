#ifndef ENEMYVIEW_H
#define ENEMYVIEW_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>


class xEnemyView : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    QString name;
    QObject *p; //parent object

    int hp;
    int dmg;

public:
    xEnemyView();
    xEnemyView(QObject *parent=nullptr, QString viewName="");

    QObject* getParent();

    QString getViewName();
    void setViewName(QString nName);

    void setHP(int nHP);
    int getHP();

    void setDmg(int nDmg);
    int getDmg();
};

#endif // ENEMYVIEW_H
