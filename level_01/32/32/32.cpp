#include <iostream>
using namespace std;

void ReadNumber(float &n, int &p)
{
   
    cout << "Enter the num : ";cin >> n;
    cout << "Enter the pow : ";cin >> p;
   
}

double Pow(float n,int p)
{
    double r = 1;
    if (n == 0)
    {
        return 0;
    }
    else if (p == 0)
    {
        return 1;
    }
    else
    {
       
        for (int i = 1;i <= p;i++)
        {
            r = n * r;
        }
    }
    return r;
}
void printPow(float r)
{
    cout << "the pow is : " << r << endl;
}
int main()
{
    float n = 0;int p = 1;
    ReadNumber(n, p);
     printPow(Pow(n,p));
}
