// Vjezba 5, zadatak 3: napisite strukturu Song i klasu Album iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite Song i Album

struct Song
{
    std::string title;
    std::string artist;
    int seconds = 0;
};

class Album
{   
    std::string title;
    int year = 0;
    std::vector<Song> songs;

    public:
    Album(const std::string& name, int y, Song s)
    :title(name), year(y),songs{s}{}

    bool add(const Song& s)
    {
        for(const Song& p : songs)
        {
            if(p.title == s.title)
                return false;
        }
        songs.push_back(s);
        return true;
    }

    int duration() const
    {
        int z = 0;
        for(const Song& p : songs)
        {
            z = z + p.seconds;
        }
        return z;
    }

    void print() const
    {
        int minute = duration() / 60;
        int sekunde = duration() % 60;
        std::cout << title << " (" << year << "), " << songs.size() << " pjesme, " << minute << ":" << sekunde << "\n";
        for(int i = 1; i <= songs.size(); i++)
        {
            std::cout << "  " << i << ". " << songs[i-1].title << "\n";
        }
    }
};

int main()
{
    Album a("Sol Invictus", 2015, {"Sol Invictus", "Faith No More", 156});
    a.add({"Superhero", "Faith No More", 315});
    a.add({"Matador", "Faith No More", 368});
    std::cout << a.add({"Superhero", "Faith No More", 315}) << '\n';   // vec postoji
    a.print();
    return 0;
}

/*
Ocekivani ispis:

    0
    Sol Invictus (2015), 3 pjesme, 13:59
      1. Sol Invictus
      2. Superhero
      3. Matador
*/
