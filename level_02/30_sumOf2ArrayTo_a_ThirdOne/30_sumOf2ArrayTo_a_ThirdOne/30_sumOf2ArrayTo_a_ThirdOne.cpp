
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int Random(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int ReadPositiveNumber(string Message)
{ 
    int Number = 0; 
    do 
    { 
        cout << Message << endl;  
        cin >> Number; 
    } 
    while (Number <= 0);
    return Number;
}

void FillArrayWithRandomNumber(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = Random(1, 100);
    }
    cout << endl;
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";     cout << "\n";

}

void SumOf2Arrays(int arrSource[100], int arrDistination[100], int arrSum[100], int arrLength)
{
    for (int i = 0;i < arrLength;i++)
    {
        arrSum [i]= arrDistination[i] + arrSource[i];
    
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arr2[100], arrSum[100] ,arrLength;

    arrLength = ReadPositiveNumber("How many elements ?\n");

    FillArrayWithRandomNumber(arr, arrLength);
    FillArrayWithRandomNumber(arr2, arrLength);

    PrintArray(arr, arrLength);
    PrintArray(arr2, arrLength);

    SumOf2Arrays(arr, arr2, arrSum,arrLength );
    PrintArray(arrSum, arrLength);



    return 0;
}