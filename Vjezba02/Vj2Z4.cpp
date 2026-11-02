#include <iostream>

void my_transform(int arr[], int n, int (*f)(int)) 
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = f(arr[i]);
    }
}

int twice(int a)
{
    return a * 2;
}

int main()
{
    int niz[] = {1 , 2 , 3 , 4};
    int miz[] = {1, 2, 3, 4};
    int n = sizeof(niz) / sizeof(niz[0]);
    my_transform(niz, n, twice);
    std::cout << "Novi niz: " << '\n';
    for(int i = 0; i < n; i++)
    {
         std::cout << niz[i] << " ";  
    }
    std::cout << '\n';
    my_transform(miz,n,[](int a){if (a % 2 == 0){return a / 2;}else{return a * 2;}});
    for(int i = 0; i < n; i++)
    {
         std::cout << miz[i] << " ";  
    }

    std::cout << '\n';

    int sum = 0;
    int prod = 1;
    int prag = 3;
    int s = 0;

    auto racun = [&] (int x)
    {
        sum += x;
        prod *= x;
    };

    for(int i = 0; i < n; i++)
    {
         racun(miz[i]); 
    }

    std::cout << "Suma niza: " << sum << '\n' << "Produkt niza: " << prod << '\n';

    auto sapragom = [prag, &s](int x){
        if(x > prag)
        {
            s += x;
        }
    };

    for(int i = 0; i < n; i++)
    {
         sapragom(niz[i]); 
    }

    std::cout << "Suma clanova vecih od praga: " << s << '\n';
}
