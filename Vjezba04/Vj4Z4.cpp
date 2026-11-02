#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

struct PasswordInfo
{
    int length = 0, digits = 0, uppercase = 0, special = 0;
};


PasswordInfo analyze(const std::string& password) 
{
    PasswordInfo info;
    info.length = password.size();
    info.digits = std::count_if(password.begin(),password.end(),[](unsigned char ch){return std::isdigit(ch);});
    info.uppercase = std::count_if(password.begin(),password.end(),[](unsigned char ch){return std::isupper(ch);});
    info.special = std::count_if(password.begin(),password.end(),[](unsigned char ch){return std::ispunct(ch);});
    
    return info;
}

bool is_strong(const PasswordInfo& info)
{
    return info.length > 9 && info.digits > 0 && info.uppercase > 0 && info.special > 0;
}

void ispis(const std::string& loz, const PasswordInfo& in)
{
    std::cout << loz << ": duljina " << in.length << ", znamenke " << in.digits << ", velika " << in.uppercase << ", posebni " << in.special; 
    if(is_strong(in))
        std::cout << " -> jaka\n";
    else
        std::cout << " -> slaba\n";
    
}

int main()
{
    std::string l1 {"lozinka123"};
    std::string l2 {"Lozinka123!"};

    PasswordInfo r1 = analyze(l1);
    PasswordInfo r2 = analyze(l2);

    ispis(l1,r1);
    ispis(l2,r2);

}
