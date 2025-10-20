
/*
Diff In Days

Write a program to read a Date1, Date2 and make a functionn to caculate the
difference in days.

Note: Date1 should be less than Date2


Please Enter a day?1
please..?1
please..? 2022

please enter a Day? 25
please enter a month? 3
please enter a year? 2022


Diffrence is : 83 Day(s).
Diffrence (Including End Day) is : 84 Day(s).

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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2) 
{
    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false); 
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
  int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
  {
      int Days = 0; 
      while (IsDate1BeforeDate2(Date1, Date2))
      { 
          Days++; 
          Date1 = IncreaseDateByOneDay(Date1); 
      } 
      return IncludeEndDay ? ++Days : Days;
  }
  //------------------this my functiion=----------
  int DiffrentDays(sDate Date1, sDate Date2)
  {
      short YearOfLastDate2 = NumberOfDaysFromTheBeginingOfTheYear(Date2.Day, Date2.Month, Date2.Year);
      short YearOfBegginingDate1 = 0;
      int AllDays = 0;
      if (Date1.Year == Date2.Year)
      {
          YearOfBegginingDate1 = NumberOfDaysFromTheBeginingOfTheYear(Date1.Day, Date1.Month, Date1.Year);
          AllDays= YearOfLastDate2 - YearOfBegginingDate1;
          return AllDays;
      }
      else
      {
          for (int i = Date1.Year + 1;i < Date2.Year;i++)
          {
              AllDays += NumberOfDaysInYear(i);
          }
          YearOfBegginingDate1 = NumberOfDaysInYear(Date1.Year) - NumberOfDaysFromTheBeginingOfTheYear(Date1.Day, Date1.Month, Date1.Year);
          AllDays += YearOfLastDate2 + YearOfBegginingDate1;
          return AllDays;
      }

  }
      //this my fuction2 is very fast
  int DiffrentDays2(sDate Date1, sDate Date2)
  {
      
      int AllDays = 0;
      if (Date1.Year == Date2.Year)
      {
          while (IsDate1BeforeDate2(Date1, Date2))
          {
              AllDays++;
              Date1 = IncreaseDateByOneDay(Date1);
          }
          return AllDays;
      }
      else
      {
          for (int i = Date1.Year + 1;i < Date2.Year;i++)
          {
              AllDays += NumberOfDaysInYear(i);
          }
          short YearOfLastDate2 = NumberOfDaysFromTheBeginingOfTheYear(Date2.Day, Date2.Month, Date2.Year);
          short YearOfBegginingDate1 = 0;

          YearOfBegginingDate1 = NumberOfDaysInYear(Date1.Year) - NumberOfDaysFromTheBeginingOfTheYear(Date1.Day, Date1.Month, Date1.Year);
          AllDays += YearOfLastDate2 + YearOfBegginingDate1;
          return AllDays;
      }

  }
  int main() 
  { 
      sDate Date1 = ReadFullDate(); 
      sDate Date2 = ReadFullDate(); 
      cout << "\nDiffrence is: " << GetDifferenceInDays(Date1, Date2) << " Day(s)."; 
      cout << "\nDiffrence (Including End Day) is: " << GetDifferenceInDays(Date1, Date2, true) << " Day(s)."; 
      
      cout << "\n(my funcntion )Diffrence is: " << DiffrentDays(Date1, Date2) << " Day(s).";

      cout << "\n(my funcntion2 )Diffrence is: " << DiffrentDays2(Date1, Date2) << " Day(s).";
      system("pause>0"); 
      return 0; 
  
  }




