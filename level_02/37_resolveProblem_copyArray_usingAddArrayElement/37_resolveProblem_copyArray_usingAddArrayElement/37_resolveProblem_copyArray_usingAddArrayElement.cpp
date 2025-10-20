
#include <iostream>
#include <time.h>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To-From+1 )+ From;
}
int ReadNumber(string Message)
{
    int num;
    do
    {
        cout << Message;
        cin >> num;
    } while (num <= 0);

    return num;
}


void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";  
    cin >> arrLength; 
    for (int i = 0; i < arrLength; i++) arr[i] = RandomNumber(1, 100);
}

void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++) 
        AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);

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
    srand((unsigned) time(NULL));

    int arr[100], arrLength = 0;

    int arr2[100], arr2Length = 0;


    
    FillArrayWithRandomNumbers(arr,arrLength);
 

    CopyArrayUsingAddArrayElement(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements:\n"; 
    PrintArray(arr, arrLength);
    cout << "\nArray 2 elements after copy:\n"; 
    PrintArray(arr2, arr2Length);
    
    return 0;
}
    
