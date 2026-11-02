#include <iostream>
#include <vector>

void input_vector(std::vector<int>& v)
{
    int x;
    while(std::cin >> x && x != 0)
    {
        v.push_back(x);
    }
}

void print_vector(const std::vector<int>& v)
{
    for(const auto& x : v)
    {
        std::cout << x << " ";
    }
}

int main()
{
    std::vector<int> v;
    std::cout << "Unesite brojeve: " << '\n';
    input_vector(v);

    std::cout << "Vektor: " << '\n';
    print_vector(v);

    std::cout << '\n';

    std::cout << "Obrnuto: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it)
        std::cout << *it << " ";
    std::cout << '\n';

    std::vector<int> a;
    for (int i = 1; i < 21; ++i)
    {
        a.push_back(i);
        std::cout << a.size() << "/" << a.capacity() << " ";
    }

    std::cout << '\n';

    std::vector<int> b;
    std::cout << "S reserve(100):\n";

    b.reserve(100);
    for (int i = 1; i <= 20; ++i) {
        b.push_back(i);
    std::cout << "size=" << b.size() << " capacity=" << b.capacity() << '\n';
    }
    b.shrink_to_fit();
    std::cout << "Nakon shrink_to_fit: capacity= " << b.capacity() << '\n';

}
