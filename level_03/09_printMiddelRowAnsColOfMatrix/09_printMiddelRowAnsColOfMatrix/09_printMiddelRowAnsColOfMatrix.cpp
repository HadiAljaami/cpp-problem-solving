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

void PrintMiddelRowsOfMatrix(int arr[3][3], short Rows, short Cols)
{
	
	for (int i = 0;i < Cols;i++)
	{
		cout << setw(4) << arr[(Rows/2)][i] << "     ";

	}
	cout << endl;

	//short MiddleRow = Rows / 2; 
	//for (short j = 0; j < Cols; j++)
	//{ 
	//	printf(" %0*d   ", 2, arr[MiddleRow][j]);
	//}       
	//cout << "\n";
}

void PrintMiddelColOfMatrix(int arr[3][3], short Rows, short Cols)
{
	
	for (int i = 0;i < Cols;i++)
	{
		cout << setw(4) << arr[i][Cols/2] << "     ";

	}
	cout << endl;

	/*short MiddleCol = Cols / 2; 
	for (short j = 0; j < Rows; j++) 
	{ 
		printf(" %0*d   ", 2, arr[j][MiddleCol]); 
	}  
	cout << "\n";*/
}


int main()
{ //Seeds the random number generator in C++, called only once 
	srand((unsigned)time(NULL));
	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);
	

	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	cout << "\nMiddle Row of Matrix1 is:\n";
	PrintMiddelRowsOfMatrix(arr, 3, 3);
	cout << "\nMiddle Col of Matrix1 is:\n";
	PrintMiddelColOfMatrix(arr, 3, 3);


	system("pause>0");
}