#include <iostream>

template<typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T))
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(cmp(arr[j],arr[j+1]))
            {
               T a = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = a; 
            }
        }
    }
}

template <typename T>
inline bool ascending (T a, T b)
{
    return a > b;
}

template <typename T>
inline bool descending (T a, T b)
{
    return a < b;
}

int main()
{
    int n[] = {3,2,7,5,1,4};
    int num = sizeof(n) / sizeof(n[0]);

    double m[] = {3.5,2.1,5.7,1.5,1.1};
    int mum = sizeof(m) / sizeof(m[0]);

    char s[] = {'a','z','l','b','d'};
    int sum = sizeof(s) / sizeof(s[0]);

    my_sort(n,num,ascending);
    std::cout << "Ascending niz: " << '\n';
    for(int i = 0; i < num; i++)
    {
        std::cout << n[i] << " ";
    }
    std::cout << '\n';
    my_sort(n,num,descending);
    std::cout << "Descending niz: " << '\n';
    for(int i = 0; i < num; i++)
    {
        std::cout << n[i] << " ";
    }
    std::cout << '\n';

    my_sort(m,mum,ascending);
    std::cout << "Ascending niz(double): " << '\n';
    for(int i = 0; i < mum; i++)
    {
        std::cout << m[i] << " ";
    }
    std::cout << '\n';
    my_sort(m,mum,descending);
    std::cout << "Descending niz(double): " << '\n';
    for(int i = 0; i < mum; i++)
    {
        std::cout << m[i] << " ";
    }
    std::cout << '\n';


    my_sort(s,sum,ascending);
    std::cout << "Ascending niz(char): " << '\n';
    for(int i = 0; i < sum; i++)
    {
        std::cout << s[i] << " ";
    }
    std::cout << '\n';
    my_sort(s,sum,descending);
    std::cout << "Descending niz(char): " << '\n';
    for(int i = 0; i < sum; i++)
    {
        std::cout << s[i] << " ";
    }
    std::cout << '\n';

}
