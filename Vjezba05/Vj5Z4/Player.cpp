#include <iostream>
#include "Player.h"

// definicije konstruktora i metode print
Player::Player(const std::string& n, Level& l) : ime(n), lvl(l){};

void Player::print() const
{
    std::cout << "Igrac: " << ime << "\n";
    std::cout << "Level: neprijatelja " << lvl.enemy_count() << ", oruzja " << lvl.weapon_count() << "\n";
}
