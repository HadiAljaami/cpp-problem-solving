// 47_A_Round.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

float GetFractionPart(float Number)
{
    return Number - int(Number);
}
int MyFloor(float Number)
{
    int IntPart;
    IntPart = int(Number);

    if (IntPart<0)
    {
        if(GetFractionPart(Number)==0)
         return IntPart;

        return  --IntPart;
    }
    else
    {
        return IntPart;
    }

}
float  ReadNumber()
{
    float Number;
    cout << "Please enter a float number?";

    cin >> Number;
    return Number;
}
int main()
{
    float Number = ReadNumber();
    cout << "My Floor Result : " << MyFloor(Number) << endl;
    cout << "C++ Floor Result: " << floor(Number) << endl;

    return 0;
}
