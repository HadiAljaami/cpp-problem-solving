/*write a program to read bank client data record and convert it to one line:
   please enter client data:
   enter Account Number? A150
   Enter PinCode? 1234
   Enter Name: Mohammed Abu-Hadhoud
   Enter Phone: 000000000
   Enter AccountBalance? 5000

   Client Reacord for Saving is :
   A150#//#1235#/#Mohammed Abu-Hadhoud#//#00000#//#5000.0000
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

struct sClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

sClient ReadNewClient()
{
	sClient Client;
	cout << "Enter Account Number? ";
	getline(cin, Client.AccountNumber);
	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;
	return Client;
}

short FindPostion(string S1, string Word, short FromPos = 0)
{
	short Pos;
	for (Pos = FromPos;Pos < S1.length();Pos++)
	{
		if (S1[Pos] == Word[0])
		{
			for (int i = 1;i < Word.length();i++)
			{
				if (!(S1[i + Pos] == Word[i]) && Pos >= S1.length())
					break;
			}
			return Pos;
		}
	}
	return -1;
}

string DeleteString(string S1, int From,int To)
{
	string S2 = "";
	for (int i =0;i <S1.length();i++)
	{
		if ((i >= From && i < To))
			continue;

			S2 += S1[i];
	}
	return S2;
}

string SubString(string S1, int From, int To)
{
	string S2 = "";
	for (int i = From;i <To;i++)
		S2+=S1[i];

	return S2;
}
vector<string> SplitString(string S1, string Delim = "#//#")
{
	vector<string> vString;
	string Word = "";
	short pos = 0;

	//(pos = S1.find(Delim)) != std::string::npos
	while ((pos = FindPostion(S1, Delim)) != std::string::npos)
	{

		Word = SubString(S1, 0, pos);
			  if (Word != "")
			  {
				  vString.push_back(Word);
			  }
			  S1 = DeleteString(S1, 0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.   
	}

	return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

	sClient Client;
	vector<string> vClientData;

	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);//cast string to double 

	return Client;
}

void PrintClientRecord(sClient Client)
{
	cout << "\n\nThe following is the extracted client record:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code     : " << Client.PinCode;
	cout << "\nName         : " << Client.Name;
	cout << "\nPhone        : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;

}
int main()
{

	string stLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
	cout << "\nLine Record is:\n";
	cout << stLine;

	sClient Client = ConvertLinetoRecord(stLine);
	PrintClientRecord(Client);


	system("pause>0");
	return 0;

}