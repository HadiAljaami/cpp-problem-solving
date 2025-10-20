#include <iostream>

#include <string>
using namespace std;

string  ReadString()
{
	string S1;

	cout << "Please Enter Your String?\n";

	getline(cin, S1);

	return S1;

}


int CountSmallLetters(string S1)
{
	int count = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
			count++;
	}
	return count;
}
int main()
{
	string S1 = ReadString();

	cout << "\nSmall Letters Count= " << CountSmallLetters(S1);


	system("pause>0");

}