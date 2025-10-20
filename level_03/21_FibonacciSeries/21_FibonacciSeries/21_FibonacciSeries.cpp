// 21_FibonacciSeries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//int ReadNumber()
//{
//    int N = 0;
//    cout << "Enter a number : "; cin >> N;
//    return N;
//}
//void Print()
//{
//    int L = ReadNumber();
//    int Num = 1;
//    int Num2 = 1;
//    int Temp = 0;
//    cout << Num2 << endl;
//    for (int i = 0;i < L-1;i++)
//    {  
//        Temp = Num;
//        cout << Num << endl;
//        Num = Num + Num2;
//        Num2 = Temp;
//
//    }
//}

void PrintFibonacciUsingLoop(short Number) 
{
    int FebNumber = 0; int Prev2 = 0, Prev1 = 1; 
    cout << "1   "; 
    for (short i = 2; i <= Number; ++i)
    {
        FebNumber = Prev1 + Prev2; 
        cout << FebNumber << "    ";    
        Prev2 = Prev1;     
        Prev1 = FebNumber;
    } 
}
int main()
{
    PrintFibonacciUsingLoop(10);
}