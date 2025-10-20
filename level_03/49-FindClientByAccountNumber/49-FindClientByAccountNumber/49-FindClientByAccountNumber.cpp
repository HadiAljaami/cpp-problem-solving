
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
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
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString; short pos = 0; string sWord; // define a string variable  // use find() function to get the position of the delimiters  
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word   
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string. 
	}
	return vString;
}


sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	sClient Client; vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);
	//cast string to double 
	return Client; 
}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode
	if (MyFile.is_open())
	{
		string Line; sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

string ReadClientAccountNumber()
{
	string S="";
	cout << "\nEnter the AccountNumber of Client do you Search him :";
	getline(cin, S);
	return S;
}
//bool ClientIsFind(string AccountNumber, vector<sClient>& vClients)
//{
//	sClient Client;
//	for (int i = 0;vClients.size();i++)
//	{
//		Client = vClients[0];
//		if (Client.AccountNumber == AccountNumber)
//			return true;
//    }
//	return false;
//}
bool FindClientByAccountNumber(string AccountNumber, sClient& Client )
{
	vector <sClient> vClients;
	
	vClients=LoadCleintsDataFromFile(ClientsFileName);
	for (int i = 0;i<vClients.size();i++)
	{	  // åäÇ ÇÐÇ ÍÕáäÇ Úáì ÇáÑÞã äÞæã ÈÊÎÒíäÉ Ýí ãÊÛíÑ ÍÊì áÇ äØÑ Çáì ÇáÈÍË ÚáíÉ ãÑÉ ÃÎÑì
		Client = vClients[0];
		if (Client.AccountNumber == AccountNumber)
			return true;
	}

	return false;
}
void PrintClientRecord(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;

	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}
int main()
{
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientRecord(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	}
	system("pause>0"); return 0;
}



