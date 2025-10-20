#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << "\n";
	}
}

void FillMatrixWithOrderedNumber(int arr[3][3], short Cols, short Rows)
{
	int Counter = 0;
	for (int R = 0;R< Rows;R++)
	{
		for (int C = 0;C<Cols;C++)
		{
			arr[R][C] = ++Counter;
		}
	}
}



int main()
{ 
	int arr[3][3];

	FillMatrixWithOrderedNumber(arr, 3, 3);

	cout << "\nThe following is a 3x3 ordered matrix:\n";
	PrintMatrix(arr, 3, 3);

	system("pause>0");
}