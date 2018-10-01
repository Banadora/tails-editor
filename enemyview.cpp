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

void xEnemyView::setViewName(QString nName)
{
    name = nName;
    setPixmap(QPixmap(":/img/" + name + ".png"));
}

void xEnemyView::setHP(int nHP) { hp = nHP; }
int xEnemyView::getHP() { return hp; }

void xEnemyView::setDmg(int nDmg) { dmg= nDmg; }
int xEnemyView::getDmg() { return dmg; }

