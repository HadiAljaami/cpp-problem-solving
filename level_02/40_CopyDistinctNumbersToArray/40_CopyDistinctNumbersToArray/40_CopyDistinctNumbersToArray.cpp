
#include <iostream>
#include <time.h>

using namespace std;

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


void FillArrayWithUserNumbers(int arr[100], int& arrLength)
{
    bool c = true;
   
    do
    {     //hard coded
        AddArrayElement(ReadNumber("Enter number of elements:\n"), arr, arrLength);
        cout << "\n ?\n";
        cin >> c;
           
    } while (c);
}

bool IsDistinct(int arrSource, int arrDestination[100], int& arrDestinationLength)
{
    for (int i = 0;i < arrDestinationLength;i++)
    {
        if (arrDestination[i] == arrSource)
            return false;

    }
    return true;
}

void CopyDistinctNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
        if (IsDistinct(arrSource[i],arrDestination, arrDestinationLength))
        {
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
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



    FillArrayWithUserNumbers(arr, arrLength);


    CopyDistinctNumbers(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);
    cout << "\nArray 2 elements after copy:\n";
    PrintArray(arr2, arr2Length);

    return 0;
}

