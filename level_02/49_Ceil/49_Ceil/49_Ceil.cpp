#include <iostream>
using namespace std;

float GetFractionPart(float Number)
{
    return Number - int(Number);
}
int MyCeil(float Number)
{
    if (GetFractionPart(Number) > .0)
        return int(Number)+1;
    else
        return int(Number);
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
    cout << "My Ceil Result : " << MyCeil(Number) << endl;
    cout << "C++ Ceil Result: " << ceil(Number) << endl;

    return 0;
}
