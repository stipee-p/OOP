#include <iostream>

int main()
{
	int a{}, b{};
	std::cout << "Unesite 2 broja: " << '\n';
	std::cin >> a >> b;
	int zbroj {a+b};
	double arit{zbroj / 2.0};
	bool usp{ a < b };
	std::cout << "Zbroj: " << a + b << '\n';
	std::cout << "Aritmeticka sredina: " << arit << '\n';
	std::cout << "Usporedba: " << std::boolalpha << usp << '\n';
}
