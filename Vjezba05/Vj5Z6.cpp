// Vjezba 5, zadatak 6: napisite klasu Coin iznad funkcije bonus.

#include <iostream>

// ovdje napisite klasu Coin
class Coin
{
    int value;
    static int coins;

    public:
        Coin(int v) : value(v){coins++;};
        ~Coin(){coins--;};
        static int remaining(){return coins;}
};

int Coin::coins = 0;

void bonus()               // bonus runda: tri novcica
{
    Coin c1(5);
    Coin c2(5);
    Coin c3(10);
    std::cout << Coin::remaining() << '\n';
}

int main()
{
    std::cout << Coin::remaining() << '\n';
    Coin gold(50);
    {
        Coin a(1);
        Coin b(1);
        std::cout << Coin::remaining() << '\n';
    }
    std::cout << Coin::remaining() << '\n';
    bonus();
    std::cout << Coin::remaining() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    0
    3
    1
    4
    1
*/