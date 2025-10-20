/*Write a program to read Vacation Period DateFrom and Date To and make a function to
calculate the actual vacation Days.


Note: Weekends are excluded.

vaction starts:
Pleas enter a day? 1
pleas enter a Month? 9
Please enter a Year? 2022

Vaction Ends:
Please enter a DAys ?5
Please enter a MOnth? 9
Please enter a Year ? 2022

Vaction From  The, 1/9/2022
Vaction To : Mon, 5/9/2022

Actucal Vacation DAys is : 2.
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

bool IsWeekEnd(sDate Date)
{
    //return DayShortName(DayOfWeekOrder(Date)) == "Fri" || DayShortName(DayOfWeekOrder(Date)) == "Thu";

    // Weekends are Fri and Thu 
    short DayIndex = DayOfWeekOrder(Date);
    return  (DayIndex == 5 || DayIndex == 4);
}
bool IsBusinessDay(sDate Date)
{
    return !IsWeekEnd(Date);;
}

short  CalculateTheActualVacationDays(sDate VactionStart,sDate VactionEnd)
{
    int Days = 0;
    while (IsDate1BeforeDate2(VactionStart, VactionEnd))
    {
        //if(!IsWeekEnd(VactionStart))
        if (IsBusinessDay(VactionStart))
        Days++;
        VactionStart = IncreaseDateByOneDay(VactionStart);
    }
    return  Days;
}
int main()
{
    cout << "vaction starts : \n";
    sDate VactionStart = ReadFullDate();
    cout << "Vaction Ends : \n";
    sDate VactionEnd = ReadFullDate();

    cout << "Vaction From : " <<  VactionStart.Day << "/" << VactionStart.Month << "/" << VactionStart.Year<<endl;
    cout << "Vaction To : "  << VactionEnd.Day << "/" << VactionEnd.Month << "/" << VactionEnd.Year <<endl;

    cout << "Actucal Vacation Days : " << CalculateTheActualVacationDays(VactionStart, VactionEnd);
    system("pause>0");

    return 0;
}