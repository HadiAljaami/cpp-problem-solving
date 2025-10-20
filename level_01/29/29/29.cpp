#include <iostream>
using namespace std;
enum enOddOrEven { odd=1, even=2};
int ReadNumber()
{
    int num;
    cout << "Enter the num : ";cin >> num;
    return num;
}
enOddOrEven CheckOddOrEven(int N)
{
    if(N % 2 == 0)
    return enOddOrEven::even ;
    else
    return enOddOrEven::odd;

}
int sumEvenNumber(int n)
{
    int sum = 0;

    for (int i = 1;i <= n;i++)
    {
        if (CheckOddOrEven(i) == enOddOrEven::even)
            sum += i;
    }
    return sum;
 }
void printSum  (int sum)
{
    cout << "sum : " << sum << endl;
}
int main()
{
    printSum(sumEvenNumber(ReadNumber()));
}
