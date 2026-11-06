#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>
#include "Level.h"

class Player {
    // data memberi
    std::string ime;
    Level& lvl;

public:
    // konstruktor
    Player(const std::string& n,Level& l);
    void print() const;      // ime i stanje levela u kojem je igrac
};
