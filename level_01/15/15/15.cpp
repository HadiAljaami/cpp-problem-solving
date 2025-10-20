#include <iostream>
using namespace std;

void ReadNumber(float& A, float& B)
{

	cout << "Enter Rectangle Width:"; cin >> A;
	cout << "Enter Rectangle Length:"; cin >> B;

}
void printRuselt(float Ruselt)
{
	cout << "The RectangleArea = " << Ruselt << endl;
	

}

float CalculateRectangleArea(float& A, float& B)
{
	
	return A * B;
	
}


int main()
{
	float A, B;
	ReadNumber(A, B);
	printRuselt(CalculateRectangleArea( A,  B));
	
}