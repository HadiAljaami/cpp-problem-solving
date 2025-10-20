/*writ a program to print Number of
- Days
- Hours
- Minutes
- Seconds
- in a certain year.*/

#include<iostream>

using namespace std;

bool isLeapYear(short Year) 
{ // if year is divisible by 4 AND not divisible by 100
  // OR if year is divisible by 400
  // then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0); 
}
short ReadYear()
{
	short Year;  
	cout << "\nPlease enter a year to check? "; 
	cin >> Year; 
	return Year;
}     
short NumberOfDaysInYear(short Year)
{
	return  isLeapYear(Year) ? 366 : 365; 
}
short NumberOfHoursInYear(short Year)
{
	return NumberOfDaysInYear(Year) * 24;
}
short NumberOfMinutesInYear(short Year)
{
	return NumberOfHoursInYear(Year) * 60;
}
int NumberOfSecondsInYear(short Year)
{
	return NumberOfMinutesInYear(Year) * 60;
}
void PrintDaysHoursMinutesSecondsInYear(short Year)
{
	cout << "Number of Days in Year [ " << Year << " ] => " << NumberOfDaysInYear(Year) <<endl ;
	cout << "Number of Hours in Year[ " << Year << " ] => " << NumberOfHoursInYear(Year) << endl;
	cout << "Number of Minutes in Year[ " << Year << " ] => " << NumberOfMinutesInYear(Year) << endl;
	cout << "Number of Seconds in Year[ " << Year << " ] => " << NumberOfSecondsInYear(Year) << endl;
}
int main()
{
	PrintDaysHoursMinutesSecondsInYear(ReadYear());
}