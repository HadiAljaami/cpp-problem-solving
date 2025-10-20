#include <iostream>
using namespace std;
int ReadNumber()
{
    int num;
    cout << "Enter a Number: "; cin >> num;
    return num;
}

int sumNumbers()
{
    int TotalSum = 0; int n = 0;
    while (true)
    {
        n = ReadNumber();
        if (n == -99)
        return TotalSum;
        TotalSum += n;
    } 
}
void printTotalSum(int TotalSum)
{
    cout << " The Total "<< TotalSum << endl;
}
int main()
{
    printTotalSum(sumNumbers());
}