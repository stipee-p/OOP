#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split_words(const std::string& text)
{
    std::vector<std::string> words;

    std::size_t start = text.find_first_not_of(' ');

    while (start != std::string::npos)
    {
        std::size_t end = text.find(' ', start);

        if (end == std::string::npos)
        {
            words.push_back(text.substr(start));
            break;
        }

        words.push_back(text.substr(start, end - start));
        start = text.find_first_not_of(' ', end);
    }
    return words;
}

int main()
{
    std::string text;

    std::cout << "Unesite rečenicu: " << '\n';
    std::getline(std::cin, text);

    std::vector<std::string> words = split_words(text);

    if (words.empty())
    {
        std::cout << "nema riječi\n";
        return 0;
    }

    std::string najdulja = words[0];
    std::string prva = words[0];

    for (const auto& w : words)
    {
        if (w.size() > najdulja.size())
        {
            najdulja = w;
        }
        if (w < prva)
        {
            prva = w;
        }
    }

    std::string obrnuto;
    for (auto it = words.rbegin(); it != words.rend(); ++it)
    {
        if (!obrnuto.empty())
        {
            obrnuto += "-";
        }
        obrnuto += *it;
    }

    std::cout << "Broj rijeci: " << words.size() << "\n";
    std::cout << "Najdulja: " << najdulja << "\n";
    std::cout << obrnuto << "\n";
    std::cout << "Prva po abecedi: " << prva << "\n";
}
