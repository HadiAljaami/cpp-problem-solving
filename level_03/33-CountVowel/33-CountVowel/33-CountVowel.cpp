#include<string>
#include<iostream>
using namespace std;

char ReadChar()
{
	char Ch1;
	cout << "\nPlease Enter a Character?\n";
	cin >> Ch1;

	return Ch1;

}
string  ReadString()
{
	string S1;

	cout << "Please Enter Your String?\n";

	getline(cin, S1);
	return S1;

}


bool IsVowel(char Ch)
{
	Ch = tolower(Ch);

	return (Ch == 'a' || Ch == 'e' || Ch == 'i' || Ch == 'u' || Ch == 'o');
}

int CountVowels(string S1)
{
	int Counter = 0;

	for (int i = 0;i < S1.length();i++)
	{
		if (IsVowel(S1[i]))
			Counter++;
	}
     return Counter;
}


int main()
{

	char Ch1 = ReadChar();

	string S1 = ReadString();  

	cout << "\nNumber of vowels is: " << CountVowels(S1);


	system("pause>0");
}

