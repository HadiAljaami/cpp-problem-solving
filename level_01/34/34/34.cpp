#include <iostream>
using namespace std;

void ReadSalesAmount(int& s)
{

    cout << "Enter the sales amount : ";cin >> s;
}

float GetComissionPercentage(int s)
{
    if (s >= 1000000)
        return  0.01;

    else if (s >= 500000 )
        return 0.02;
    else if (s >= 100000 )
        return 0.03;

    else if (s >=50000 )
        return 0.05;

    else 
        return 0;

}

double commission(int s)
{
    double p = GetComissionPercentage(s);
  return s* p;
}
void printCommission(double c)
{
    cout << " is : " << c << endl;
}
int main()
{
    int S = 0;
    ReadSalesAmount(S);

    printCommission(GetComissionPercentage(S));
   
}
