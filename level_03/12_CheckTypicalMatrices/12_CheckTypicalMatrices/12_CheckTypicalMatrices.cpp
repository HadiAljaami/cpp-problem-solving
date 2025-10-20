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

bool AreTypicalMatrices(int arr[3][3], int arr2[3][3], short Rows, short Cols)
{

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			
			if (arr[i][j] != arr2[i][j])
				return false;
			 
		}
	}
	return true;
}





int main()
{ //Seeds the random number generator in C++, called only once 
	srand((unsigned)time(NULL));
	int Matrix1[3][3];
	int Matrix2[3][3];


	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);

	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(Matrix2, 3, 3);

	if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
		cout << "\nYES: both martices are typical.";
	else
		cout << "\nNo: martices are NOT typical.";



	system("pause>0");
}