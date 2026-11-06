#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>

class Weapon {
    // data memberi
    std::string naziv;

public:
    // konstruktor (deklaracija; definicija je u Weapon.cpp)
    Weapon(const std::string& n);
};
