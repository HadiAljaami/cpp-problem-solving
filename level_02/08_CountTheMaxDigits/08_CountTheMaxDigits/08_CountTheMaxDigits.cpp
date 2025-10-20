// 08_CountTheMaxDigits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int ReadPositiveNumber(string message, int & num) {
    
    do {
        cout << message << endl;
        cin >> num;
    } while (num <= 0);

    return num;
}

int CountDigitFrequency(int Number, short Number2)
{
    int Count = 0;
    int Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        if (Number2==Remainder)
            Count++;
    }

    return Count;
}

int MaxOfDigits(int Number)
{
    int  Remainder = 0;
     int Max=0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        if (Remainder > Max)
            Max = Remainder;
    }

    return Max;
}



int main()
{
    int Num;
    int Max = MaxOfDigits(ReadPositiveNumber("Please enter Positev Number",Num));
    cout << "The Max Digts is " << Max << endl;
  cout << "The count of digits is "<<  CountDigitFrequency(Num,Max);
  
   
}
