#include<iostream>
//#include <cstdlib>
#include <time.h>

using namespace std;
int ReadPositiveNumber(string Message)
{
	int Number = 0; do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}
int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}


void FillArrayWithRandomNumber(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = RandomNumber(1,100);
}

void CopyArrayInReverseOrder(int arr[100], int arr2[100],int Length)
{
	for (int i =0;i <Length;i++)
	{
		arr2[i] = arr[Length - 1 - i];
	}

}


void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{ //Seeds the random number generator in C++, called only once  
	srand((unsigned)time(NULL));
	int arr[100];
	int arrLength = ReadPositiveNumber("\nEnter number of elements : \n");
	FillArrayWithRandomNumber(arr, arrLength);

	

	int arr2[100];
	CopyArrayInReverseOrder(arr, arr2, arrLength);
	cout << "Array 1 : \n";
	PrintArray(arr, arrLength);

	cout << "Array 2 : \n";
	PrintArray(arr2, arrLength);

	return 0;
}
