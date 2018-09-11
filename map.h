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
    QJsonArray blocksArray;

public:
    xMap();

    void setName(QString nName);
    void setBlock(xBlock &block);
    void saveJson(QString nName);
    void loadJson(QString nName);
};

#endif // MAP_H
