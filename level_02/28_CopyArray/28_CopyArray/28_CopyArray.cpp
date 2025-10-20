
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int Random(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArrayWithRandomNumber(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
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
int SumArray(int arr[100], int arrLength)
{
    int Sum = 0;
    for (int i = 0;i < arrLength;i++)
    {
        Sum += arr[i];
    }

    return Sum;
}
void CopyArray(int arrSource[100],int arrDistination[100], int arrLength)
{
    for (int i = 0;i < arrLength;i++)
    {
        arrDistination[i] = arrSource[i];
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrLength;


    FillArrayWithRandomNumber(arr, arrLength);
   

    int arr2[100];    
    CopyArray(arr, arr2, arrLength); 
    cout << "\nArray 1 elements:\n";  
    PrintArray(arr, arrLength); 
    cout << "\nArray 2 elements after copy:\n";   
    PrintArray(arr2, arrLength);
    return 0;
}