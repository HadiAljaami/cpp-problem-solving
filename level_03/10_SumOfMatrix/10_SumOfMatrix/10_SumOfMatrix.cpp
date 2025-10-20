#include<iostream>
#include<string>
#include<iomanip>
//09_printMiddelRowAnsColOfMatrix.cpp :
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

int SumOfMatrix(int arr[3][3], short Rows, short Cols)
{
	int Sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Sum+=arr[i][j] ;
		}
	}
	return Sum;
}


int main()
{ //Seeds the random number generator in C++, called only once 
	srand((unsigned)time(NULL));
	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nSum of Matrix1 is: " << 
		SumOfMatrix(Matrix1, 3, 3);


	system("pause>0");
}