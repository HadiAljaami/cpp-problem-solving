/*please Enter Your Date of Birth:

please enter a days? 6
please enter a Month? 11
please enter a Year? 1977

Your Age is: 16391 Day(s).*/


#include<iostream>
#include <ctime>
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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));

}
bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
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

//this my fuction2 is very fast
int DiffrentDays2(sDate Date1, sDate Date2)
{

    int AllDays = 0;
    if (Date1.Year == Date2.Year)
    {
        while (IsDate1BeforeDate2(Date1, Date2))
        {
            AllDays++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return AllDays;
    }
    else
    {
        for (int i = Date1.Year + 1;i < Date2.Year;i++)
        {
            AllDays += NumberOfDaysInYear(i);
        }
        short YearOfLastDate2 = NumberOfDaysFromTheBeginingOfTheYear(Date2.Day, Date2.Month, Date2.Year);
        short YearOfBegginingDate1 = 0;

        YearOfBegginingDate1 = NumberOfDaysInYear(Date1.Year) - NumberOfDaysFromTheBeginingOfTheYear(Date1.Day, Date1.Month, Date1.Year);
        AllDays += YearOfLastDate2 + YearOfBegginingDate1;
        return AllDays;
    }

}


sDate GetSystemDate()
{
   /* sDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;*/
    time_t now = time(0);
    tm local_time;
    localtime_s(&local_time, &now);

    sDate CurrentDate;
    CurrentDate.Day = local_time.tm_mday;
    CurrentDate.Month = local_time.tm_mon + 1;
    CurrentDate.Year = local_time.tm_year + 1900;

    return CurrentDate;
}
int main()
{
    cout << "\nPlease Enter Your Date of Birth:\n";
    sDate Date1 = ReadFullDate();
    sDate Date2 = GetSystemDate();
    cout << "\nYour Age is : " << GetDifferenceInDays(Date1, Date2, true) << " Day(s).";

    system("pause>0");
    return 0;
}


