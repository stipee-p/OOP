#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>
#include "Level.h"
#include "Player.h"

class Game {
    // data memberi
    std::string tlt;
    Level lvl;
    Player ply;

public:
    Game(const std::string& title, const std::string& player_name);
    void print() const;      // naziv igre, zatim stanje igraca
};
