#include <iostream>
using namespace std;

void readNumber(int& num1, int& num2)
{

	cout << "Enter num1:"; cin >> num1;
	cout << "Enter num2:"; cin >> num2;

}
void printRuselt(int num1, int num2)
{
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

}

void SwapTowNumber(int &num1, int &num2)
{
	int Temp = 0;
	Temp = num1;
	num1 = num2;
	num2 = Temp;

	//printRuselt(num1, num2);
}


int main()
{
	int num1, num2;
	readNumber(num1, num2);
	printRuselt(num1, num2);
	SwapTowNumber(num1, num2);
	printRuselt(num1, num2);
}