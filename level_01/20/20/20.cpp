#include <iostream>
using namespace std;

float ReadSquareSide()
{
	float A;
	cout << "Enter SquareSide ?"; cin >> A;
	return A;
}
float printArea(float Area)
{
	cout << "The Circle Area = " << Area << endl;
	return Area;
}

float CircleAreaInscribedInSquare(float A)
{
	const float Pi = 3.141592;
	float Area = (pow(A, 2) * Pi) / 4;
	return Area;
}


int main()
{

	printArea(CircleAreaInscribedInSquare(ReadSquareSide()));

}