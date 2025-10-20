/*
CopyRight ProgrammingAdvices.com
Mohammed Abu-Hadhoud
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";
enum enMainMenueOptions {
    QuickWithdraw = 1, NormalWithdraw = 2, Deposit = 3,
    CheckBalance = 4, Logout = 5
};
enum enQuickWithdraw{e20=1,e50=2, e100=3, e200=4, e400=5, e500=6,e800=7, e1000=8, eExit=9};

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
sClient CurrentClient;

void ATM_MainMenueScreen();
void LoginScreen();

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
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

vector <sClient> LoadCleintsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }

        }

        MyFile.close();
    }

    return vClients;
}

void DrawQuickWithdrawScreen()
{
    cout << "===========================================\n";
    cout << "\t\t\tQuick Withdraw \n";
    cout << "===========================================\n";
    cout << "[1] 20" << right << setw(15) << "[2] 50\n";
    cout << "[3] 100"<< right << setw(15) << "[4] 200\n";
    cout << "[5] 400"<< right << setw(15) << "[6] 500\n";
    cout << "[7] 800"<< right << setw(15) << "[8] 1000\n";
    cout << "[9] Exit"<< right << setw(15)<< endl;
}
short ReadQuickWithdraw()
{
    short NumberAmount;

    bool Answer = false;
    do
    {
        cout << "Enter Number  Amount do you Withdraw ? ";
        cin >> NumberAmount;

        switch (NumberAmount)
        {
        case enQuickWithdraw::e20: return 20;
        case enQuickWithdraw::e50: return 50;
        case enQuickWithdraw::e100: return 100;
        case enQuickWithdraw::e200: return 200;
        case enQuickWithdraw::e400: return 400;
        case enQuickWithdraw::e500: return 500;
        case enQuickWithdraw::e800: return 800;
        case enQuickWithdraw::e1000: return 1000;
        case enQuickWithdraw::eExit: return 0;
        default:
            system("cls");
            DrawQuickWithdrawScreen();
            cout << "Invild Number !\n";
            Answer = true;
            break;
        }

    } while (true);
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient>& vClients)
{

    char Answer = 'n';


    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;
                CurrentClient.AccountBalance += Amount;
                return true;
            }

        }


        return false;
    }

}

void ShowQuickWithdrawScreen()
{

    if (CurrentClient.AccountBalance < 20)
    {
        cout << "Your Balance is : " << CurrentClient.AccountBalance << " You cann't use Quick Withdraw" << endl;
        return;
    }

    DrawQuickWithdrawScreen();
    vector <sClient> Clients = LoadCleintsDataFromFile(ClientsFileName);
    short Amount = ReadQuickWithdraw();
    if (Amount == 0)
        return;
    while(CurrentClient.AccountBalance < Amount)
    {
        system("cls");
        DrawQuickWithdrawScreen();
        cout << "Your Balance is : " << CurrentClient.AccountBalance <<" You cann't withdraw this amount" << endl;
        Amount = ReadQuickWithdraw();
    }
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, Amount*-1, Clients);
   // CurrentClient.AccountBalance -= Amount;
}

void ShowNormalWithdrawScreen()
{
    cout << "===========================================\n";
    cout << "\t\t\tQuick Withdraw \n";
    cout << "===========================================\n";
    int Amount;
    cout << "Enter an amount multiple 5's ? ";
    cin >> Amount;
   
    if (CurrentClient.AccountBalance < Amount)
    {
        cout << "Your Balance is : " << CurrentClient.AccountBalance << " You cann't  Withdraw" << endl;
        return;
    }
    while (Amount % 5 != 0)
    {
        cout << " !! Enter an amount multiple 5's ? ";
        cin >> Amount;
    }
  
    vector <sClient> Clients = LoadCleintsDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, Amount*-1 , Clients);

}

void ShowDepositScreen()
{
    cout << "===========================================\n";
    cout << "\t\t\tDeposit \n";
    cout << "===========================================\n";
    int Amount;
    cout << "Enter an amount that you Deposit ? ";
    cin >> Amount;

  
    while (Amount <= 0)
    {
        cout << "Error!! Enter an amount that you Deposit  ? ";
        cin >> Amount;
    }

    vector <sClient> Clients = LoadCleintsDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, Amount, Clients);


}

void PrintBalance()
{
    cout << "Your Balance is : " << CurrentClient.AccountBalance;
}
void ShowCheckBalanceScreen()
{
    cout << "===========================================\n";
    cout << "\t\tATM Check Balance Screen\n";
    cout << "===========================================\n";
    PrintBalance();
}
void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}

void GoBackToATM_MainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ATM_MainMenueScreen();

}

short ReadATM_MainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 5]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PerfromATM_MainMenueOption(enMainMenueOptions MainMenueOption)
{

        switch (MainMenueOption)
        {
        case enMainMenueOptions::QuickWithdraw:
        {
            system("cls");
            ShowQuickWithdrawScreen();
            GoBackToATM_MainMenue();
            break;
        }
        case enMainMenueOptions::NormalWithdraw:
            system("cls");
            ShowNormalWithdrawScreen();
            GoBackToATM_MainMenue();
            break;

        case enMainMenueOptions::Deposit:
            system("cls");
            ShowDepositScreen();
            GoBackToATM_MainMenue();
            break;

        case enMainMenueOptions::CheckBalance:
            system("cls");
            ShowCheckBalanceScreen();
            GoBackToATM_MainMenue();
            break;
        case enMainMenueOptions::Logout:
            system("cls");
            LoginScreen();
            break;
        default:
            cout << "\nThe Number Out Range \n";
            return;
        }
    
}

void ATM_MainMenueScreen()
{
    system("cls");

    cout << "===========================================\n";
    cout << "\t\tATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "[1] Quick withdraw.\n";
    cout << "[2] Normal Withdraw.\n";
    cout << "[3] Deposit.\n";
    cout << "[4] Check Balance.\n";
    cout << "[5] Logout.\n";
    cout << "===========================================\n";


    PerfromATM_MainMenueOption((enMainMenueOptions)ReadATM_MainMenueOption());
}

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, sClient& Client)
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    for (sClient C : vClients)
    {

        if (C.AccountNumber== AccountNumber && C.PinCode == PinCode)
        {
            Client = C;
            return true;
        }
    }
    return false;
}
bool  LoadClientInfo(string AccountNumber, string PinCode)
{

    if (FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
        return true;
    else
        return false;

}
void LoginScreen()
{
    bool LoginFaild = false;

    string AccountNumber, PinCode;
    do
    {
        system("cls");

        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (LoginFaild)
        {
            cout << "Invlaid AccountNumber/PinCode!\n";
        }

        cout << "Enter AccountNumber? ";
        cin >> AccountNumber;

        cout << "Enter PinCode? ";
        cin >> PinCode;

        LoginFaild = ! LoadClientInfo(AccountNumber, PinCode);

    } while (LoginFaild);

    ATM_MainMenueScreen();

}

int main()
{
    LoginScreen();
    
    system("pause>0");
    return 0;
}