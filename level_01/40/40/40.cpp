#include <iostream>
using namespace std;
void ReadBillValue(float& BillValue)
{
    do
    {
        cout << "Enter The TotalBill : ";cin >> BillValue;
    } while (BillValue < 0);


}

float CalculateTheTotalBillServices(float TotalBill, int services = 0)
{
    float  s = TotalBill / 100 * services;

    return s;
}
float CalculateTheTotalBill_Tax(float TotalBill, int tax = 0)
{

    float t = TotalBill / 100 * tax;
    return t;
}
void PrintTheTotalBillServicesTax(float BillValue)
{
    cout << "The  BillValue:" << BillValue;
}
int main()
{
    float BillValue = 0;
    ReadBillValue(BillValue);
    BillValue = BillValue + CalculateTheTotalBillServices(BillValue, 10) +
        CalculateTheTotalBill_Tax(BillValue, 16);

    PrintTheTotalBillServicesTax(BillValue);

} 