#include <iostream>
#include <cstdlib>

int& find_max(int arr[], int n)
{
    int max_i{0};
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[max_i])
        {
            max_i = i;
        }
    }
    return arr[max_i];
}


int main()
{
    int numbers[] = {4,-7, 12, 0, 9,-3};
    const int n{6};
    
    for(int c : numbers)
    {
            std::cout << c << " "; 
    }
    std::cout << '\n';

    for (int& c : numbers)
    {
        if (c < 0)
        {
            c = std::abs(c);
        }
    }

    for(int c : numbers)
    {
            std::cout << c << " ";
    }
    std::cout << '\n';

    find_max(numbers, n) = 0;

    for(int c : numbers)
    {
            std::cout << c << " ";
    }
    std::cout << '\n';
}
