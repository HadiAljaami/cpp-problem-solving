
#include <iostream>
using namespace std;

float MyRound(float Number)
{
	int N = int(Number);
	float Temp = Number - N;

	if (Temp >= 0.5)
		return N + 1;

	else if (Temp >= 0.0)
		return N;

	else if (Temp <= -0.5)
		return N -1 ;

	else
		return N;
}
float  ReadNumber()
{
	float Number;
	cout << "Please enter a number?";
	cin >> Number;

	return Number;
} int main()
{
	float Number = ReadNumber();
	cout << "My round Result : " << MyRound(Number) << endl;

	cout << "C++ roun Result: " << round(Number) << endl;
	return 0;
}

