
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
enum enCharType { Digit = 1, SmallLetter = 2, CapitalLetter = 3, SpecialCharacter = 4 };

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

char GetRandomCharcter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
    {
        return char(RandomNumber(97, 122));
        break;
    }
    case enCharType::CapitalLetter:
    {
        return char(RandomNumber(65, 90));
        break;
    }
    case enCharType::SpecialCharacter:
    {
        return char(RandomNumber(33, 47));
        break;
    }
    case enCharType::Digit:
    {
        return char(RandomNumber(48, 57));
        break;
    }
    }

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

void GenerateKeys(int Number)
{
    for (int i = 1;i <= Number;i++)
    {
        for (int k = 1;k <= 4;k++)
        {
            for (int j = 1;j <= 4;j++)
            {
                cout << GetRandomCharcter(enCharType::CapitalLetter);
            }
            if (k == 4)
                break;
            cout << "-";
        }
        cout << endl;
       
    }

}

int main()
{
    srand((unsigned)time(NULL));

    GenerateKeys( ReadPositiveNumber("Enter ?"));

}