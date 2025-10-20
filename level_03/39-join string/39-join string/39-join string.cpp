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

string JoinString(vector<string> & vString, string Delim)
{

	string S1 = ""; 
	for (string& s : vString) 
	{ 
		S1 = S1 + s + Delim; 
	} 
	return S1.substr(0, S1.length() - Delim.length());

	/*string S1;
	
	for (int i=0;i< vString.size();i++)
	{
		S1+=vString[i];
		S1 += Delim;
	}

	return S1;*/
}


int main()
{
	vector<string> vString{ "hadi","ameen", "ali" };
	
	cout << "\nVector after join: \n";  
	cout << JoinString(vString, " ");

	system("pause>0");
}

