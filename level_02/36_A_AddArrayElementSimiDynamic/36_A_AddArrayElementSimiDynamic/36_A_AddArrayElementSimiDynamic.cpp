
#include <iostream>

using namespace std;


int ReadNumber()
{
    int num;
    do
    {
        cout << "\nPlease enter a number to add ?";
        cin >> num;
    } while (num <= 0);

    return num;
}


void AddArrayElement(int Number,int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength-1] = Number;
}
void InputUserNumberInArray(int arr[100], int &arrLength)
{
    bool AddMore = true;
    do
    {
        AddArrayElement(ReadNumber(), arr, arrLength);
        cout << "Do you want to add more number [0]:No , [1]:yes ? ";
        cin >> AddMore;

    } while (AddMore);
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
    InputUserNumberInArray(arr, arrLength);

    PrintArray(arr, arrLength);
}