#include <iostream>
#define MAX(a, b) (a) > (b) ? (a) : (b)

inline int my_max(int a, int b)
{
    return a > b ? a : b;
}

template<typename T>
T my_max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
	int a = MAX(3, 5);
	int b = 2 * (MAX(3, 5));
	int c = MAX(3, 5) + 1;
    int i = 3;
    int k = MAX(++i, 2);

    std::cout << "Template funkcija za int: " << my_max(3,2) << '\n';
    std::cout << "Template funkcija za double: " << my_max(3.5,4.6) << '\n';
    std::cout << "Template funkcija za char: " << my_max('k','a') << '\n';
    std::cout << "Template funkcija za std string: " << my_max((std::string("vata")),(std::string("vrara"))) << '\n';
	std::cout << "Rezultati: " << '\n' << a << " " << b << " " << c << '\n';
    std::cout << "Rezultat bez inline: (prvi) " << k << '\n';
    std::cout << "Vrijednost i(prvi): " << i << '\n';
    i = 3;
    std::cout << "Rezultat inline: " << my_max(++i, 2) << '\n';
    std::cout << "Vrijednost i(inline): " << i << '\n';
}
