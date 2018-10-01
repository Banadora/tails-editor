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

    void saveJson(QString nName);
    void loadJson(QString nName);
};

#endif // MAP_H
