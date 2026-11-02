#include <iostream>
#include <string>

bool split_email(const std::string& email, std::string& user, std::string& domain)
{
    auto poz = email.find('@');
    auto zad = email.rfind('@');

    if (poz == std::string::npos)
    {
        return false;
    }
    else if (poz != zad)
    {
        return false;
    }
    else if ((poz == 0) || (poz == email.size() - 1))
    {
        return false;
    }

    std::string d_domena = email.substr(poz + 1);

    if (d_domena.find('.') == std::string::npos)
    {
        return false;
    }

    user = email.substr(0, poz);
    domain = d_domena;
    return true;
}

int main()
{
    std::string email, user, domain;

    std::cout << "Unesite e-mail adresu: " << '\n';
    std::getline(std::cin, email);

    if (split_email(email, user, domain))
    {
        std::cout << "Korisnik: " << user << ", Domena: " << domain << "\n";
    }
    else
    {
        std::cout << "Neispravna adresa\n";
    }
}
