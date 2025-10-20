/*Nubmer of Days-HOurs-Minutes- Seconds In a Month

write a program to print Number of :
-day
-hous
- minutes
- seconds


in a certain Month.

----
please enter a year to check? 2000
please enter a Month to check? 2
...
*/
#include<iostream>

using namespace std;

bool isLeapYear(short Year)
{ // if year is divisible by 4 AND not divisible by 100
  // OR if year is divisible by 400
  // then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
//short NumberOfDaysInAMonth(short Month, short Year)
//{
//	if (Month < 1 || Month>12) 
//		return  0;
//	if (Month == 2)
//	{
//		return  isLeapYear(Year) ? 29 : 28;
//	}
//	short arr31Days[7] = { 1,3,5,7,8,10,12 };
//	for (short i = 1; i <= 7; i++) 
//	{
//		if (arr31Days[i - 1] == Month) 
//			return 31;
//	}
//	//if you reach here then its 30 days.
//	return  30;
//}
short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return  0;
	short DaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return  (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : DaysInMonth[Month - 1];
}
short NumberOfHoursInAMonth(short Month, short Year) 
{
	return  NumberOfDaysInAMonth(Month, Year) * 24; 
}
int NumberOfMinutesInAMonth(short Month, short Year) 
{
	return  NumberOfHoursInAMonth(Month, Year) * 60;
}
int NumberOfSecondsInAMonth(short Month, short Year) 
{
	return  NumberOfMinutesInAMonth(Month, Year) * 60;
} 
short ReadMonth() { 
	short Month;
	cout << "\nPlease enter a Month to check? ";    
	cin >> Month;
	
	return Month; 
}
short ReadYear() 
{
	short Year;  
	cout << "\nPlease enter a year to check? ";
	cin >> Year; 
	
	return Year;
}
int main() 
{
	short Year = ReadYear(); 
	short Month = ReadMonth();
	cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInAMonth(Month, Year); 
	cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberOfHoursInAMonth(Month, Year);    
	cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInAMonth(Month, Year);     
	cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInAMonth(Month, Year);    
	
	system("pause>0");
	return 0; 
}

//short ReadNumber(string Massge)
//{
//	short Year;
//	cout << Massge;
//	cin >> Year;
//	return Year;
//}
//short NumberOfDaysInMonth(short Year, short Month)
//{
//	short DaysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//
//	if (Month > 12 || Month < 1)
//		return 0;
//	if (Month == 2 && isLeapYear(Year))
//		DaysInMonth[Month] = 29;
//
//	return DaysInMonth[Month];
//}
//int main()
//{
//	short Year = ReadNumber("\nPlease enter a year to check? ");
//	short Month = ReadNumber("\nPlease enter a month to check? ")
//	//PrintDaysHoursMinutesSecondsInYear();
//}