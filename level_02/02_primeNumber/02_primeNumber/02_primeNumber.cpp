#include <iostream>
using namespace std;
enum enPrime { Prime = 1, NotPrime = 2 };
void ReadNumber(int& n)
{
    do
    {
        cout << "Enter a number : ";cin >> n;
    }

    while (n <= 0);
}

enPrime Prime_(int N)
{
    int Counter = 2;
    int m = N / 2;
    m = round(m);
    if (N <= Counter)
        return enPrime::Prime;
    else
    {
        while (true)
        {
            if (N % Counter == 0)
                return enPrime::NotPrime;

            if (Counter == m)
                return enPrime::Prime;
            Counter++;
        }
    }


}

void PrintPrimeNumber(int n)
{
    for (int i = 1;i <= n;i++)
    {
        if (Prime_(i) == enPrime::Prime)
            cout << i << " ";
    }
   
}

int main()        
{
    int n = 0;
    ReadNumber(n);
    PrintPrimeNumber(n);
    
}