
/*

Write a program to read a date and check:
- if it is last Day in Month
- if it is last Month in year.

pleas..day ? 31
please ? 12
please ? 2022

yes,Day is Last Day in Month.
Yes, Month is Last Month in Year.
*/




#include<iostream>
using namespace std;
struct stDate
{
	short Year; short Month; short Day;
};

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
	cout << "Please enter a Month? ";
	cin >> Month; return Month;
}
short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;
}

stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

bool IsLastDayInMonth(stDate Date)
{
	
	return (Date.Day == NumberOfDaysInAMonth(Date.Month,Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return Date.Month == 12;
}

int main()
{
	stDate Date1 = ReadFullDate();
	
	if (IsLastDayInMonth(Date1))
	{
		cout << "Yes Day is Last in month" << endl;
	}
	else
	{
		cout << "No Day isn't Last in month" << endl;
	}

	system("pause>0");
	return 0;
}