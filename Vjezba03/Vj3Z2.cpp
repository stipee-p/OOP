#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cout << "Unesite broj dana: " << '\n';
    std::cin >> n;
    std::cout << "Unesite temperature za dane: " << '\n';

    std::vector<double> v(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }

    std::vector<double> v1;
    v1.reserve(n-1);

    for(auto it = v.begin() + 1; it != v.end(); ++it)
    {
        v1.push_back(*it - *(it-1));
    }

    std::cout << "Broj dana: " << n << '\n';
    std::cout << "Temperature: ";
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\nPromjene: " << '\n';
    for(auto it = v1.begin(); it != v1.end(); ++it)
    {
        std::cout << *it << " ";
    }
       
    v.resize(7,v.back());
    
    std::cout << "\nIzvjestaj: ";
    
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::vector<int> a(5);
    std::vector<int> b{5};

    std::cout << "Vektor a: " << a.size() << '\n';
    std::cout << "Vektor b: " << b.size() << '\n';
}
