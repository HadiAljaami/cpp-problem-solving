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


bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
{

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols/2; j++)
		{
			if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
				return false;
		}
	
	}
	return true;
}



int main()
{
	/*int Matrix1[3][3] = { {9,0,0},{1,9,0},{0,0,9} };*/
	int Matrix1[3][3] = { {9,1,9},{1,5,1},{0,3,0} };
	int Number = 9;

	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsPalindromeMatrix(Matrix1, 3, 3)) 
	{ 
		cout << "\nYes: Matrix is Palindrome\n"; 
	}
	else     
		cout << "\nNo: Matrix is NOT Palindrome\n";

	system("pause>0");
}