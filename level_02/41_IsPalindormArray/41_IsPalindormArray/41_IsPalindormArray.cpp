
#include <iostream>
#include <time.h>

using namespace std;

void FillArray(int arr[100], int& arrLength)
{
    arrLength = 11;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 70;
    arr[4] = 70;
    arr[5] =  5;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 10;
    arr[9] = 10;
    arr[10] = 10;
}

//void AddArrayElement(int Number, int arr[100], int& arrLength)
//{
//    arrLength++;
//    arr[arrLength - 1] = Number;
//}

bool IspalindromArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        if (arr[i] != arr[Length - 1 - i])
        {
            return false;
        }   
    }
    return true;
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


    int arr[100], arrLength = 0;
    FillArray(arr, arrLength);
    PrintArray(arr, arrLength);

    if (IspalindromArray(arr, arrLength))
        cout << "The array is palindrom\n";
    else
        cout << "The array isn't palindrom\n";

    return 0;
}

