/*
Write a program to read a date and make functions as follows:

- Overload the DayOfWeekOrder ot take date structure
- IsEndOfweek
- IsWeekEnd
- IsBusinessDay
- DaysUntilTheEndOfWeek
- DaysUntilTheEndOfMonth
- DaysUntilTheEndOfYear
*/
#include<iostream>
using namespace std;

struct sDate { short Year; short Month; short Day; };
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
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }
    TotalDays += Day;

    return TotalDays;
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
short ReadNumber()
{
    short Days;
    cout << "\nHow many days to add? ";
    cin >> Days;
    return Days;
}
bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));

}
bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}
string DayShortName(short DayOfWeekOrder)
{ 
    string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" }; 
    return arrDayNames[DayOfWeekOrder]; 
}
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}
short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;

    m = Month + (12 * a) - 2; // Gregorian://0:sun, 1:Mon, 2:Tue...etc

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short DayOfWeekOrder(sDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

bool IsEndOfweek(sDate Date)
{
    return DayShortName( DayOfWeekOrder(Date))=="Fri"; //5
    //return  DayOfWeekOrder(Date) == 6;
}
bool IsWeekEnd(sDate Date)
{
    //return DayShortName(DayOfWeekOrder(Date)) == "Fri" || DayShortName(DayOfWeekOrder(Date)) == "Thu";

    // Weekends are Fri and Thu 
    short DayIndex = DayOfWeekOrder(Date);
    return  (DayIndex == 5 || DayIndex == 4);
}
bool IsBusinessDay(sDate Date)
{
    return  !IsWeekEnd(Date);
}
short DaysUntilTheEndOfWeek(sDate Date)
{
    //return 6 - DayOfWeekOrder(Date);
    short Days = 0;
    while (true)
    {
        if (IsEndOfweek(Date))
            return Days;
        Date.Day++;
        Days++;
    }
}
short DaysUntilTheEndOfMonth(sDate Date1)
{
    sDate EndOfMontDate;
    EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);

    EndOfMontDate.Month = Date1.Month;
    EndOfMontDate.Year = Date1.Year;

    return GetDifferenceInDays(Date1, EndOfMontDate, true);
}
short DaysUntilTheEndOfMonth2(sDate Date)
{
    short Days = 0;
   /* while (true)
    {
        if (IsLastDayInMonth(Date))
            return Days;
        Date.Day++;
        Days++;
    }*/
    for (int i = Date.Day;i <= NumberOfDaysInAMonth(Date.Month,Date.Year);i++)
    {
        Days++;
    }
    return Days;
}
short DaysUntilTheEndOfYear(sDate Date1)
{
    sDate EndOfMontDate;
    EndOfMontDate.Day = 31;
    EndOfMontDate.Month = 12;
    EndOfMontDate.Year = Date1.Year;

    return GetDifferenceInDays(Date1, EndOfMontDate, true);
}
short DaysUntilTheEndOfYear2(sDate Date)
{
    short Days = 0;
    if (Date.Month == 12)
    {
        Days = DaysUntilTheEndOfMonth(Date);
        return  Days;
    }
    else
    {
        Days = DaysUntilTheEndOfMonth(Date);
        for (int i = Date.Month + 1;i <= 12;i++)
        {
            Days += NumberOfDaysInAMonth(i, Date.Year);
        }
        return Days;
    }
}

int main()
{
    sDate Date = ReadFullDate();

    if (IsEndOfweek(Date))
    {
        cout << "Yes The " << DayShortName(DayOfWeekOrder(Date)) << " is end of the week\n";
    }
    else
    {
        cout << "No The " << DayShortName(DayOfWeekOrder(Date)) << " is Not end of the week\n";
    }

    if (IsWeekEnd(Date))
    {
        cout << "Yes The " << DayShortName(DayOfWeekOrder(Date)) << " is WeekEnd\n";
    }
    else
    {
        cout << "No The " << DayShortName(DayOfWeekOrder(Date)) << " is Not WeekEnd\n";
    }

    if (IsBusinessDay(Date))
    {
        cout << "Yes The " << DayShortName(DayOfWeekOrder(Date)) << " is Business Day\n";
    }
    else
    {
        cout << "No The " << DayShortName(DayOfWeekOrder(Date)) << " is Not Business Day\n";
    }


    cout << "\n The Days Until To The End Of The Week are : " << DaysUntilTheEndOfWeek(Date) <<endl;
    cout << "\n The Days Until To The End Of The Month are : " << DaysUntilTheEndOfMonth(Date) << endl;
    cout << "\n The Days Until To The End Of The Year are : " << DaysUntilTheEndOfYear(Date) << endl;
    system("pause>0");

    return 0;
}