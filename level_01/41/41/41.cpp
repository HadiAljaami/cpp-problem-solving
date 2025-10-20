#include <iostream>
using namespace std;
struct stWeeksAndDays
{   float Days = 0;
    float Weeks = 0;
};
void ReadNumberHours(int& Hours)
{
    do
    {
        cout << "Enter The Hours: ";cin >> Hours;
    } while (Hours < 0);


}

stWeeksAndDays TheWeeksAndDays( int Hours )
{
    stWeeksAndDays WeeksAndDays;
    WeeksAndDays.Days = (float)Hours / 24;
    WeeksAndDays.Weeks = WeeksAndDays.Days / 7;

    return WeeksAndDays;
}

void PrintTheWeeksAndDays(stWeeksAndDays WeeksAndDays)
{
    cout << "\nThe  Days :" <<  WeeksAndDays.Days;
    cout << "\nThe  Weeks :" << WeeksAndDays.Weeks;

}
int main()
{
   int Hours = 0;
    ReadNumberHours(Hours);
    PrintTheWeeksAndDays(TheWeeksAndDays(Hours));

}