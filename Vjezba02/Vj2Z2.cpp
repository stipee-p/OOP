#include <iostream>

void my_sort(int arr[], int n, bool (*cmp)(int, int))
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(cmp(arr[j],arr[j+1]))
            {
               int a = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = a; 
            }
        }
    }
}

inline bool ascending (int a, int b)
{
    return a > b;
}

inline bool descending (int a, int b)
{
    return a < b;
}

int main()
{
    int n[] = {3,2,7,5,1,4};
    int num = sizeof(n) / sizeof(n[0]);

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

}
