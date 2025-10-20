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

int CountDigitFrequency( int Number)
{
    int Frequency = 0;
    int Remainder = 0;
    int Temp = 0;
    int DigitToCheck = 0;
    bool n = 1;
        while (Number>0)
        {
            while (Number > 0)
            {

                Remainder = Number % 10;
                Number /= 10;

                if (n)
                {
                    DigitToCheck = Remainder;
                    Temp = Number;
                    n = 0;
                }

                if (DigitToCheck == Remainder)
                    Frequency++;
            }

            cout << "\nDigit " << DigitToCheck << " Frequency is " << Frequency << " Time(s).\n";
            Number = Temp;
            n = 1;
            Frequency = 0;
        } 
  

    return Frequency;
}

int main()
{
    CountDigitFrequency(ReadPositiveNumber("Please enter the main number?"));
  
    return 0;
}

