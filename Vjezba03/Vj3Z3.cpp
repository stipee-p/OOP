#include <iostream>
#include <array>

constexpr int DAYS = 7;

double total(const std::array<double, DAYS>& hours)
{
    double x = 0;
    for(auto it = hours.begin(); it != hours.end(); ++it)
    {
        x += *it;
    }
    return x;
}

int best_day(const std::array<double, DAYS>& hours)
{
    int dan = 1;
    double sat = hours[0];

    for(int i = 1; i < DAYS; i++)
    {
        if (hours[i] > sat)
        {
            dan = i + 1;
            sat = hours[i];
        }
    }
    return dan;
}

int main()
{
   std::array<double, DAYS> prvi;
   std::array<double, DAYS> drugi;
   
    drugi.fill(1.5);

   std::cout << "Unesite broj sati za svaki dan: " << '\n';
   for(int i = 0; i < DAYS; i++)
    {
        std::cin >> prvi[i];
    }
    double ukupno = total(prvi);
    int najvise = best_day(prvi);

    std::cout << "Ukupno sati ovaj tjedan: " << ukupno << '\n';
    std::cout << "Najvise u danu broj: " << najvise << '\n';

    std::cout << std::boolalpha;
    std::cout << (prvi == drugi) << '\n';
    std::cout << (prvi < drugi) << '\n';

    prvi.swap(drugi);

    ukupno = total(prvi);
    najvise = best_day(prvi);

    std::cout << "Ukupno sati ovaj tjedan(NAKON ZAMJENE): " << ukupno << '\n';
    std::cout << "Najvise u danu broj(NAKON ZAMJENE): " << najvise << '\n';
}
