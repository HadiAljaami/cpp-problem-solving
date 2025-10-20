/*increase date by one day
Write a program to read date and make a function to increase date by one day.

please..?31
please..?12
please..? 2022

date after addign one days is : 1/1/2023
*/
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

struct sDate { short Year; short Month; short Day; };

bool IsLastDayInMonth(sDate Date)
{

    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return Month == 12;
}
sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1; Date.Day = 1; Date.Year++;
        }
        else
        {
            Date.Day = 1; Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}
sDate IncreaseOneDay(sDate Date)
{
    if (Date.Day < NumberOfDaysInAMonth(Date.Month, Date.Year))
        Date.Day++;
    else if(Date.Month==12)
    {
        Date.Year++;
        Date.Month=1;
        Date.Day = 1;
    }
    else
    {
        Date.Month++;
        Date.Day = 1;
    }

    return Date;
}
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

int main()
{
    sDate Date = ReadFullDate();
    Date = IncreaseOneDay(Date);
   
    cout << "\nDate after adding one day is: ";

    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
    system("pause>0");

    return 0;
}
