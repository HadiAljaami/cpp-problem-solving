#include <iostream>
#include<string>
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
    string Temp;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;

        Temp += to_string( Remainder);


    }
    Remainder = stoi(Temp);

    return Remainder;
}
int main()
{
    cout << "The sum of digits = " <<
        SumOfDigits(ReadPositiveNumber("Please enter Positev Number"));
}