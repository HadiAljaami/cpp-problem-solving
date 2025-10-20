//by Hadi Ameen

#include <iostream>
using namespace std;
struct stNumbers
{
	int num1;
	int num2;
	int num3;


};

stNumbers ReadNumbers()
{
	stNumbers Number;

	cout << "Enter number 1 : ";cin >> Number.num1;
	cout << "Enter number 2 : ";cin >> Number.num2;
	cout << "Enter number 3 : ";cin >> Number.num3;
	return Number;
}

int SumNumber(stNumbers Number)
{
	int sum = 0;
	sum = Number.num1 + Number.num2 + Number.num3;
	return sum;
}

void printNumber(int sum)
{

	cout <<"The result of sum : " <<  sum << endl;

}

int main()
{
	printNumber(SumNumber(ReadNumbers()));
}
