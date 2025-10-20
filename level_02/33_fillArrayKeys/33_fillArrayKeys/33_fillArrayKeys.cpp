
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

char GetRandomCharacter(enCharType CharType)
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
    default:
        return 0;
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
string GenerateWord(enCharType CharType, short Length)
{
    string Word;
    for (int i = 1; i <= Length; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}

string GenerateKey()
{
    string Key = "";
    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
    return Key;
}
//void GenerateKeys(short NumberOfKeys)
//{
//    
//    for (int i = 1; i <= NumberOfKeys; i++)
//    {
//        cout << "Key [" << i << "] : "; cout << GenerateKey() << endl;
//    }
//
//}

void FillArrayWithKeys(short NumberOfKeys, string arr[100])
{

    for (int i = 0; i < NumberOfKeys; i++)
    {
        arr[i] = GenerateKey();
    }

}


void PrintArray(short NumberOfKeys, string arr[100])
{

    for (int i = 0; i < NumberOfKeys; i++)
    {
        cout << "Array [" << i  << "] : " <<
            arr[i] << endl;
    }

}
int main()
{
    //Seeds the random number generator in C++, called only once 
    srand((unsigned)time(NULL));
    string arr[100];
    int Number = ReadPositiveNumber("Pleaes enter how many keys to generate? \n ");
   // GenerateKeys(ReadPositiveNumber("Pleaes enter how many keys to generate? \n "));
    FillArrayWithKeys(Number,arr);
    PrintArray(Number, arr);
}