/*
Date1 Less Than Date 2

p
please enter a month?2
please enter a Year?2022


please enter a day? 12
please enter a month?3
please enter a Year?2022

Yes, Date1 is Less than Date2.

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
void Date1LessThanDate2(sDate Date1, sDate Date2)
{

    if (Date1.Year == Date2.Year)
    {
        if (Date1.Month == Date2.Month)
        {
            if (Date1.Day == Date2.Day)
                cout << "Date1 equle Date2" << endl;
            else if (Date1.Day < Date2.Day)
                cout << "Date1 Less Than Date2" << endl;
            else
                cout << "Date1 Greater Than Date2" << endl;

        }
        else if(Date1.Month <Date2.Month)
            cout << "Date1 Less Than Date2" << endl;
        else
            cout << "Date1 Greater Than Date2" << endl;
      
    }
    else if (Date1.Year < Date2.Year)
        cout << "Date1 Less Than Date2" << endl;
    else
        cout << "Date1 Greater Than Date2" << endl;
}
int main()
{
    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();
    Date1LessThanDate2(Date1, Date2);


    return 0;
}