#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Song
{
    std::string title;
    std::string artist;
    int year;
    int plays;
};

void print_song(const Song& s)
{
    std::cout << s.artist << " - " << s.title << " (" << s.year << "), "<< s.plays << " slusanja\n";
}

int main()
{
    std::vector<Song> songs
    {
        {"Starman", "David Bowie", 1972, 365},
        {"Magla", "Josipa Lisac", 1988, 231},
        {"Stikla", "Severina", 2005, 2},
        {"Hey Jude", "Queen", 1984, 250},
        {"Aleluja", "Mate Bulic", 2008, 400},
        {"Gori gora", "Mate Bulic", 2006, 2000}
    };

    std::sort(songs.begin(),songs.end(),[](const Song& a, const Song& b)
    {
        if (a.year != b.year)
            return a.year < b.year;
        return a.title < b.title;
    });

    std::cout << "Sortirano po godinama: \n";
    for(const Song& s : songs)
    {
        print_song(s);
    }

    std::string izv;
    std::cout << "Unesite izvodjaca: \n";
    std::getline(std::cin, izv);

    auto by_artist = [&izv](const Song& s)
    {
        return s.artist == izv;
    };

    auto cnt = std::count_if(songs.begin(), songs.end(), by_artist);
    if(cnt == 0)
        std::cout << "Nema izvodjaca.\n";
    else
    {
        std::cout << "Broj pjesama izvodjaca: " << cnt << '\n';
        auto oldest = std::find_if(songs.begin(), songs.end(), by_artist);

        std::cout << "Najstarija: \n";
        print_song(*oldest);
    }

    auto top = std::max_element(songs.begin(), songs.end(),[](const Song& a, const Song& b)
    {
        return a.plays < b.plays;
    });

    std::cout << "\nNajslusanija: \n";
    print_song(*top);
}
