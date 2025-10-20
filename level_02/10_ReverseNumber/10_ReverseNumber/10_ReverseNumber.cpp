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

int ReverseNumber(int Number)
{
    int  Remainder = 0;
    int Number2 = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;

        Number2 = Number2 * 10 + Remainder;

    }
    return   Number2;
}
void PrintDigits(int Number)
{
    int  Remainder = 0;
    
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;

       cout << Remainder <<endl;
    }

}
int main()
{
    int Number = ReverseNumber(ReadPositiveNumber("Please enter a positive number?"));
    PrintDigits(Number);
}