/*Add Days To Date


/*write a program to read date and read how many days to add to it , print the
results on screen.

please enter a day? 20
please enter a month?9
please enter a Year:2022

How many days to add ? 2500

Date after addding [255] days is  : 14/8/2029

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

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
    sDate Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;

    Date.Year = Year;
    Date.Month = 1;
    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

sDate AddDaysToDate(sDate Date, int RemainingDays)
{
    
    short TotalDays = 0;
    TotalDays += Date.Day;
    Date.Day = 0;
    for (int i = 1;i < Date.Month;i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Date.Year);
    }
    Date.Month = 0;
    RemainingDays += TotalDays;

    while(true)
    {
        short Y = NumberOfDaysInYear(Date.Year );
        if (Y < RemainingDays)
        {
            Date.Year++;
            RemainingDays -= Y;
            
        }
        else
        {

             Date= GetDateFromDayOrderInYear(RemainingDays,Date.Year);
             break;

        }
    }

    return Date;
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
    cout << "Number of Days fromther begining of ther year is " << NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year) << endl;
}
int main()
{
    short Day = ReadDay();
    short Month = ReadManth();
    short Year = ReadYear();
    sDate Date;
    Date.Day = Day;
    Date.Month = Month;
    Date.Year = Year;
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
    

    int Days = ReadDay();
    Date = AddDaysToDate(Date,Days);
    cout << endl;
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

}

