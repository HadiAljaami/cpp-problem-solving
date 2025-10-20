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
void PrintDigits(int Number) 
{ 
    int  Remainder = 0; 
    while (Number > 0) 
    { 
        Remainder = Number % 10;
        Number /= 10;

        cout << Remainder;
    } 
} 
int main()
{
    PrintDigits(ReadPositiveNumber("Please enter Positev Number"));
}