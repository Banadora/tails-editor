#include "map.h"
#include "editor.h"

#include <QDebug>


extern xEditor *editor;

xMap::xMap()
{ }

void xMap::setName(QString nName) { name = nName; }

void xMap::setBlock(xBlock &block) {

    blockObj["name"] = block.getName();
    blockObj["xpos"] = block.pos().x();
    blockObj["ypos"] = block.pos().y();
    blockObj["obstacle"] = block.getIsObstacle();

    blocksArray << blockObj;
}

void xMap::setEnemy(xEnemyView &enemy)
{
    enemyObj["name"] = enemy.getViewName();
    enemyObj["xpos"] = enemy.pos().x();
    enemyObj["ypos"] = enemy.pos().y();
    enemyObj["hp"] = enemy.getHP();
    enemyObj["weapon"] = enemy.getWeapon();

    enemyArray << enemyObj;
}

void xMap::clearArrays()
{
    while(blocksArray.count()) { blocksArray.pop_back(); }
    while(enemyArray.count()) { enemyArray.pop_back(); }
}

void xMap::saveJson(QString nName, QString north, QString east, QString south, QString west) {
    rootObj.insert("blocks", blocksArray);
    rootObj.insert("enemies", enemyArray);
    rootObj.insert("name", nName);
    rootObj.insert("mapNorth", north);
    rootObj.insert("mapEast", east);
    rootObj.insert("mapSouth", south);
    rootObj.insert("mapWest", west);
    doc.setObject(rootObj);

    QFile file(nName + ".json");
    if ( file.open(QIODevice::NewOnly) ) {
        qDebug() << "~~~~ Writing to file ~~~~";
        file.write(doc.toJson());
    }
}

void xMap::loadJson(QString nName) {    
    //open file and convert to byteArray
    QFile file(nName + ".json");
    if(!file.open(QIODevice::ReadOnly)) { qDebug() << "Failed to open " << nName + ".json"; exit(1); }
    QTextStream file_text(&file);
    QString fullJsonString;
    fullJsonString = file_text.readAll();
    file.close();
    QByteArray json_bytes = fullJsonString.toLocal8Bit();

    //convert to jdoc
    auto json_doc=QJsonDocument::fromJson(json_bytes);
    if(json_doc.isNull()) { qDebug() << "Failed to find JSON doc."; exit(2); }
    if(!json_doc.isObject()){ qDebug() << "JSON is not an object."; exit(3); }
    rootObj = json_doc.object();
    if(rootObj.isEmpty()){ qDebug() << "JSON object is empty."; exit(4); }

    //rootMap = root json object
    QVariantMap rootMap = rootObj.toVariantMap();

    // BLOCKS BLOCKS BLOCKS BLOCKS BLOCKS BLOCKS BLOCKS BLOCKS BLOCKS BLOCKS BLOCKS BLOCKS BLOCKS BLOCKS BLOCKS BLOCKS
    //blocksArray is an array of objects and is located directly in root, it's erased before use
    while(blocksArray.count()) { blocksArray.pop_back(); }
    blocksArray = rootObj["blocks"].toArray();

    //jBlock is an object inside the blockArray
    QJsonObject jBlock;
    QVariantMap jBlockMap;
    for (int i = 0, n = blocksArray.size(); i < n; i++) {
        jBlock = blocksArray[i].toObject();
        jBlockMap = jBlock.toVariantMap();
        editor->selection->setPos(jBlockMap["xpos"].toInt(), jBlockMap["ypos"].toInt());
        editor->placeBlock(jBlockMap["name"].toString(), jBlockMap["obstacle"].toBool());
    }

    // ENEMIES ENEMIES ENEMIES ENEMIES ENEMIES ENEMIES ENEMIES ENEMIES ENEMIES ENEMIES ENEMIES ENEMIES ENEMIES ENEMIES ENEMIES ENEMIES
    //enemyArray is an array of objects and is located directly in root, it's erased before use
    while(enemyArray.count()) { enemyArray.pop_back(); }
    enemyArray = rootObj["enemies"].toArray();

    QJsonObject jEnemy;
    QVariantMap jEnemyMap;
    for (int i = 0, n = enemyArray.size(); i < n; i++) {
        jEnemy = enemyArray[i].toObject();
        jEnemyMap = jEnemy.toVariantMap();
        editor->selection->setPos(jEnemyMap["xpos"].toInt(), jEnemyMap["ypos"].toInt());
        editor->placeEnemy(jEnemyMap["name"].toString(), jEnemyMap["hp"].toInt(), jEnemyMap["weapon"].toString());
    }


    name = rootMap["name"].toString();
    mapNorth = rootMap["mapNorth"].toString();
    mapEast = rootMap["mapEast"].toString();
    mapSouth = rootMap["mapSouth"].toString();
    mapWest = rootMap["mapWest"].toString();

    clearArrays();
    qDebug() << "~~~~ Map loaded ~~~~" << '\n' << name;
}

QString xMap::getMapNorth() { return mapNorth; }
QString xMap::getMapEast() { return mapEast; }
QString xMap::getMapSouth() { return mapSouth; }
QString xMap::getMapWest() { return mapWest; }
