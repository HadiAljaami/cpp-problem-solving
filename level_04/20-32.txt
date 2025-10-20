/*
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
sDate IncreaseDateByXDay(sDate Date, short Days)
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);

    short MonthDays = 0;
    Date.Month = 1;
    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}
sDate IncreaseDateBy10Days(sDate Date)
{
    if ((Date.Day+10 )<= NumberOfDaysInAMonth(Date.Month,Date.Year))
    {
        Date.Day+=10;
    }
    else
    {
        if (IsLastMonthInYear(Date.Month))
        {
            short t = NumberOfDaysInAMonth(Date.Month, Date.Year)-Date.Day;
            Date.Day =10-t;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            short t = NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day;
            Date.Day = 10 - t;
            Date.Month++;
        }
      
    }
    return Date;
}
sDate IncreaseDateByOneWeak(sDate Date)
{
    if ((Date.Day + 7) <= NumberOfDaysInAMonth(Date.Month, Date.Year))
    {
        Date.Day += 7;
    }
    else
    {
        if (IsLastMonthInYear(Date.Month))
        {
            short t = NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day;
            Date.Day = 7 - t;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            short t = NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day;
            Date.Day = 7 - t;
            Date.Month++;
        }

    }
    return Date;
}
sDate IncreaseDateByXWeak(sDate Date,int NumOfWeak)
{
    for (int i = 1;i <= NumOfWeak;i++)
    {
        Date= IncreaseDateByOneWeak(Date);
    }       
    return Date;
}
sDate IncreaseDateByOneMonth(sDate Date)
{
    if (Date.Month== IsLastMonthInYear(Date.Month))
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    if (Date.Day < NumberOfDaysInAMonth(Date.Month, Date.Year))
        Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);

    return Date;
}
sDate IncreaseDateByXMonth(sDate Date,int NumOfMonth)
{
    for (int i = 1;i <= NumOfMonth;i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
    
}
sDate IncreaseDateByOneYear(sDate Date)
{
    Date.Year++;
    return Date;
}
sDate IncreaseDateByXYear(sDate Date,int NumOfYear)
{
    if(NumOfYear>0)
    Date.Year+= NumOfYear;
    return Date;
}
sDate IncreaseDateByOneDecade(sDate Date)
{
    Date.Year += 10;
    return Date;
}
sDate IncreaseDateByXDecade(sDate Date,int NumOfDecade)
{
    if(NumOfDecade>0)
    Date.Year += (NumOfDecade*10);
    return Date;
}
sDate IncreaseDateByOneCentury(sDate Date)
{
    Date.Year += 100;
    return Date;
}
sDate IncreaseDateByOneMillennium(sDate Date)
{
    Date.Year += 1000;
    return Date;
}

int main()
{
    sDate Date = ReadFullDate();
  
    Date = IncreaseDateByOneDay(Date);
    cout << "\n01- Adding one day is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateBy10Days(Date);
    cout << "\n02- Adding ten day is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByXDay(Date,30);
    cout << "\n03- Adding X "<<30 << " days is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = IncreaseDateByOneWeak(Date);
    cout << "\n04- Adding one weak is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
    system("pause>0");

    return 0;
}