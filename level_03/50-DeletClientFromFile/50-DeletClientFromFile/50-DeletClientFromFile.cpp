
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
	bool MarkForDelete = false; 
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
	string AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code     : " << Client.PinCode;
	cout << "\nName         : " << Client.Name;
	cout << "\nPhone        : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);
	return stClientRecord;
}

void WriteClientToFile(string ClientsFileName,vector <sClient>& vClients)
{
	fstream FileClient;

	FileClient.open(ClientsFileName,ios::out);
	if (FileClient.is_open())
	{
		for (int i = 0;i < vClients.size();i++)
		{
			FileClient <<ConvertRecordToLine(vClients[0]) <<endl;
		
		}
		FileClient.close();
	}
}
bool DeleteClientFromFile(string AccountNumber, vector <sClient>& vClients)
{
	char ToDelete = 'n';
	for (int i=0;i<vClients.size();i++)
	{
		sClient C = vClients[i];
		if (AccountNumber == C.AccountNumber)
		{
			PrintClientCard(C);
			cout << "\nDo you Delete This Client (Y,y) : ";
			cin >> ToDelete;
			if (ToDelete == 'Y' || ToDelete == 'y')
			{
				vClients.erase(vClients.begin() + i);
				WriteClientToFile(ClientsFileName, vClients);
				//Refresh Clients 
				vClients = LoadCleintsDataFromFile(ClientsFileName);
				cout << "\n\nClient Deleted Successfully.";
				return true;
			}
			
		}
	}
	cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	return false;
}

	
	

int main()
{
	sClient Client;
	vector <sClient> vClients;
	string AccountNumber = ReadClientAccountNumber();
	vClients = LoadCleintsDataFromFile(ClientsFileName);

	if (DeleteClientFromFile(AccountNumber, vClients))
		cout << "Succsus\n";
	else
		cout << "No delete it, the item doesn't exist\n";
	


	system("pause>0"); return 0;
}



