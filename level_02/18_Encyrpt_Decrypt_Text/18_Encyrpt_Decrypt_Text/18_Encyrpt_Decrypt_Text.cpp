#include <iostream>
using namespace std;
string  ReadText()
{
    string pass;

    cout << "Enter a Text to Encypt ? " << endl;
    cin >> pass;


    return pass;
}

string Encypt(string Text)
{
    cout << "\n";
    string Encypt = "";
    int n = 90;
   
   for (int j = 0; j < Text.length(); j++)
        {
            for (int i = 65;i <= n;i++)
            {
                if (Text[j] == char(i) )
                {
                    Encypt = Encypt + char(i + 2);
                    break;
                }

                if (i == 90)
                {
                    i = 96;
                    n = 122;
                }

            }

        }

    
    return Encypt;

}

string Decrypt(string EncyptText)
{
    cout << "\n";
    string DecryptText = "";
    int n = 90;

    for (int j = 0; j < EncyptText.length(); j++)
    {
        for (int i = 65;i <= n;i++)
        {
            if (EncyptText[j] == char(i))
            {
                DecryptText = DecryptText + char(i - 2);
                break;
            }

            if (i == 90)
            {
                i = 96;
                n = 122;
            }

        }

    }


    return DecryptText;

}


int main()
{
    
  string x=  ReadText();
  cout << "Text before Encryption : " << x << endl;
  string y = Encypt(x);
  cout << "Text after Encryption : " << y << endl;

  cout << "Text after Decryption : " << Decrypt(y);

  
}