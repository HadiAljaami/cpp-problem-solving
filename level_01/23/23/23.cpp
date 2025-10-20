#include <iostream>
#include "23.h"
using namespace std;
struct  Traingle
{
    float A;
    float B;
    float C;
};
Traingle ReadTraingleData()
{
    Traingle T;
    cout << "Enter the a\n";
    cin >> T.A;
    while (T.A < 0 || cin.fail())
    {
        if (cin.fail())
        {
            cout << "Error, Enter only numbers \n";
            cin.clear();   
            cin.ignore(10000, '\n');
            cin >> T.A;
        }
        else
        {
            cout << "Error, Enter the Circmference\n";
            cin >> T.A;
        }

    }
    cout << "Enter the b\n";
    cin >> T.B;
    while (T.B < 0 || cin.fail())
    {
        if (cin.fail())
        {
            cout << "Error, Enter only numbers \n";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> T.B;
        }
        else
        {
            cout << "Error, Enter the Circmference\n";
            cin >> T.B;
        }

    }

    cout << "Enter the C\n";
    cin >> T.C;
    while (T.C < 0 || cin.fail())
    {
        if (cin.fail())
        {
            cout << "Error, Enter only numbers \n";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> T.C;
        }
        else
        {
            cout << "Error, Enter the Circmference\n";
            cin >> T.C;
        }

    }

    return T;
}
float CircleAreaByTraingle(Traingle T)
{
    const float pi = 3.14;
    float   P = (T.A+T.B+T.C)/2;

    float area = pi*pow(T.A*T.B*T.C/(4*sqrt(P*(P-T.A)*(P-T.B)*(P-T.C))),2);
    return area;

}
void printCircleArea(float x)
{
    cout << "The CircleArea = " << x << endl;
}
int main()
{
   
   
   
   printCircleArea(CircleAreaByTraingle(ReadTraingleData()));

}