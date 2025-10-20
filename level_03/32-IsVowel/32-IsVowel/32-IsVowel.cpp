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

bool IsVowel(char Ch)
{
	Ch = tolower(Ch);

	return (Ch == 'a' || Ch == 'e' || Ch == 'i' || Ch == 'u' || Ch == 'o');
}


int main()
{
	
	char Ch1 = ReadChar();

	if (IsVowel(Ch1))     
		cout << "\nYES Letter \'" << Ch1 << "\' is vowel"; 
	else     
		cout << "\nNO Letter \'" << Ch1 << "\' is NOT vowel";
	

	system("pause>0");
}