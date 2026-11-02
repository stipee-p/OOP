#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<std::string> split_words(const std::string& s)
{
    std::vector<std::string> r;
    std::istringstream iss(s);
    std::string w;
    while (iss >> w)
        r.push_back(w);
    return r;
}

int main()
{
    std::vector<std::string> rjecnik{"programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije", "jednostavan", "za", "pocetnike"};

    std::sort(rjecnik.begin(), rjecnik.end());

    std::string rec;
    std::cout << "Recenica: ";
    std::getline(std::cin, rec);

    std::vector<std::string> rijeci = split_words(rec);
    std::vector<std::string> nepoznate;

    for (auto& r : rijeci)
    {
        r.erase(std::remove_if(r.begin(), r.end(), [](unsigned char c) {
            return c == ',' || c == '.';
        }), r.end());

        for (char& c : r)
            c = std::tolower(static_cast<unsigned char>(c));

        if (!std::binary_search(rjecnik.begin(), rjecnik.end(), r))
            nepoznate.push_back(r);
    }

    std::cout << "nepoznatih rijeci: " << nepoznate.size();
    for (const auto& r : nepoznate)
        std::cout << " " << r;
    std::cout << "\n";

    return 0;
}
