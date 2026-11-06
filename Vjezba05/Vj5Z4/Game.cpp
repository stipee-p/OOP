#include <iostream>
#include "Game.h"

// definicije konstruktora i metode print
Game::Game(const std::string& title, const std::string& player_name)
: tlt(title), lvl(Enemy("Zlocko")),ply(player_name, lvl){};

void Game::print() const
{
    std::cout << tlt << "\n";
    ply.print();
}
