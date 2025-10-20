/*write program to read a number and print the text of that number
Enter a Number>5843
Five Thousands Eight Hundreds Forty Three
 
Enter a Number> 5843
Five Thousands Eight Hundreds Forty Three
*/

#include <iostream>
#include <string>
using namespace std;
enum eNum
{
    
};
string PrintTextOfNumber(int Number)
{
    string numAsString = to_string(Number);
    int size = numAsString.length();
    string TextNum = "";

    for (int i = size;i>0;i--)
    {
        if(i<=1)
        { 
            switch (numAsString[size])
            {
            case '1':TextNum += " one"; break;
            case '2':TextNum += " two";    break;
            case '3':TextNum += " three";    break;
            case '4':TextNum += " four";    break;
            case '5':TextNum += " five";   break;
            case '6':TextNum += " six";    break;
            case '7':TextNum += " seven";    break;
            case '8':TextNum += " eight";    break;
            case '9':TextNum += " nine";    break;
         

            default:
                break;
            }
            TextNum += "";
        }
        else if(i<=2)
        {
            char c = numAsString[size - 1];
            int num = c - '0';

            if (num<20)
            {

            }
               else
               {

               }
        }
        else if (i <=3)
        {

        }
        else if (i < 20)
        {

        }
        else if (i < 20)
        {

        }
        else if (i < 20)
        {

        }
        else if (i < 20)
        {

        }
    }
}
int main()
{
    
    return 0;
}

