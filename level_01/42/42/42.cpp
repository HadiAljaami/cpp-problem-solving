#include <iostream>
using namespace std;
struct stDayHoursMinutesSeconde
{
    int Day = 0;
    int  Hours = 0;
    int   Minutes = 0;
    int Seconde = 0;
};
stDayHoursMinutesSeconde ReadDayHoursMinutesSeconde()
{
    stDayHoursMinutesSeconde   DayHoursMinutesSeconde;
    do
    {
        cout << "Enter The Days: ";cin >> DayHoursMinutesSeconde.Day;
    } while (DayHoursMinutesSeconde.Day < 0);
    do
    {
        cout << "Enter The Hours: ";cin >> DayHoursMinutesSeconde.Hours;
    } while (DayHoursMinutesSeconde.Hours < 0);
    do
    {
        cout << "Enter The Minutes: ";cin >> DayHoursMinutesSeconde.Minutes;
    } while (DayHoursMinutesSeconde.Minutes < 0);
    do
    {
        cout << "Enter The Hours: ";cin >> DayHoursMinutesSeconde.Seconde;
    } while (DayHoursMinutesSeconde.Seconde < 0);

    return DayHoursMinutesSeconde;
}

int CalculateTotalSecondes(stDayHoursMinutesSeconde DayHoursMinutesSeconde)
{
    int secondes = DayHoursMinutesSeconde.Seconde +
        DayHoursMinutesSeconde.Minutes * 60 +
        DayHoursMinutesSeconde.Hours * 3600 +
        DayHoursMinutesSeconde.Day * 86400;

    return secondes;
}

void PrintDayHoursMinutesSeconde(int secondes)
{
    cout << "\nThe  secondes :" << secondes;
}
int main()
{
    PrintDayHoursMinutesSeconde(CalculateTotalSecondes(ReadDayHoursMinutesSeconde()));

}