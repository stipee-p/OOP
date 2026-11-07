// Vjezba 5, zadatak 5: napisite klasu Ticket iznad main.

#include <iostream>
#include <string>

// ovdje napisite klasu Ticket
class Ticket
{
    std::string bend_mjesto;
    int id;
    static int next_id;

    public: 
        Ticket(const std::string& s) : bend_mjesto(s), id(next_id++){};
        int get_id() const {return id; }
        static int issued() {return next_id - 1;}
};

int Ticket::next_id = 1;

int main()
{
    std::cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");
    std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
    std::cout << Ticket::issued() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    0
    1 2 3
    3
*/