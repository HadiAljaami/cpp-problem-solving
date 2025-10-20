
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}



int ReadPositiveNumber(string message)
{
    int num;
    do {
        cout << message << endl;
        cin >> num;
    } while (num <= 0);

    return num;
}


void FillArrayWithRandomNumber(short Lemgth, int arr[100])
{

    for (int i = 0; i < Lemgth; i++)
    {
        arr[i] = RandomNumber(1,100);
    }

}

int SearchElementInArray(short Lemgth, int arr[100], int Element)
{

   for (int i = 0;i < Lemgth;i++)
   {
       if (arr[i] == Element)
           return i;      
   }
   return -1;
}

void PrintArray(int NumberPosition,int Element)
{
    if (NumberPosition == -1)
        cout << "The Element don't fond\n";

    else
    {
        cout << "The number found at position: "; 
        cout << NumberPosition << endl; 
        cout << "The number found its order  : ";  
        cout << NumberPosition + 1 << endl;
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
    //Seeds the random number generator in C++, called only once 
    srand((unsigned)time(NULL));
  int arr[100];
    int Number = ReadPositiveNumber("Pleaes enter how many Numbers to generate? \n ");
    FillArrayWithRandomNumber(Number, arr);
    PrintArray(arr, Number);
   int Element = ReadPositiveNumber("Pleaes enter how many Numbers to generate? \n ");

    PrintArray(SearchElementInArray(Number, arr, Element), Element);
}