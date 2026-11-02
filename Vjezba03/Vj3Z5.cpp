#include <iostream>
#include <string>

std::string with_separators(std::string digits)
{
    std::size_t start = (!digits.empty() && digits[0] == '-') ? 1 : 0;

    for (std::size_t pos = digits.size(); pos > start + 3; )
    {
        pos -= 3;
        digits.insert(pos, ".");
    }
    return digits;
}

std::string without_separators(std::string text)
{
    auto poz = text.find('.');

    while (poz != std::string::npos)
    {
        text.erase(poz, 1);
        poz = text.find('.', poz);
    }
    return text;
}

int main()
{
    std::string broj;

    std::cout << "Unesite broj: " << '\n';
    std::getline(std::cin, broj);

    std::string s = with_separators(broj);
    std::cout << "S točkama: " << s << "\n";
    std::cout << "Bez točaka: " << without_separators(s) << "\n";
}
