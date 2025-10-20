#include<string>
#include<iostream>
#include<vector>
using namespace std;

string  ReadString()
{
	string S1;

	cout << "Please Enter Your String?\n";

	getline(cin, S1);
	return S1;

}

string JoinString(vector<string>& vString, string Delim)
{

	string S1 = "";
	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}

string JoinString(string vString[100], short Length, string Delim)
{

	string S1 = "";
	for (int i=0;i<Length;i++)
	{
		S1 = S1 + vString [i]+ Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
	vector<string> vString{ "hadi","ameen", "ali" };
	string arrString[] = { "Mohammed","Faid","Ali","Maher" };

	cout << "\nVector after join: \n";
	cout << JoinString(vString, " ");

	cout << "\n\nArray after join: \n"; 
	cout << JoinString(arrString, 4, " ");

	system("pause>0");
}

