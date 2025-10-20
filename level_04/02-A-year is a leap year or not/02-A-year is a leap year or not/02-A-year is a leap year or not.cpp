/*write  a program to check if year is a leap year or ont.

Note :
All years which are perfectly divisible by 4 are leap years excpt for century years
(years ending with 00) , which are leap ears only if they are perfectly divisible by 400.

*/

// bool IsLeapYear(shortYear) { // leap year if perfectly divisible by 400if (Year % 400 == 0) { returntrue;     } // not a leap year if divisible by 100// but not divisible by 400elseif (Year % 100 == 0) { returnfalse;     } // leap year if not divisible by 100// but divisible by 4elseif (Year % 4 == 0) { returntrue;     } // all other years are not leap yearselse { returnfalse;     } } short ReadYear() { short Year;     cout << "\nPlease enter a year to check? ";     cin >> Year; return Year; } int main() { short Year = ReadYear(); if (IsLeapYear(Year))         cout << "\nYes, Year [" << Year << "] is a leap year.\n"; else        cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";     system("pause>0"); return 0; } 



#include <iostream>
using namespace std;

int ReadLeapYear()
{
	int Num;
		cout << "Enter a Year: ";
		cin >> Num;

	 while (Num < 1)
	 {
		 cout << "The Year cann't leas than one, Enter again: ";
		 cin >> Num;
	 }
	
	return Num;
}

//bool IsLeapYear(int Year)
//{
//	if (Year % 400 == 0)
//	{
//		return true;
//	}
//	else if  ((Year % 4 ==0) && (Year % 1000 !=0))
//	{
//		return true;
//	}
//	else {
//		return false;
//	}
//}
// 2000 ,2004 ,1968, 1200,1600 => leap year
//1971,2006,2010 =>not

bool IsLeapYear(int Year)
{
	// «ﬂ”»—‘‰
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}
int main()
{
	cout <<IsLeapYear(ReadLeapYear());
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
