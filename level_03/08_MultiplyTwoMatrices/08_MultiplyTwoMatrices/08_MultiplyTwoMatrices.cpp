#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
	//Function to generate a random number 
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			/*printf(" %0*d   ", 2, arr[i][j]);*/

			cout << setw(4) << arr[i][j] << "     ";
		}
		cout << "\n";
	}
}


void MultiplyMatrix(int arr[3][3], int arr2[3][3],int arrSum[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows;i++)
	{
		for (int j = 0;j < Cols;j++)
		{
			arrSum[i][j] = arr[i][j] * arr2[i][j];
		}
    }
}

int main()
{ //Seeds the random number generator in C++, called only once 
	srand((unsigned)time(NULL));
	int arr[3][3];
	int arr2[3][3];

	int arrSum[3][3] = { 0 };

	FillMatrixWithRandomNumbers(arr, 3, 3);
	FillMatrixWithRandomNumbers(arr2, 3, 3);

	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(arr2, 3, 3);

	MultiplyMatrix(arr,arr2,arrSum, 3, 3);
	cout << "\nResults:\n";
	PrintMatrix(arrSum, 3, 3);

	system("pause>0");
}