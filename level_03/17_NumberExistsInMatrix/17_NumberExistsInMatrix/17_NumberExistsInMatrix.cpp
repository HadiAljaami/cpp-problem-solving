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

short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
	short NumberCount = 0; 
	for (short i = 0; i < Rows; i++) 
	{ 
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number) 
			{
				NumberCount++; 
			}; 
		} 
	}   
	return NumberCount; 
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


int main()
{
	int Matrix1[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
	int Number = 9;

	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(Matrix1, 3, 3);


	//Using Count is a slower method 
	/*if (CountNumberInMatrix(Matrix1, Number, 3, 3) > 0) 
		cout     <<     "\nYes it is there.\n"; 
	else    
		cout     <<     "\nNo: It's NOT there.\n";*/
	//This is faster mthod

	if (IsNumberInMatrix(Matrix1, Number, 3, 3))    
		cout     <<     "\nYes it is there.\n";
	else        
		cout     <<     "\nNo: It's NOT there.\n";


	system("pause>0");
}