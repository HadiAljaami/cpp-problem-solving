#include <iostream>
using namespace std;
int ReadPositiveNumber(string message) {
    int num;
    do {
        cout << message << endl;
        cin >> num;
    } while (num <= 0);

    return num;
}

int ReverseNumber(int Number)
{
    int  Remainder = 0;
    int Number2 = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        Number2 = Number2 * 10 + Remainder;

    }
    return   Number2;
}
bool IsPalindromeNumber(int Number)
{

    return  Number == ReverseNumber(Number);

   /* int  Remainder = 0;
    int  Remainder2 = 0;
    bool isPalindrome = 1;
    int Number2 = ReverseNumber(Number);
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;

        Remainder2 = Number2 % 10;
        Number2 /= 10;

        if (Remainder2 != Remainder)
        {
            return 0;
        }

    }
    return isPalindrome;*/
}
//void PrintPalindrome(int Number)
//{
//    if (isPalindromeNumber(Number))
//    {
//        cout << "The Number is Palindrome " << endl;
//
//    }
//    else
//        cout << "The Number is Not Palindrome " << endl;
//}
int main()
{
    
    if (IsPalindromeNumber(ReadPositiveNumber("Please enter a positive number?")))  
        cout << "\nYes , it is a Palindrome number.\n"; 
    else        cout << "\nNo , it is NOT a Palindrome number.\n";
}