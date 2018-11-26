#ifndef WEAPON_H
#define WEAPON_H

//damage done by weapons
#define STAFF_DMG 55
#define CLAWS_DMG 5

#include <QString>


class xWeapon {

    int dmg;

public:
    xWeapon();

    int getDmg(QString name);
};

#endif // WEAPON_H
