#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

void PrintReversedNumber(int N)
{
    int x[7];
    int temp = 0;

    int length = 0;
  
    if (length == 1)
    {
        cout << N;
        return;
    }
    else  if  (N < 100)
    {
        x[0]=  N / 10;
        temp= N % 10;
        x[1] = temp;

        length = 2;
    }
    else if (N < 1000)
    {
        x[0]= N / 100;
        temp = N % 100;

        x[1] = temp / 10;
        temp= temp % 10;
        x[2] = temp;

        length = 3;
    }
    else if (N < 10000)
    {
        x[0] = N / 1000;
        temp = N % 1000;

        x[1] = temp / 100;
        temp = temp % 100;

        x[2] = temp / 10;
        temp = temp % 10;
        x[3] = temp;

        length = 4;
    }

    else if (N < 100000)
    {
        x[0] = N / 10000;
        temp = N % 10000;

        x[1] = temp / 1000;
        temp = temp % 1000;

        x[2] = temp / 100;
        temp = temp % 100;

        x[3] = temp / 10;
        temp = temp % 10;
        x[4] = temp;

        length = 5;
    }

    else if (N < 1000000)
    {
        x[0] = N / 100000;
        temp = N % 100000;

        x[1] = temp / 10000;
        temp = temp % 10000;

        x[2] = temp / 1000;
        temp = temp % 1000;

        x[3] = temp / 100;
        temp = temp % 100;

        x[4] = temp / 10;
        temp = temp % 10;
        x[5] = temp;

        length = 6;
    }

    else if (N < 10000000)
    {
        x[0] = N / 1000000;
        temp = N % 1000000;

        x[1] = temp / 100000;
        temp = temp % 100000;

        x[2] = temp / 10000;
        temp = temp % 10000;

        x[3] = temp / 1000;
        temp = temp % 1000;

        x[4] = temp / 100;
        temp = temp % 100;

        x[5] = temp / 10;
        temp = temp % 10;
        x[6] = temp;

        length = 7;
    }
    else
    {
    cout << "The Number is length\n";
    }

        for (int i = length-1;i >= 0;i--)
            cout << x[i];
}



int main()
{
    PrintReversedNumber(ReadPositiveNumber("Enter The Number"));
}