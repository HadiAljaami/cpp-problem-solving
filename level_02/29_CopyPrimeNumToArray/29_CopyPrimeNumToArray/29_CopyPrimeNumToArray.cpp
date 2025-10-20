
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
enum enPrimNotPrime{ Prime = 1, NotPrime = 2 };

enPrimNotPrime CheckPrime(int Number) 
{ 
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++) 
    {
        if (Number % Counter == 0) 
            return enPrimNotPrime::NotPrime;
    }
    return enPrimNotPrime::Prime; 

}

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


void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Lenght)
{ 
    int Counter = 0; 
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime) 
        { 
            arrDestination[Counter] = arrSource[i]; 
            Counter++;
        } 
    }
    arr2Lenght = --Counter; 
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrLength;


    FillArrayWithRandomNumber(arr, arrLength);


    int arr2[100];
    int arr2Length;
    CopyOnlyPrimeNumbers(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    cout << "\nPrime Numbers in Array2:\n";
    PrintArray(arr2, arr2Length);

   
    return 0;
}