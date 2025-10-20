#include <iostream>
#include <string>
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

int ReadArray(int N)
{
    string Num="";
    int Temp = 0;
    for (int i = 0; i < N;i++)
    {
        cout << "Element[" << i + 1 << "] : ";cin>> Temp;
        Num = Num + to_string(Temp);
    }
    return stoi( Num);
}

void PrintElement(int N)
{
    cout << N << endl;
}

void CheckNumber(int Number,int NumToSearch)
{
    int R=0;
    int C = 0;
    while (Number >0)
    {
        R = Number % 10;
        Number = Number / 10;
        if (NumToSearch == R)
            C++;
    }
    cout << NumToSearch << " id repeated " << C << " Time(s)";
}
int main()
{
    int NumberOfElement = ReadPositiveNumber("input ");
    int Num = ReadArray(NumberOfElement);
    PrintElement(Num);
    CheckNumber(Num, ReadPositiveNumber("Enter The Number to you check: "));

}