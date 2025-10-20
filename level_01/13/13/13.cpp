#include <iostream>
using namespace std;

void readNumber(int& num1, int& num2 , int &num3)
{

	cout << "Enter num1:"; cin >> num1;
	cout << "Enter num2:"; cin >> num2;
	cout << "Enter num3:"; cin >> num3;
}

int maxOfTowNumbers(int num1, int num2,int & num3)
{
	if (num1 > num2)
	{
		if (num1 > num3)
			return 	num1;

		else
			return 	num3;

	}
	else
	{
		if (num2 > num3)
			return 	num2;

		else
			return 	num3;

	}
		

}

void printRuselt(int maxNumber)
{
	cout << "The max number is " << maxNumber << endl;

}
int main()
{
	int num1, num2, num3;;
	readNumber(num1, num2, num3);

	printRuselt(maxOfTowNumbers(num1, num2, num3));
}
