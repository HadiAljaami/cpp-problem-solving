#include <iostream>
using namespace std;
string  ReadPassword()
{
    string pass;
  
        cout << "Enter a 3-password (all capital ?) " << endl;
        cin >> pass;
    

    return pass;
}

bool GuessPassword(string Password)
{
    cout << "\n";
    string Word = "";
    int c = 0;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65;k <= 90;k++)
            {

                
                Word = Word + char(i);
                Word = Word + char(j);
                Word = Word + char(k);
                cout << "Trial [" << ++c << "] : " << 
                Word << endl;
               
                if (Word == Password)
                {
                    cout << "Password is " << Word << "\nFound after " << c << " trial(s)" << endl;
                    return 1;
                }
                Word = " ";
               
            }

        }
       
    }
    return 0;
   
}


int main()
{
    GuessPassword(ReadPassword());

}