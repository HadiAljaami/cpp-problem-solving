
#include <iostream>
using namespace std;
enum enNumberType { odd = 1,even=2 };
int readNumuber() {

    int Num;
    cout << "Enter a Number?" << endl;
    cin >> Num;
    return Num;
}
enNumberType CheckNumberType(int Num)
{
    int Ruselt = Num % 2;
    if (Ruselt == 0)
        return enNumberType::even;
    else
    {
        return enNumberType::odd;
    }
       
}

void printNumberType(enNumberType NumberType)
{
    if (NumberType == enNumberType::even)
        cout << "\nNumber is Even\n" << endl;
    else
        cout << "\nNumber is Odd\n" << endl;
}
int main()                   
{
     printNumberType(CheckNumberType(readNumuber()));
}


