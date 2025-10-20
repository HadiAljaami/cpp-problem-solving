
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
enum enCharType{ Digit = 1,SmallLetter=2,CapitalLetter=3, SpecialCharacter=4};
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
        case enCharType::CapitalLetter : 
        {
            return char(RandomNumber(65, 90));
            break;
        } 
        case enCharType::SpecialCharacter :
        {
            return char(RandomNumber(33, 47)); 
            break; 
        } 
        case enCharType::Digit :
        { 
            return char(RandomNumber(48, 57)); 
            break; 
        }
    }

   /* char t;
    if (CharType == enCharType::Digit)
    return  t=   Random(48,57);

    else if(CharType== enCharType::SmallLetter)
    return   t= char(Random(97, 122));

    else if(CharType== enCharType::CapitalLetter)
    return t= char( Random(65, 90));

    else 
    return  t= char ( Random(33, 47));*/

}

int main()
{
    srand((unsigned)time(NULL));
    cout << GetRandomCharcter(enCharType::Digit) << endl;
    cout << GetRandomCharcter(enCharType::SmallLetter) << endl;
    cout << GetRandomCharcter(enCharType::CapitalLetter) << endl;
    cout << GetRandomCharcter(enCharType::SpecialCharacter) << endl;



}