#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool starts_with(const std::string& s, const std::string& prefix)
{
   if(s.size() < prefix.size())
   {
        return false;
   }

   return std::equal(prefix.begin(),prefix.end(),s.begin());
}

bool ends_with(const std::string& s, const std::string& suffix)
{
    if(s.size() < suffix.size())
    {
        return false;
    }

    return std::equal(suffix.rbegin(),suffix.rend(),s.rbegin());
}


int main()
{
    std::vector<std::string> v{"vjezba04.cpp", "slajdovi.pdf", "main.cpp", "README.md", "vjezba04.h", "notes.txt", "vjezba03.cpp"};

    int cnt = 0;
    for(const auto& x : v)
    {
        if(ends_with(x,".cpp"))
        {
            cnt++;
        }
    }

    std::cout << ".cpp datoteka: " << cnt << "\n";

    v.erase(std::remove_if(v.begin(),v.end(),[](const std::string& ime){return starts_with(ime, "vjezba");}),v.end());

    for(const auto& x : v)
    {
        std::cout << x << " ";
    }

}