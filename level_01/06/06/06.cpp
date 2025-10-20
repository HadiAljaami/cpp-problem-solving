#include <iostream>
using namespace std;
struct Name
{
    string FirstName;
    string LastName;

};

Name ReadName()
{
   Name name;
    cout << "Enter first name? ";
    cin>>name.FirstName;
    cout << "Enter last name? ";
    cin >> name.LastName;

    return name;
}
string ConcatenateName(Name name,bool Reversed)
{
    string FullName = "";
    if (Reversed)
     FullName = name.LastName + " " +  name.FirstName;

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
    PrintFullName(ConcatenateName(ReadName(),false));
  

  ;
    return 0;
}