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

//void PrintInvertedLetterPattern(int Number)
//{
//    char x = 64;
//
//    for (int i = Number;i > 0;i--)
//    {
//        for (int j = i;j > 0;j--)
//            cout << char(i + 64);
//        cout << endl;
//    }
//}

void PrintLetterPattern(int Number)
{
    cout << "\n";
    for (int i = 65 ; i <= 65 + Number - 1; i++)
    {
        for (int j = 1; j <= i-65 + 1 ; j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
}


int main()
{

    PrintLetterPattern(ReadPositiveNumber("Please enter a positive number?"));
}