#include "block.h"
#include "editor.h"


extern xEditor *editor;

////////// init
xBlock::xBlock(QString blockName, bool isObs) :
    name(blockName),
    isObstacle(isObs)
{
    setPixmap(QPixmap(":/img/" + name));
}

QString xBlock::getName() { return name; }

bool xBlock::getIsObstacle() { return isObstacle; }




