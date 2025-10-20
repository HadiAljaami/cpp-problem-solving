#include <iostream>
using namespace std;
int ReadPositiveNumber(string message)
{
    int num;
    do {
        cout << message << endl;
        cin >> num;
    } while (num <= 0);

    return num;
}

void PrintInvertedPatternNumber(int Number)
{
    for (int i =1;i <= Number;i++)
    {

        for (int j = 1;j <= i;j++)
            cout << i;
        cout << endl;
    }
}


int main()
{

    PrintInvertedPatternNumber(ReadPositiveNumber("Please enter a positive number?"));
}