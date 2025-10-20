
/*write a program to print total days from the beginnign of year.
Take the total days and convert them back to date.

please enter a day? 20
please enter a month?9
please enter a Year:2022

Number of Days fromther begining of ther year is 263

Data for [263] is : 20/9/2022
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

short TotalDaysFromTheBeggingOfYear(short Day, short Month, short Year)
{
    short TotalDays = 0;
    for (int i = 1;i < Month;i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}
short NumberOfDaysInYear(short Year)
{
    return  isLeapYear(Year) ? 366 : 365;
}
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0; for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }
    TotalDays += Day;
    
    return TotalDays;
}

struct sDate{ short Year; short Month; short Day; };
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
    cout << "Number of Days fromther begining of ther year is " << TotalDaysFromTheBeggingOfYear(Day, Month, Year) << endl;
}
int main()
{
    short Day = ReadDay();
    short Month = ReadManth();
    short Year = ReadYear();
    short DaysOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);  
    
    cout << "\nNumber of Days from the begining of the year is " << DaysOrderInYear << "\n\n"; 
    sDate Date;   
    Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);    
    
    cout << "Date for [" << DaysOrderInYear << "] is: ";   
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

}

