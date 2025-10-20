#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string message)
{
	int Number=0;
	do {
		cout << message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

void PrintReversedNumber(int Number)
{
	int Remainder = 0;
	int Sum = 0;
	int SumAllDigits = 0;


	for (int i = 1; Number > 0; (int)i++)
	{

		Remainder = Number % 10;

		Sum = Remainder * pow(10, ((to_string(Number)).length()) - 1);

		Number = Number / 10;

		cout << Sum << endl;
		cout << "-----------------" << endl;

		SumAllDigits = SumAllDigits + Sum;
	}

	cout << SumAllDigits << endl;

}

int main()
{
	PrintReversedNumber(ReadPositiveNumber("Please enter a positive number"));

	return 0;
}