#include <iostream>
using namespace std;

void readNumber(int &num1,int& num2)
{
	
	cout << "Enter num1:"; cin >> num1;
	cout << "Enter num2:"; cin >> num2;
}

int maxOfTowNumbers(int num1, int num2)
{
	if (num1 > num2)
		return 	num1;

	else
		return 	num2;

}

void printRuselt(int maxNumber)
{
	cout << "The max number is " << maxNumber << endl;

}
int main()
{
	int num1, num2;
	readNumber(num1, num2);

	printRuselt(maxOfTowNumbers(num1, num2));
}
