#include <iostream>
#include <string>
using namespace std;
int ReadNumber()
{
    int Num;
    cout << "Enter A Number : ";
    cin >> Num;

    return Num;
}
float HalfNumber(int Num)
{
    return (float)Num/ 2;
}

string convertNumber(int Num)
{
    string  convertNumber = " half of "+ to_string(Num) +" is "+ to_string(HalfNumber(Num));

    return convertNumber;
}

void printConvertNumber(string convertNumber)
{
    cout << convertNumber << endl;

}
int main()
{
    printConvertNumber(convertNumber(ReadNumber()));
}