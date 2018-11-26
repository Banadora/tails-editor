#include "enemyview.h"
#include "editor.h"

#include <QDebug>


extern xEditor *editor;


xEnemyView::xEnemyView()
{ }

xEnemyView::xEnemyView(QObject *parent, QString viewName) :
    name(viewName),
    p(parent)
{
    setPixmap(QPixmap(":/img/enemies/" + viewName));
}

QObject* xEnemyView::getParent()
{
    return p;
}

QString xEnemyView::getViewName() { return name; }

int xEnemyView::getHP() { return hp; }
void xEnemyView::setHP(int nHP) { hp = nHP; }

QString xEnemyView::getWeapon() { return weapon; }
void xEnemyView::setWeapon(QString nWeapon) { weapon = nWeapon; }

