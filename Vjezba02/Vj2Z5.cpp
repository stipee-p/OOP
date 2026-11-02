#include <iostream>

inline double add(double a, double b) 
{ 
    return a + b; 
}

inline double subtract(double a, double b) 
{
    return a - b; 
}

inline double multiply(double a, double b) 
{ 
    return a * b; 
}

inline double divide(double a, double b) 
{ 
    return a / b; 
}

int main()
{
    double (*oper[])(double, double) = {add, subtract, multiply, divide};

    double x, y;
    int op;

    std::cout << "Unesi dva broja: ";
    std::cin >> x >> y;
    std::cout << "Izaberi operaciju: ";
    std::cin >> op;

    if (op < 0 || op > 3)
    {
        std::cout << "Nepostojeca operacija.\n";
    }
    else if (op == 3 && y == 0)
    {
        std::cout << "Dijeljenje s nulom nije moguce.\n";
    }
    else
    {
        std::cout << "Rezultat: " << oper[op](x, y) << "\n";
    }

    return 0;
}
