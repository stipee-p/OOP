#include <iostream>
#include <string>

int main()
{
    const int g{2026};
    int god {};
    std::string i_p{};
    std::cout << "Unesite godinu rodenja: " << '\n';
    std::cin >> god;
    std::cin.ignore();
    std::cout << "Unesite ime i prezime: " << '\n';
    std::getline(std::cin, i_p);
    
    std::cout << god << '\n' << i_p << '\n';
    char pr{i_p[0]};
    std::size_t raz{i_p.find(' ')};
    char dr{i_p[raz + 1]};

    int broj {0};
    for(char c : i_p)
    {
        if(c != ' ')
        {
            broj = broj + 1;
        }
    }

    std::cout << "Inicijali: " << pr << "." << dr << "." << '\n';
    std::cout << "Broj znakova: " << broj << '\n';
    std::cout << "Godine: " << g-god << '\n';

}
