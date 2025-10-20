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

void PrintAllDigitsFrequencey(int Number)
{ 
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        short DigitFrequency = 0;    
        DigitFrequency = CountDigitFrequency(i, Number); 

        if (DigitFrequency > 0) 
        {
            cout << "Digit " << i << " Frequencey is " << DigitFrequency << " Time(s).\n"; 
        } 
    } 
}

int main()
{
    int Number = ReadPositiveNumber("Please enter the main number?");
    PrintAllDigitsFrequencey( Number);

   
    return 0;
}

