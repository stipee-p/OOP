#include <iostream>
#include <vector>
#include <algorithm>

void input_vector(std::vector<int>& v)
{
    int x;
    while(std::cin >> x && x != 0)
    {
        v.push_back(x);
    }
}

int main()
{
    int k;
    std::vector<int> v;
    std::cout << "Unesite brojeve (0 za kraj): \n";
    input_vector(v);

    std::cout << "k(> 0): ";
    std::cin >> k;

    while(k < 1)
    {
        std::cout << "k treba biti veći od 0!\n" << "Unesite ponovno: ";
        std::cin >> k;
    }

    auto negativan = [](int x) {return x < 0;};
    auto visekratnik = [k](int x) {return x % k == 0;};
    auto najveci = std::max_element(v.begin(), v.end());
    auto najmanji = std::min_element(v.begin(), v.end());

    auto neg = std::count_if(v.begin(),v.end(),negativan);
    std::cout << "negativnih: " << neg << "\n";

    auto vise = std::find_if(v.begin(),v.end(),visekratnik);
    if(vise != v.end())
    {
        std::cout << "prvi visekratnik od " << k << ": " << *vise << " (pozicija " << vise - v.begin() << ")\n";
    }
    else
    {
       std::cout << "Nema visekratnika.\n"; 
    }
    
    if(v.empty())
    {
        std::cout << "Vektor je prazan.\n";
    }
    else
    {
        std::cout << "min " << *najmanji << " (pozicija " << najmanji - v.begin() << "), max " << *najveci << " (pozicija " << najveci - v.begin() << ")\n";

    }

    v.erase(std::remove_if(v.begin(),v.end(),visekratnik),v.end());
    
    std::cout << "bez visekratnika: ";
    for(const auto& x : v)
    {
        std::cout << x << " ";
    }
    

}
