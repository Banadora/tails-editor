#ifndef MAP_H
#define MAP_H

#include "block.h"
#include "enemyview.h"

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class xMap {

    QString name;
    int level;

    QString mapNorth;
    QString mapEast;
    QString mapSouth;
    QString mapWest;

    QJsonDocument doc;
    QJsonObject rootObj;

    QJsonObject blockObj;
    QJsonArray blocksArray;

    QJsonObject enemyObj;
    QJsonArray enemyArray;

public:
    xMap();

    void setName(QString nName);

    void setBlock(xBlock &block);
    void setEnemy(xEnemyView &enemy);

    void saveJson(QString nName, QString north, QString east, QString south, QString west);
    void loadJson(QString nName);

    QString getMapNorth();
    QString getMapEast();
    QString getMapSouth();
    QString getMapWest();
};

#endif // MAP_H
