
#include <iostream>
#include <time.h>
using namespace std;
int RandomNumbers(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRanomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

    for (int i = 0;i < arrLength;i++)
    {
        arr[i] = RandomNumbers(1, 100);
    }
}


int CountOdd(int arr[100], int arrLength)
{
    int counter = 0;
    for (int i = 0;i < arrLength;i++)
    {
        if (arr[i] %2 !=0)
        {
            counter++;
        }
    }
    return counter;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";     cout << "\n";
}
int main()
{
    // Seeds the random number generator in C++, called only once  
        
    srand((unsigned)time(NULL));
    int arr[100], arrLength ;

    FillArrayWithRanomNumbers(arr, arrLength);

    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    cout << "\nOdd Numbers count is: ";
    cout << CountOdd(arr, arrLength);

    return 0;
}

