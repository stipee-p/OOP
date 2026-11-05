// Vjezba 5: klasa Clip ne radi ispravno.
// Ispravite je tako da program ispise: Concrete (Shame): 180 s

#include <iostream>
#include <string>

class Clip {
    //ispisalo je netočan rezultat jer je pravilo po redu
    //, a u našem slučaju length je bio prvi. U tom trenutku u start i end je bilo smeće
    //pa je iz tog razloga izbacivalo netočan odgovor.
    int start;
    int end;
    int length;
    std::string name;
    const int max_length = 600;
public:
    Clip(const std::string& name, int s, int e)
        : start(s), end(e), length(end - start)
    {
        //max_length ne možemo mijenjati ovdje jer je to constant varijabla
        //bez ovog this, misli se na parametar name iz konstruktora
        this->name = name;
    }
    void print() const {
        std::cout << name << ": " << length << " s\n";
    }
};

int main()
{
    Clip c("Concrete (Shame)", 10, 190);
    c.print();
    return 0;
}