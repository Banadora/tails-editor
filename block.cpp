#include "block.h"
#include "game.h"


extern xGame *game;

////////// init
xBlock::xBlock(QString blockName) :
    name(blockName),
    obstacle(false)
{
    setPixmap(QPixmap(":/img/" + name + ".png"));
    defineIfObstacle(name);
}

void xBlock::setName(QString nName) { name = nName;}
QString xBlock::getName() { return name; }

void xBlock::setX(int nX) { x = nX; }
void xBlock::setY(int nY) { y = nY; }

int xBlock::getX() { return x; }
int xBlock::getY() { return y; }

////////// when created, define if a certain block is an obstacle
void xBlock::defineIfObstacle(QString name) {
    if (name == "grass1") { obstacle = true; }
}

bool xBlock::isObstacle() { return obstacle; }


////////// virtual funcs
int xBlock::getDestinationLayout() const { return -1; }
int xBlock::getDestinationX() const { return -1; }
int xBlock::getDestinationY() const { return -1; }


