#ifndef MAP_H
#define MAP_H

#include "block.h"

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class xMap {

    QString name;
    int level;
    //QList<xBlock> blocksList;

    QJsonDocument doc;
    QJsonObject rootObj;
    QJsonObject blockObj;
    QJsonArray blockArray;

public:
    xMap();

    void setBlock(xBlock &block);
    void saveJson(QString nName);
};

#endif // MAP_H
