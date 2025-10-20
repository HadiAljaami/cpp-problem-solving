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

int CountDigitFrequency(short DigitToCheck, int Number)
{
    int Frequency = 0;
    int Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        if (DigitToCheck == Remainder)
            Frequency++;
    }

    return Frequency;
}

int main()
{
    int Number = ReadPositiveNumber("Please enter the main number?");
    short DigitToCheck = ReadPositiveNumber("Please enter one digit to check?");

    cout << "\nDigit " << DigitToCheck << " Frequency is " << CountDigitFrequency(DigitToCheck, Number) 
        << " Time(s).\n"; 
    return 0;
}

