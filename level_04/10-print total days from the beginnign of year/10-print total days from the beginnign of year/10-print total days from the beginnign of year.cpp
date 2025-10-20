/*write a program to pront Month calendar.*/
#include<iostream>
using namespace std;

bool isLeapYear(short Year)
{ // if year is divisible by 4 AND not divisible by 100// OR if year is divisible by 400
// then it is a leap year 
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month>12)
        return  0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short TotalDaysFromTheBeggingOfYear(short Day,short Month, short Year)
{
   short TotalDays = 0;
    for (int i = 1;i < Month;i++)
    {
       TotalDays+= NumberOfDaysInAMonth(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}
short NumberOfDaysInYear(short Year)
{
    return  isLeapYear(Year) ? 366 : 365;
}
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}
short ReadManth()
{
    short Year;
    cout << "\nPlease enter a Month? ";
    cin >> Year;
    return Year;
}
short ReadDay()
{
    short Year;
    cout << "\nPlease enter a Day? ";
    cin >> Year;
    return Year;
}
void PrintTotalDaysFromTheBeggingOfYear(short Day, short Month, short Year)
{
    cout << "Number of Days fromther begining of ther year is " << TotalDaysFromTheBeggingOfYear(Day, Month, Year) <<endl;
}
int main()
{
    short Day = ReadDay();
    short Month = ReadManth();
    short Year = ReadYear();
    PrintTotalDaysFromTheBeggingOfYear(Day,Month,Year);
    
}
