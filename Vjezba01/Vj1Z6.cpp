#include <iostream>

struct Fraction
{
    int numerator, denominator;

    void reduce()
    {
        int nzd = 0, a = numerator, b = denominator;
        while(a % b != 0)
        {
            nzd = a%b;
            a = b;
            b = nzd;
        }
        numerator = numerator / b;
        denominator = denominator / b;
    }

    double value()
    {
        return double(numerator)/denominator;
    }

    void print()
    {
        std::cout << numerator << "/" << denominator << '\n';
    }

};

Fraction sum(const Fraction& a, const Fraction& b) 
{
    Fraction z {((a.numerator * b.denominator)+(b.numerator*a.denominator)),(a.denominator * b.denominator)} ;
    z.reduce();
    return z;
}

int main()
{
    Fraction r{4,2};
    Fraction r1{6,8};
    Fraction r3{3,4};
    std::cout << r.value() << '\n';
    r.print();
    r.reduce();
    r.print();

    Fraction rez = sum(r1,r3);
    rez.print();
}
