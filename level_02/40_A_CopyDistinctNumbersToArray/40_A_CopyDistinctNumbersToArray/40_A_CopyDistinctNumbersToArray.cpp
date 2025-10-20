
#include <iostream>
#include <time.h>

using namespace std;

void FillArray(int arr[100], int& arrLength) 
{
    arrLength = 10;
    arr[0] = 10; 
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}


short FindNumberPositionInArray(int Number, int arr[100], int arrLength)  
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number) return i;//return the index 
    } 
    //if you reached here, this means the number is not found 
    return -1; 
}
bool IsNumberInArray(int Number, int arr[100], int arrLength)
{ 
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}



void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
{ 
    for (int i = 0; i < SourceLength; i++) 
    { 
        if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
        {
            AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    } 
}


void PrintArray(int arr[100], int Length)
{


    for (int i = 0;i < Length;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength = 0;

    int arr2[100], arr2Length = 0;

    FillArray(arr, arrLength);
    CopyDistinctNumbersToArray(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);
    cout << "\nArray 2 elements after copy:\n";
    PrintArray(arr2, arr2Length);

    return 0;
}

