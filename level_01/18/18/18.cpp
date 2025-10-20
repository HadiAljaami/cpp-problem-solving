#include <iostream>
using namespace std;

void ReadRadious(float& R)
{
	cout << "Enter The Radious:"; cin >> R;
}
void printRuselt(float Ruselt)
{
	cout << "The Circle Area = " << Ruselt << endl;

}

float CircleArea(float R )
{
	const float Pi = 3.141592;
	return (Pi*pow(R,2));
}


int main()
{
	float Radious;
	ReadRadious(Radious);
	printRuselt(CircleArea(Radious));

}