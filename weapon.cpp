#include "weapon.h"


xWeapon::xWeapon() { }

int xWeapon::getDmg(QString name) {
    if (name == "none") { dmg = 0; }
    else if (name == "staff") { dmg = STAFF_DMG; }
    else if (name == "claws") { dmg = CLAWS_DMG; }
    else { dmg = 0; }

    return dmg;
}
