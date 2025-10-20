
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;


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


void AddArrayElement(int arr[100], int& arrLength)
{
    bool c;
    for (int i = 0; i < 100; i++)
    {
        cout << "Please Enter a number? ";
        cin >> arr[i];
        arrLength++;
        cout << "Do you want add more numbers ? [0]:No ,[1]:yes ? ";
        cin >> c;
        if (!c)
           return;
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
    int arr[100], arrLength=0;
    AddArrayElement(arr, arrLength);

    cout << "\nArray Length: " << arrLength << endl;
    
    PrintArray(arr, arrLength);
}