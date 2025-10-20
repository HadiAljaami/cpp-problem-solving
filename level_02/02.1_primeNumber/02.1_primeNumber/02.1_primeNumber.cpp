#include <iostream>
using namespace std;
enum enPrime { Prime = 1, NotPrime = 2 };
int ReadNumber(string message)
{
    int n = 0;
    do
    {
        cout << message ;cin >> n;
    }

    while (n <= 0);
    return n;
}

enPrime CheckPrimeNumber(int N)
{
    int m = round(N / 2);
    for (int counter = 2;counter <= m;counter++)
    {
        if (N % counter == 0)
            return enPrime::NotPrime;
    }
    return enPrime::Prime;
}

void PrintPrimeNumber(int n)
{
    for (int i = 1;i <= n;i++)
    {
        if (CheckPrimeNumber(i) == enPrime::Prime)
            cout << i << endl;;
    }

}

int main()
{
    PrintPrimeNumber(ReadNumber("enter a positive number ? "));
   

}