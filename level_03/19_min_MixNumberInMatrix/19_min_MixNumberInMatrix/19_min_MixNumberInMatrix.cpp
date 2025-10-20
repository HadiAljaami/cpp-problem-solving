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
			/*printf(" %0*d   ", 2, arr[i][j]);*/

			cout << setw(4) << arr[i][j] << "     ";
		}
		cout << "\n";
	}
}


int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int Max = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] > Max)
				Max=Matrix1[i][j];
		}
	}
	return Max;
}

int MinNumberInMatrix(int Matrix1[3][3],  short Rows, short Cols)
{
	int Min = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] < Min)
				Min = Matrix1[i][j];
		}
	}
	return Min;
}




int main()
{
	int Matrix1[3][3] = { {9,0,0},{1,9,0},{0,0,9} };
	
	int Number = 9;

	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMinimum Number is: "; 
	cout << MinNumberInMatrix(Matrix1, 3, 3); 

	cout << "\n\nMax Number is: "; 
	cout << MaxNumberInMatrix(Matrix1, 3, 3);

	system("pause>0");
}