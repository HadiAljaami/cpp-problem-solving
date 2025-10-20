
#include <iostream>
#include <iomanip>
using namespace std;
void PrintMultiplicationTable()
{
    cout << "     1   2   3   4   5   6   7   8   9   10 " << endl;
    cout << "_____________________________________________" << endl;
    for (int i = 1; i <= 10;i++)
    {
        cout <<setw(2)<< i << " |" << setw(2);
        for (int j = 1; j <= 10; j++)
        {
            cout <<i * j << setw(4);
        }
        cout << "\n";

    }

}
int main()
{
    PrintMultiplicationTable();
}

