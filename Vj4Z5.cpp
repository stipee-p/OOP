#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

struct Student
{
    std::string jmbag;
    std::string surname;
    int points;
};



int main()
{
    std::vector<Student> registered{
    {"0302", "Kovac", 78}, {"0117", "Babic", 45},
    {"0255", "Maric", 91}, {"0117", "Babic", 45},
    {"0410", "Novak", 78}, {"0089", "Juric", 62},
    {"0255", "Maric", 91}, {"0520", "Maric", 55},
    {"0333", "Peric", 30}}; 

    std::sort(registered.begin(),registered.end(), [](const Student& a,const Student& b){return a.jmbag < b.jmbag;});

    registered.erase(std::unique(registered.begin(), registered.end(), [](const Student& a, const Student& b){return a.jmbag == b.jmbag;}),registered.end());

    std::cout << "prijavljenih: " << registered.size() << "\n";

    int p;
    std::cout << "Prag: ";
    std::cin >> p;

    registered.erase(std::remove_if(registered.begin(),registered.end(),[p](const Student& s){return s.points < p;}), registered.end());

    std::sort(registered.begin(),registered.end(),[](const Student& a, const Student& b)
    {
        if(a.points != b.points)
            return a.points > b.points;
        return a.surname < b.surname;
    });

    int r = 1;
    for(const auto& x : registered)
    {
        std::cout << r << ". " << x.surname << " (" << x.jmbag << ") " << x.points << "\n";
        r++;
    }
}