/*Write a Program to read  Period and calculate period length in days ?*/



#include<iostream>
using namespace std;

enum enDateCompare { Before = -1, Equal = 0, After = 1 };
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
struct sPeriod { sDate StartDate;sDate EndDate; };


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
sPeriod ReadPeriod()
{
    sPeriod Period;
    cout << "\nEnter Start Date:";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:";
    Period.EndDate = ReadFullDate();

    return Period;
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

    ///this is faster
    return enDateCompare::After;
}
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
int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false) 
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2)) 
    {
        Days++; Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days; 
}

int PeriodLengthInDays(sPeriod Period, bool IncludeEndDate = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate); 
}
bool IsOverlapPeriods(sPeriod Period1, sPeriod Period2)
{
    if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before || CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
        return false;
    return true;
}

int main()
{
    cout << "\nEnter Period1:";
    sPeriod Period1 = ReadPeriod();

    cout << "\nPeriod Length is: " << PeriodLengthInDays(Period1);  
    cout << "\nPeriod Length (Including End Date) is: " << PeriodLengthInDays(Period1, true);

    return 0;
}