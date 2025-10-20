#include <iostream>
using namespace std;

float ReadDiameter()
{
	float Diameter;
	cout << "Enter The Diameter:"; cin >> Diameter;
	return Diameter;
}
float printArea(float Area)
{
	cout << "The Circle Area = " << Area << endl;
	return Area;
}

float CircleAreaByDiameter(float D)
{
	const float Pi = 3.141592;
	float Area = (pow(D, 2) * Pi) / 4;
	return Area;
}


int main()
{
	
	printArea(CircleAreaByDiameter(ReadDiameter()));

}