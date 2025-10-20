#include <iostream>
using namespace std;
void ReadTotalBillAndCashPaid(float& TotalBill,float & CashPaid)
{
    do
    {
        cout << "Enter The TotalBill : ";cin >> TotalBill;
    }
    while (TotalBill<0);
    do
    {
        cout << "Enter The CashPaid : ";cin >> CashPaid;
    } while (CashPaid < 0);
        
}

float CalculateTheRemainder(float TotalBill, float CashPaid)
{
    float Remainder = CashPaid - TotalBill;
    return  Remainder;
}
void PrintTheRemainder(float Remainder)
{
    cout << "The Remainder :" << Remainder;
}
int main()
{
    float TotalBill = 0;float CashPaid = 0;
    ReadTotalBillAndCashPaid(TotalBill, CashPaid);
    PrintTheRemainder(CalculateTheRemainder(TotalBill, CashPaid));

}