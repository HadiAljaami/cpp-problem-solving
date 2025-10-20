/*Write a Program to read Date1 Date2, and write a function to compare dates, it
shold return;

- -1 Before
- 0 Equal
- 1 After
*/


#include<iostream>
using namespace std;

enum enDateCompare { Before =-1, Equal=0, After=1};
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
bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
}

enDateCompare CompareDates(sDate Date1, sDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    
    /* if (IsDate1AfterDate2(Date1,Date2))   
    return enDateCompare::After;
    *///this is faster

    return enDateCompare::After;
}
int main()
{
    cout << "\nEnter Date1:";
    sDate Date1 = ReadFullDate();
    cout << "\nEnter Date2:";

    sDate Date2 = ReadFullDate();

    cout << "\nCompare Result = " << CompareDates(Date1, Date2);

    return 0;
}