
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
int MaxNumberInArray(int arr[100], int arrLength)
{
    int Max = 0;
    for (int i = 0;i < arrLength;i++)
    {
        if (arr[i] > Max)
            Max = arr[i];
    }

    return Max;
 }

int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrLength;


    FillArrayWithRandomNumber(arr, arrLength);
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);
  cout << "The Max element is " << MaxNumberInArray(arr, arrLength);

    return 0;
}