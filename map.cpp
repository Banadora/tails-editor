#include "map.h"
#include "editor.h"

#include <QDebug>


extern xEditor *editor;

xMap::xMap()
{ }

void xMap::setBlock(xBlock &block) {

    blockObj["name"]=block.getName();
    blockObj["xpos"]=block.pos().x();
    blockObj["ypos"]=block.pos().y();
    blockObj["obstacle"]=block.getIsObstacle();

    blocksArray << blockObj;
}

void xMap::saveJson(QString nName) {
    rootObj.insert("blocks", blocksArray);
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
    //blocksArray is an array of objects and is located directly in root, it's erased before use
    while(blocksArray.count()) {
         blocksArray.pop_back();
     }
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
    name = rootMap["name"].toString();
    qDebug() << "~~~~ Map loaded ~~~~" << '\n' << name;
}
