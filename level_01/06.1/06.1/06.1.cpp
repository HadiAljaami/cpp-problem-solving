#include <iostream>
using namespace std;
struct Name
{
    string FirstName;
    string LastName;
    bool   Reversed;
};

Name ReadName()
{
    Name name;
    cout << "Enter first name? ";
    cin >> name.FirstName;
    cout << "Enter last name? ";
    cin >> name.LastName;
    cout << "In American, enter 1, in Arabic, enter 0 : ";
    cin >> name.Reversed;

    return name;
}
string ConcatenateName(Name name)
{
    string FullName = "";
    if (name.Reversed)
        FullName = name.LastName + " " + name.FirstName;

    else
        FullName = name.FirstName + " " + name.LastName;

    return FullName;
}
void PrintFullName(string FullName)
{
    cout << FullName << endl;
}
int main()
{
    PrintFullName(ConcatenateName(ReadName()));


    ;
    return 0;
}