#include <iostream>
using namespace std;
bool IsPunct(char C)
{
    char Punctuations[] = { '\'','"','/','+','-','=','_',')','(','*','&','^','%','$','#','@','!','}','{','[',']','/','?','>','.',',','<','~' ,';',':'};
    const auto n = std::extent<decltype(Punctuations) >::value;
    

    for (int i = 0;i<n;i++)
    {
        if (C == Punctuations[i])
        {
            return true;
        }

    }
    return false;
}

string RemovePunctuationsFromString(string S1)
{
    string S2 = "";

    for (short i = 0;i < S1.length();i++)
    {
        if (!IsPunct(S1[i]))
            S2 += S1[i];
    }
    return S2;
}
int main()
{

    string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing.";
    cout << "Original String:\n" << S1;

    cout << "\n\nPauncuations Removed:\n" << RemovePunctuationsFromString(S1);

    system("pause>0");
    
}                                             