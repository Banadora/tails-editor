#include "map.h"

#include <QDebug>


xMap::xMap()
{ }

void xMap::setBlock(xBlock &block) {

    blockObj["name"]=block.getName();
    blockObj["xpos"]=block.pos().x();
    blockObj["ypos"]=block.pos().y();
    blockObj["obstacle"]=block.getIsObstacle();

    blockArray << blockObj;
}

void xMap::saveJson() {
    rootObj.insert("blocks", blockArray);
    doc.setObject(rootObj);

    QFile file("jtest.json");
    if ( file.open(QIODevice::NewOnly) ) {
        qDebug() << "~~~~ Writing to file ~~~~";
        file.write(doc.toJson());
    }
}
