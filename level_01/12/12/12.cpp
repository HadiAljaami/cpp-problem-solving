#include <iostream>
using namespace std;
struct stNumbers
{
	int num1;
	int num2;
};
stNumbers readNumber()
{
	stNumbers 	 Numbers;
	cout << "Enter num1:"; cin >> Numbers.num1;
	cout << "Enter num2:"; cin >> Numbers.num2;
	return 	Numbers;
}

int Check(stNumbers Numbers)
{
	if (Numbers.num1 > Numbers.num2)
		return 	Numbers.num1;

	else 
		return 	Numbers.num2;

}

void printNumber(int maxNumber)
{
	cout << "The max number is " << maxNumber << endl;

}
int main()
{
	printNumber(Check(readNumber()));
}
