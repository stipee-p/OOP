#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>

class Enemy {
    // data memberi
    std::string ime;

public:
    // konstruktor (deklaracija; definicija je u Enemy.cpp)
    Enemy(const std::string& ime);
};
