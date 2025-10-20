#include <iostream>
using namespace std;
void ReadTraingleData(float& a, float& b)
{
    cout << "Enter the a\n";
    cin >> a;
    while (a < 0 || cin.fail())
    {
        if (cin.fail())
        {
            cout << "Error, Enter only numbers \n";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> a;
        }
        else
        {
            cout << "Error, Enter the Circmference\n";
            cin >> a;
        }

    }
    cout << "Enter the b\n";
    cin >> b;
    while (b < 0 || cin.fail())
    {
        if (cin.fail())
        {
            cout << "Error, Enter only numbers \n";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> b;
        }
        else
        {
            cout << "Error, Enter the Circmference\n";
            cin >> b;
        }

    }


}
float CircleAreaByTraingle(float a,float b)
{
    const float pi = 3.14;
    float area = (pi*pow(b,2)/4) * ((2*a-b)/(2*a+b));
    return area;

}
void printCircleArea(float x)
{
    cout << "The CircleArea = " << x << endl;
}
int main()
{
	float a;
	float b;
    ReadTraingleData(a,b);
    printCircleArea(CircleAreaByTraingle(a,b));

}