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

sDate DecreaseDateByOneDay(sDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        } 
        else 
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        } 
    } 
    else
    {
        Date.Day--;
    }
    return Date;
}
sDate DecreaseDateBy10Days(sDate Date)
{
    if ((Date.Day - 10) >=1)
    {
        Date.Day -= 10;
    }
    else
    {
        if (Date.Month==1)
        {
            short t =  Date.Day-10;   
            Date.Month = 12;
            Date.Year--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year) + t;
           
        }
        else
        {
            short t = Date.Day - 10;
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year) + t;
           
        }

    }
    return Date;
}
sDate DecreaseDateByOneWeak(sDate Date)
{
    if ((Date.Day - 7) >= 1)
    {
        Date.Day -= 7;
    }
    else
    {
        if (Date.Month == 1)
        {
            short t = Date.Day - 7;
            Date.Month = 12;
            Date.Year--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year) + t;

        }
        else
        {
            short t = Date.Day - 7;
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year) + t;

        }

    }
    return Date;
}
sDate DecreaseDateByXWeak(sDate Date, int NumOfWeak)
{
    for (int i = 1;i <= NumOfWeak;i++)
    {
        Date = DecreaseDateByOneWeak(Date);
    }
    return Date;
}
sDate DecreaseDateByOneMonth(sDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }

    if (Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year))
        Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);

    return Date;
}
sDate DecreaseDateByXDay(sDate Date, short Days)
{
   /* for (short i = 1; i <= Days; i++) { Date = DecreaseDateByOneDay(Date); }*/

    short MonthDays = 0;
    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (Days >= MonthDays && Date.Day <= 28)
        {
            Days -= MonthDays;
            Date = DecreaseDateByOneMonth(Date);
        }
        else if (Days >= 10)
        {
            Days -= 10;
            Date = DecreaseDateBy10Days(Date);
        }
        else
        {

            Days -= 1;
            Date = DecreaseDateByOneDay(Date);

            if (Days < 1)
                break;
        }
    }
    return Date;
}
sDate DecreaseDateByXMonth(sDate Date, int NumOfMonth)
{
    for (int i = 1;i <= NumOfMonth;i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;

}
sDate DecreaseDateByOneYear(sDate Date)
{
    Date.Year--;
    return Date;
}
sDate DecreaseDateByXYear(sDate Date, int NumOfYear)
{
    if (NumOfYear > 0)
        Date.Year -= NumOfYear;
    return Date;
}
sDate DecreaseDateByOneDecade(sDate Date)
{
    Date.Year -= 10;
    return Date;
}
sDate DecreaseByXDecade(sDate Date, int NumOfDecade)
{
    if (NumOfDecade > 0)
        Date.Year -= (NumOfDecade * 10);
    return Date;
}
sDate DecreaseDateByOneCentury(sDate Date)
{
    Date.Year -= 100;
    return Date;
}
sDate DecreaseDateByOneMillennium(sDate Date)
{
    Date.Year -= 1000;
    return Date;
}

int main()
{
    sDate Date = ReadFullDate();

    Date = DecreaseDateByOneDay(Date);
    cout << "\n01- Decrease one day is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateBy10Days(Date);
    cout << "\n02- Adding ten day is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    /*Date = DecreaseDateByXDay(Date, 30);
    cout << "\n03- Adding X " << 30 << " days is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;*/

    Date = DecreaseDateByOneWeak(Date);
    cout << "\n04- Adding one weak is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    Date = DecreaseDateByXWeak(Date,10);
    cout << "\n05- Adding one weak is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
    system("pause>0");

    return 0;
}