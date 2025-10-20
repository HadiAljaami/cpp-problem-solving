#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return  0;
	short DaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return  (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : DaysInMonth[Month - 1];
}
short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2; // Gregorian://0:sun, 1:Mon, 2:Tue...etc

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];

}

void PrintMonthCalendar(short Month, short Year)
{
	cout << "\n\n  ------------Month("<<Month<<")------------\n\n";
	cout << setw(5) << right << "Sun"  
		 << setw(5) << right << "Mon"
		 << setw(5) << right << "Tue"
		 << setw(5) << right << "Wed"
		 << setw(5) << right << "Thu"
		 << setw(5) << right << "Fri"
		 << setw(5) << right << "Sat" << endl;

	string FirstDay = DayShortName(DayOfWeekOrder(1, Month, Year));
	short FirsDay = 1;
	if (FirstDay == "Mon")
		cout << setw(10) << right << FirsDay;
	else if (FirstDay == "Tue")
		cout << setw(15) << right << FirsDay;
	else if (FirstDay == "Wed")
		cout << setw(20) << right << FirsDay;
	else if (FirstDay == "Thu")
		cout << setw(25) << right << FirsDay;
	else if (FirstDay == "Fri")
		cout << setw(30) << right << FirsDay;
	else if (FirstDay == "Sat")
		cout << setw(35) << right << FirsDay <<endl;
	else if (FirstDay == "Sun")
		cout << setw(5) << right << FirsDay;
	else
		cout << "";

	

	for (int i = 2;i<=NumberOfDaysInAMonth(Month,Year);i++)
	{
		cout << setw(5) << right << i;
		
		
		if (DayShortName(DayOfWeekOrder(i,Month,Year))=="Sat")
			cout << endl;
	}
}				

short ReadMonth()
{
	short Month;     cout << "\nPlease enter a Month? ";     cin >> Month; return Month;
}
short ReadYear()
{
	short Year;     cout << "\nPlease enter a year? ";
	cin >> Year; return Year;
}
int main()
{
	//PrintMonthCalendar(ReadMonth(), ReadYear());

	string s = "123.5849";  //123.585
	       s = "123.5840"; //123.584
		   s = "123.5845"; //123.584
		   s = "123.584560"; //123.584
		   s = "123.584110"; //123.584
		   s = "123.115599";// 123.116
		   s = "123.2346";// 123.235


	float f = stof(s);
	cout << f << endl;

	system("pause>0"); 
	return 0;
}		   