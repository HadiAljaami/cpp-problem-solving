
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";
struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};


short FindPostion(string S1, string Word, short FromPos = 0);
string DeleteString(string S1, int From, int To);
string SubString(string S1, int From, int To);
vector<string> SplitString(string S1, string Delim = "#//#");
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#");
vector<sClient> RreadClientFromFile();
void PrintClientRecord(sClient);
void PrintAllClient();

int main()
{
	PrintAllClient();
	
	return 0;
}


//==============================
void PrintAllClient()
{
	vector<sClient> vFileContent = RreadClientFromFile();

	for (int i = 0;i < vFileContent.size();i++)
	{
		PrintClientRecord(vFileContent[i]);
	}

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

vector<sClient> RreadClientFromFile()
{
	fstream MyFile;
	string Line;
	vector<sClient> vFileContent;
	MyFile.open(ClientsFileName, ios::in);

	if (MyFile.is_open())
	{
		while (getline(MyFile, Line))
		{

			vFileContent.push_back(ConvertLinetoRecord(Line));
		}

		MyFile.close();
	}

	return vFileContent;

}

sClient ConvertLinetoRecord(string Line, string Seperator )
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

vector<string> SplitString(string S1, string Delim )
{
	vector<string> vString;
	string Word = "";
	short pos = 0;


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

string SubString(string S1, int From, int To)
{
	string S2 = "";
	for (int i = From;i < To;i++)
		S2 += S1[i];

	return S2;
}

string DeleteString(string S1, int From, int To)
{
	string S2 = "";
	for (int i = 0;i < S1.length();i++)
	{
		if ((i >= From && i < To))
			continue;

		S2 += S1[i];
	}
	return S2;
}
short FindPostion(string S1, string Word, short FromPos )
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