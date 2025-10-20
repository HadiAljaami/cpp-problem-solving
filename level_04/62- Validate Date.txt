/*Write a program to read a tow periods then count overlap days?*/

#include<iostream>
using namespace std;

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month>12)
        return  0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
short NumberOfDaysInYear(short Year)
{
    return  isLeapYear(Year) ? 366 : 365;
}
struct sDate { short Year; short Month; short Day; };
short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}
short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;

    return Month;
}
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;

    return Year;
}
sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}
bool IsLastDayInMonth(sDate Date)
{

    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}
bool IsLastMonthInYear(short Month)
{
    return Month == 12;
}


bool ValidateDate(sDate Date)
{
    return(Date.Day > 0 && Date.Day <= NumberOfDaysInAMonth(Date.Month, Date.Year)) && (Date.Month>0 && Date.Month<=12) && Date.Year>0;
}

bool IsValidDate(sDate Date)
{ 
    if (Date.Day < 1 || Date.Day>31)
        return false;
    if (Date.Month < 1 || Date.Month>12) 
        return false; if (Date.Month == 2) 
    { 
        if (isLeapYear(Date.Year))
        {
            if (Date.Day > 29) 
                return false; 
        }
        else 
        {
            if (Date.Day > 28) return false; 
        } 
    }
    short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > DaysInMonth)
        return false;
    
    return true;
}

int main()
{
    sDate Date = ReadFullDate();


    if (ValidateDate(Date))
        cout << "\nDate is validate" << endl;
    else
        cout << "\n Date isn't validate" << endl;
  
    return 0;
}