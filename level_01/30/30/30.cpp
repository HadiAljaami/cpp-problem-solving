#include <iostream>
using namespace std;
enum enOddOrEven { odd = 1, even = 2 };
int ReadNumber()
{
    int num;
    cout << "Enter the num : ";cin >> num;
    return num;
}

bool isPositive(int n)
{
    return n >= 0;
}
int factorial(int n)
{
    while (!isPositive(n))
    {
         n = ReadNumber();
    } 
   
    int f = 1;
    if (n == 0 || n == 1)
    return 1;
    else
    {
        for (int i = n;i >= 1;i--)
        {
             f = f * i;
        }
             return f;
    }
   
}
void printFactorial(int f)
{
    cout << "the factorial is : " << f << endl;
}
int main()
{
    printFactorial(factorial(ReadNumber()));
}
