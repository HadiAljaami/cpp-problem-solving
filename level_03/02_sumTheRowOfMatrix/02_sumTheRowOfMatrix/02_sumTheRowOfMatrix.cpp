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
            cout << setw(3) << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
void SumTheRowOfMatrix(int Matrix[3][3], short Columns, short Rows,int Sum[3])
{

    for (short i = 0;i < Rows;i++)
    {
        for (short j = 0;j < Columns;j++)
        {
           Sum[i]+=  Matrix[i][j] ;
        }
       
    }
  
}

void PrintTheSumTheRowOfMatrix(int Sum[3], int Rows)
{
    for (short i = 0;i < Rows;i++)
    {
        cout << "Row[" << i+1 << "] = " << Sum[i] << "\n";
    }
}

void FillMatrixArrayWithRandomNumbers(int Matrix[3][3], short Columns, short Rows)
{
    for (short i = 0;i < Rows;i++)
    {
        for (short j = 0;j < Columns;j++)
        {
            Matrix[i][j] = Random(1, 100);
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3];
    int Sum[3] = { 0 };

    FillMatrixArrayWithRandomNumbers(Matrix, 3, 3);
    SumTheRowOfMatrix(Matrix, 3, 3, Sum);

    PrintTheMatrix(Matrix, 3, 3);
    cout << endl;

    cout << "The follwoing are the sum of each rows of the Matrix :\n";
    PrintTheSumTheRowOfMatrix(Sum, 3);

 
   

}