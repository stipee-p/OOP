#include "Level.h"

// definicije konstruktora i metoda
Level::Level(const Enemy& e) : neprijatelji{e} {};

int Level::enemy_count() const
{
    return neprijatelji.size();
}

int Level::weapon_count() const
{
    return oruzja.size();
}
