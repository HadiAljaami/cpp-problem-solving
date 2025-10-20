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

bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	short NumberCount = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
			{
				return true;
			};
		}
	}
	return false;
}
void PrintIntersectedNumber(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	int Number = 0;

	cout << endl;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Number = Matrix2[i][j];
			if (IsNumberInMatrix(Matrix1, Number, Rows, Cols))
				cout << setw(4) << Number << "     ";
			
		}
	}
}




int main()
{
	int Matrix1[3][3] = { {9,0,0},{1,9,0},{0,0,9} };
	int Matrix2[3][3] = { {9,1,2},{0,9,4},{4,1,10} };
	int Number = 9;

	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nIntersected Numbers are: \n\n";
	PrintIntersectedNumber(Matrix1, Matrix2,3,3);


	system("pause>0");
}