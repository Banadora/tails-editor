#include "enemyview.h"
#include "block.h"
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

