#include <iostream>
using namespace std;
enum enPerfectNumber{perfect=1, noPerfect=2};

int ReadNumber(string message)
{
    int n = 0;
    do
    {
        cout << message;cin >> n;
    }

    while (n <= 0);
    return n;
}

enPerfectNumber CheckNumberPerfect(int N)
{
    int sum = 0;
   for (int i=1; i<=N/2;i++)
   {
       if (N % i == 0)
       {
           sum = sum + i;
       }
   }
   
   return sum == N ? enPerfectNumber::perfect : enPerfectNumber::noPerfect;
}

void PrintPerfectNumber(int N)
{
    if (CheckNumberPerfect(N) == enPerfectNumber::perfect)
    {
        cout << "The " << N << " is perfect \n";
    }

    else 
        cout << "The " << N << " is not perfect \n";

}
int main()
{
    PrintPerfectNumber(ReadNumber("Enter a Number ? "));
}