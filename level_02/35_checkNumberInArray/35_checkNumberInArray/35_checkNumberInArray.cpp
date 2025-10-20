
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}



int ReadNumber()
{
    int num;
    do
    {
        cout << "\nPlease enter a number to search for?\n";
        cin >> num;
    } while (num <= 0);

    return num;
}


void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";     cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }

}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    /*This function will search for a number in array and return its index, or return -1 if it does not exists*/
    for (int i = 0; i < arrLength; i++)
    {

        if (arr[i] == Number)
            return i;
        // and return the index 
    }
    //if you reached here, this means the number is not foundreturn -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray( Number,  arr,  arrLength) != -1;
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
    //Seeds the random number generator in C++, called only once 
    srand((unsigned)time(NULL));
    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    int Number = ReadNumber();
    cout << "\nNumber you are looking for is: " << Number << endl;
    

    if (!IsNumberInArray(Number,arr,arrLength) == -1)
        cout << "The number is found ";
    else
    {
        cout << "The number is not found :-(\n";
       
    }
}