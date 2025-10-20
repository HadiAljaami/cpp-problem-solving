#include<string>
#include<iostream>
using namespace std;

string  ReadString()
{
	string S1;

	cout << "Please Enter Your String?\n";

	getline(cin, S1);
	return S1;

}

void PrintWoedsInString(string S1)
{
	cout << "\nVowels in string are:\n ";
	for (int i = 0;i < S1.length();i++)
	{
		if (S1[i] != ' ')
			cout << S1[i];

		   if(S1[i] == ' ' && S1[i+1] != ' ')
			cout << endl;
		
	}

}


int main()
{
	 //there are mastak in this problem

	string S1 = ReadString();

	PrintWoedsInString(S1);

	system("pause>0");
}

