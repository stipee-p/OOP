#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <vector>
#include "Enemy.h"
#include "Weapon.h"

class Level {
    // data memberi
    std::vector<Enemy> neprijatelji;
    std::vector<Weapon> oruzja;

public:
    // konstruktor
    Level(const Enemy& e);
    int enemy_count() const;
    int weapon_count() const;
};
