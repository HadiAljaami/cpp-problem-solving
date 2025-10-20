#include <iostream>
using namespace std;
int ReadPositiveNumber(string message) {
    int num;
    do {
        cout << message << endl;
        cin >> num;
    } while (num <= 0);

    return num;
}
int SumOfDigits(int Number)
{
    int  Remainder = 0;
    int Sum = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;

        Sum += Remainder;
    }
   return Sum;
}
int main()
{
   cout << "The sum of digits = "<< 
       SumOfDigits(ReadPositiveNumber("Please enter Positev Number"));
}