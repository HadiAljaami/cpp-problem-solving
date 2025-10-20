#include <iostream>
using namespace std;

void ReadNumber(float& A, float& B)
{

	cout << "Enter Rectangle Diagonal:"; cin >> A;
	cout << "Enter Rectangle Side:"; cin >> B;

}
void printRuselt(float Ruselt)
{
	cout << "The RectangleArea = " << Ruselt << endl;


}

float RectangleAreaBySideAndDiagonal(float& D, float& S)
{

	return (S*sqrt(pow(D,2)- pow(S, 2)));

}


int main()
{
	float Diagonal, Side;
	ReadNumber(Diagonal, Side);
	printRuselt(RectangleAreaBySideAndDiagonal(Diagonal, Side));

}