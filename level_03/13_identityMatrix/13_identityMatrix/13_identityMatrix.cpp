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

//bool IsIdentityMatrices(int arr[3][3], short Rows, short Cols)
//{
//	bool Diagonal = true;
//	bool OtherNum = true;
//
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//
//			if (i == j)
//			{
//				if (arr[i][j]!=1)
//				{
//					Diagonal = false;
//				}
//				
//			}
//			else
//			{
//				if (arr[i][j] != 0)
//				OtherNum = false;
//			}
//
//		}
//	}
//	return OtherNum&& Diagonal;
//}

bool IsIdentityMarix(int Matrix1[3][3], short Rows, short Cols) 
{ 
	//check Diagonal elements are 1 and rest elements are 0

	for (short i = 0; i < Rows; i++) 
	{   
		for (short j = 0; j < Cols; j++)
		{ 
			//check for diagonals element
			if (i == j && Matrix1[i][j] != 1) 
			{ return false;  
			} 
			//check for rest elements

			else if (i != j && Matrix1[i][j] != 0)  
			{ return false;    
			} 
		}   
	}   
	return true; 
} 

int main()
{ //Seeds the random number generator in C++, called only once 
	srand((unsigned)time(NULL));
	int Matrix1[3][3] = { {1,4,0},{0,1,0},{0,0,1} };
	
	/*FillMatrixWithRandomNumbers(Matrix1, 3, 3);*/
	
	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(Matrix1, 3, 3);


	if (IsIdentityMarix(Matrix1, 3, 3))
		cout << "\nYES: Matrix is identity.";
	else 
		cout << "\nNo: Matrix is NOT identity.";

	system("pause>0");
}