#include <iostream>
#include <time.h>
#include<iomanip>
using namespace std;

int Random(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void PrintTheMatrix(int Matrix[3][3], short Columns, short Rows)
{
    
    for (short i = 0;i < Rows;i++)
    {
        for (short j = 0;j < Columns;j++)
        {
            cout <<setw(3) << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void FillMatrixArrayWithRandomNumbers(int Matrix[3][3], short Columns, short Rows)
{
        for (short i = 0;i < Rows;i++)
        {
            for (short j = 0;j < Columns;j++)
            {
                Matrix[i][j]=Random(1,100);
            }   
        }
}
int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3];
    FillMatrixArrayWithRandomNumbers(Matrix, 3, 3);

    cout << "The follwoing is a 3x3 Matrix :\n";
    PrintTheMatrix(Matrix, 3, 3);
   
}