#include <iostream>
using namespace std;

void ReadNumber(float& B, float& H)
{

	cout << "Enter Triangle Base :"; cin >> B;
	cout << "Enter Triangle Hight :"; cin >> H;

}
void printRuselt(float Area)
{
	cout << "The Triangle Area = " << Area << endl;


}

float TriangleArea(float& B, float& H)
{

	return ((B/2)*H);

}


int main()
{
	float Base, Hight;
	ReadNumber(Base, Hight);
	printRuselt(TriangleArea(Base, Hight));

}