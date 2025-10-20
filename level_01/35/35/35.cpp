#include <iostream>
using namespace std;
struct stPiggyBankContenet
{
    int Pennies, Nickels, Dimes, Quarters, Dollars;
};
stPiggyBankContenet ReadPiggyBankContenet()
{
    stPiggyBankContenet PiggyBankContenet;
    cout << "Enter a Total pinnies : "; cin >> PiggyBankContenet.Pennies;
    cout << "Enter a Total Nickels : "; cin >> PiggyBankContenet.Nickels;
    cout << "Enter a Total Dimes : "; cin >> PiggyBankContenet.Dimes;
    cout << "Enter a Total Quarters : "; cin >> PiggyBankContenet.Quarters;
    cout << "Enter a Total Dollars : "; cin >> PiggyBankContenet.Dollars;
    return   PiggyBankContenet;
}
int CalculataTotalPennies(stPiggyBankContenet PiggyBankContenet)
{
    int TotalPennias = 0;
    TotalPennias = PiggyBankContenet.Pennies +
        PiggyBankContenet.Nickels * 5 +
        PiggyBankContenet.Dimes * 10 +
        PiggyBankContenet.Quarters * 25 +
        PiggyBankContenet.Dollars * 100;

    return TotalPennias;

}
int main()
{
    int TotalPennias = CalculataTotalPennies(ReadPiggyBankContenet());
    cout << "Total pennias " << TotalPennias << endl;
    cout << "Total Dollars " << (float)TotalPennias/100 << endl;

}