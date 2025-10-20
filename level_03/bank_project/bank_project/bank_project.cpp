#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using  namespace std;

const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
struct sUser
{
    string UserName;
    string Password;
    short Permissions;
    bool MarkForDelete = false;
};
sUser CurrentUser;


enum enPermissionProcess
{
    eAll = -1, eShowClients = 1, eAddClient = 2, eDeleteClient = 4, eUpadateClient = 8, eFindClient = 16, eTransactions = 32, eManageUsers = 64
};

bool CheckPermission(enPermissionProcess PermissionProces)
{
    //Verify the process permissions
    if (CurrentUser.Permissions == -1)
        return true;
    if (CurrentUser.Permissions & PermissionProces == PermissionProces)
        return true;
    else
        return false;
}
void ShowAccessDeniedMessage()
{
    cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.";
    cout << "\n------------------------------------\n";
}

void MainScreen();
void transactionsMenueScreen();
void ManageUsersScreen();
bool CheckPermission(enPermissionProcess PermissionProces);
void LoginScreen();
void ShowAccessDeniedMessage();

void GoBackMainScreen()
{
    cout << "Enter any key to go back the main";
    system("pause>0");
    MainScreen();
}
void GoBacktransactionsScreen()
{
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "Enter any key to go back the main";
    system("pause>0");
    // transactionsMenueScreen();
}
void GoBackUsersScreen()
{
    cout << "\n____________________________________________";
    cout << endl;
    cout << "Enter any key to go back the Users Manager Screen";
    system("pause>0");
}

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
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.  
    }
    return vString;
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
string ConvertRecordUserToLine(sUser User, string Seperator = "#//#")
{
    string stUserRecord = "";
    stUserRecord += User.UserName + Seperator;
    stUserRecord += User.Password + Seperator;
    stUserRecord += to_string(User.Permissions);

    return stUserRecord;
}
sUser ConvertLineUsertoRecord(string Line, string Seperator = "#//#")
{
    sUser User;
    vector<string> vUserData;
    vUserData = SplitString(Line, Seperator);

    User.UserName = vUserData[0];
    User.Password = vUserData[1];
    User.Permissions = stof(vUserData[2]);
    return User;
}

vector<sClient> LoadDateClinetFromFile(string ClientsFileName)
{
    fstream  ClientFile;
    vector <sClient> vClient;
    string Line = "";

    ClientFile.open(ClientsFileName, ios::in);
    if (ClientFile.is_open())
    {
        while (getline(ClientFile, Line))
        {
            vClient.push_back(ConvertLinetoRecord(Line));
        }
        ClientFile.close();
    }

    return vClient;
}
vector <sUser> LoadDateUsersFromFile()
{
    fstream Users;
    string Line = "";
    vector <sUser> vUsers;

    Users.open(UsersFileName, ios::in);
    if (Users.is_open())
    {
        while (getline(Users, Line))
        {
            vUsers.push_back(ConvertLineUsertoRecord(Line));
        }
    }
    return vUsers;
}
bool IsUsernameExist(string Username)
{
    vector<sUser> vUsers = LoadDateUsersFromFile();
    for (sUser U : vUsers)
    {
        if (U.UserName == Username)
        {
            return true;
        }
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
void PrintUserRecord(sUser User)
{
    cout << "| " << setw(20) << left << User.UserName;
    cout << "| " << setw(20) << left << User.Password;
    cout << "| " << setw(5) << left << User.Permissions;
}
void PrintAllClients()
{
    if (!CheckPermission(enPermissionProcess::eShowClients))
    {
        ShowAccessDeniedMessage();
        GoBackMainScreen();
        return;
    }
    vector <sClient> vClients = LoadDateClinetFromFile(ClientsFileName);
    system("cls");
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    for (sClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    GoBackMainScreen();
}
void PrintAllUsers()
{
    vector <sUser> vUsers = LoadDateUsersFromFile();
    system("cls");
    cout << "\n\t\tClient List (" << vUsers.size() << ") User(s).";

    cout << "\n_______________________________________________________";
    cout << "_______\n" << endl;
    cout << "| " << left << setw(20) << "Username";
    cout << "| " << left << setw(20) << "Password";
    cout << "| " << left << setw(5) << "Permission";
    cout << "\n_______________________________________________________";

    cout << "_______\n" << endl;

    for (sUser User : vUsers)
    {
        PrintUserRecord(User);
        cout << endl;
    }
    //cout << "\n_______________________________________________________";
    //cout << "_______\n" << endl;
    GoBackUsersScreen();
}
sClient ReadNewClient()
{
    sClient Client;
    cout << "Enter Account Number? "; // Usage of std::ws will extract allthe whitespace character 
    getline(cin >> ws, Client.AccountNumber);

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


short ReadOnePermission(string massage, enPermissionProcess p)
{
    char c = 'y';
    short  Permissions = 0;
    cout << massage;
    cin >> c;
    if (tolower(c) == 'y')
    {
        Permissions += p;
    }
    return  Permissions;
}
short ReadPermissions()
{
    char c = 'y';
    short Permissions = 0;

    cout << "Do You Want Set All Permissions For User (y,n) ? ";
    cin >> c;
    if (tolower(c) == 'y')
        return enPermissionProcess::eAll;

    Permissions += ReadOnePermission("Do You Want Set show Client List Permissions For User (y,n) ? ", enPermissionProcess::eShowClients);
    Permissions += ReadOnePermission("Do You Want Set Add Client Permissions For User (y,n) ? ", enPermissionProcess::eAddClient);
    Permissions += ReadOnePermission("Do You Want Set Delete Client Permissions For User (y,n) ? ", enPermissionProcess::eDeleteClient);
    Permissions += ReadOnePermission("Do You Want Set Upadate Client Permissions For User (y,n) ? ", enPermissionProcess::eUpadateClient);
    Permissions += ReadOnePermission("Do You Want Set Find Client Permissions For User (y,n) ? ", enPermissionProcess::eFindClient);
    Permissions += ReadOnePermission("Do You Want Set Transactions Permissions For User (y,n) ? ", enPermissionProcess::eTransactions);
    Permissions += ReadOnePermission("Do You Want Set Manage Users Permissions For User (y,n) ? ", enPermissionProcess::eManageUsers);

    return Permissions;
}
sUser ReadNewUser()
{
    sUser User;
    cout << "Enter Username ? ";
    getline(cin >> ws, User.UserName);
    cout << "Enter Password ? ";
    getline(cin, User.Password);
    User.Permissions = ReadPermissions();
    return User;
}

sClient UpdatClientInf(string AccountNumber)
{
    sClient Client;
    Client.AccountNumber = AccountNumber;

    cout << "Enter PinCode? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}
sUser UpdatUserInf(string Username)
{
    sUser User;
    string OldUsername = Username;

    cout << "Enter Username ? ";
    getline(cin >> ws, User.UserName);

    if (!(OldUsername == Username))
    {
        while (IsUsernameExist(User.UserName))
        {
            cout << "The Username is not available\n";
            cout << "Enter another Username  ? ";
            getline(cin >> ws, User.UserName);
        }
    }
    cout << "Enter Password? ";
    getline(cin, User.Password);
    User.Permissions = ReadPermissions();
    return User;
}

void AddDataLineClientToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}
void AddDataLineUserToFile(string FileName, string stDataLine)
{
    fstream FileUsers;
    FileUsers.open(FileName, ios::out | ios::app);

    if (FileUsers.is_open())
    {
        FileUsers << stDataLine << endl;
        FileUsers.close();
    }
}
void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineClientToFile(ClientsFileName, ConvertRecordToLine(Client));
}
void AddClients()
{
    if (!CheckPermission(enPermissionProcess::eAddClient))
    {
        ShowAccessDeniedMessage();
        GoBackMainScreen();
        return;
    }
    char AddMore = 'Y';
    do
    {
        system("cls");
        cout << "Adding New Client:\n\n";
        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}
void AddUsers();
void AddNewuser()
{
    sUser User;
    User = ReadNewUser();
    while(IsUsernameExist(User.UserName))
    {
        cout << "!! The Username is not available !! \n";
        User = ReadNewUser();
    }
    AddDataLineUserToFile(UsersFileName, ConvertRecordUserToLine(User));
}
void AddUsers()
{
    char AddMore = 'Y';
    do
    {
        system("cls");
        cout << "Adding New User:\n\n";
        AddNewuser();
        cout << "\nUser Added Successfully, do you want to add more Users? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}
string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber ?";
    cin >> AccountNumber;
    return AccountNumber;
}
string ReadUsername()
{
    string Username = "";
    cout << "\nPlease enter Username ?";
    cin >> Username;
    return Username;
}
string ReadPassword()
{
    string ReadPassword = "";
    cout << "\nPlease enter Password ?";
    cin >> ReadPassword;
    return ReadPassword;
}

vector <sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
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
vector <sUser> SaveUsersDataToFile(string FileName, vector <sUser> vUsers)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite
    string DataLine;
    if (MyFile.is_open())
    {
        for (sUser U : vUsers)
        {
            if (U.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordUserToLine(U);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vUsers;
}


bool FindClientByAccountNumber(string AccountNumber, vector <sClient>& vClients, sClient& Client)
{
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}
bool FindUserByUsername(string Username, vector <sUser> vUsers, sUser& User)
{

    for (sUser U : vUsers)
    {

        if (U.UserName == Username)
        {
            User = U;
            return true;
        }

    }
    return false;

}
bool FindUserByUsernameAndPassword(string Username, string Password, sUser& User)
{

    vector <sUser> vUsers = LoadDateUsersFromFile();

    for (sUser U : vUsers)
    {

        if (U.UserName == Username && U.Password == Password)
        {
            User = U;
            return true;
        }

    }
    return false;

}
void FindClient()
{
    if (!CheckPermission(enPermissionProcess::eFindClient))
    {
        ShowAccessDeniedMessage();
        GoBackMainScreen();
        return;
    }
    vector <sClient> vClients = LoadDateClinetFromFile(ClientsFileName);
    sClient C;
    string AccountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, vClients, C))
    {
        PrintClientRecord(C);
        GoBackMainScreen();
    }
    else
    {
        cout << "The Client doesn't exsist" << endl;
        GoBackMainScreen();
    }

}
void FindUser()
{
    vector <sUser> vUsers = LoadDateUsersFromFile();
    sUser U;
    string Username = ReadUsername();

    if (FindUserByUsername(Username, vUsers, U))
    {
        PrintUserRecord(U);
        GoBackUsersScreen();
    }
    else
    {
        cout << "The Client doesn't exsist" << endl;
        GoBackUsersScreen();
    }

}

bool isAllowedForModificationUser(short Permission)
{
    return (CurrentUser.Permissions == enPermissionProcess::eAll) || (CurrentUser.Permissions != enPermissionProcess::eAll && Permission != enPermissionProcess::eAll);
}
bool Upadate_Client()
{
    if (!CheckPermission(enPermissionProcess::eUpadateClient))
    {
        ShowAccessDeniedMessage();
        GoBackMainScreen();
        return false;
    }
    vector <sClient> vClients = LoadDateClinetFromFile(ClientsFileName);
    char Answer = 'n';
    string AccountNumber = ReadClientAccountNumber();
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            cout << "\n\nAre you sure you want updata this client? y/n ? ";
            PrintClientRecord(C);
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                C = UpdatClientInf(C.AccountNumber);
                SaveCleintsDataToFile(ClientsFileName, vClients);
                vClients = LoadDateClinetFromFile(ClientsFileName);
                cout << "\n\nClient Updatad Successfully.";
                GoBackMainScreen();
                return true;
            }

            return false;
        }

    }
    cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    GoBackMainScreen();
    return false;
}
bool Upadate_User()
{
    vector <sUser> vUsers = LoadDateUsersFromFile();
    sUser User;
    char Answer = 'n';
    string Username = ReadUsername();
    //string Password = ReadPassword();

    for (sUser& U : vUsers)
    {
        if (U.UserName == Username)
        {
            /* if (!(U.Password == Password))
             {
                 cout << "Password faild\n";
                 GoBackUsersScreen();
             }*/

            if (isAllowedForModificationUser(U.Permissions))
            {
                PrintUserRecord(U);
                cout << "\n\nAre you sure you want updata this User? y/n ? ";
                cin >> Answer;
                if (Answer == 'y' || Answer == 'Y')
                {
                    U = UpdatUserInf(U.UserName);
                    SaveUsersDataToFile(UsersFileName, vUsers);
                    vUsers = LoadDateUsersFromFile();
                    cout << "\n\nUser Updatad Successfully.";
                    GoBackUsersScreen();
                    return true;
                }

                return false;

            }
            else
            {
                cout << "You do not have permissions to update the admin\n";
                GoBackUsersScreen();
                return false;
            }
        }
    }
    cout << "\nUser with Username (" << Username << ") is Not Found!";
    GoBackUsersScreen();
    return false;
}
bool DeleteClient()
{
    if (!CheckPermission(enPermissionProcess::eDeleteClient))
    {
        ShowAccessDeniedMessage();
        GoBackMainScreen();
        return false;
    }
    vector <sClient> vClients = LoadDateClinetFromFile(ClientsFileName);
    char Answer = 'n';
    string AccountNumber = ReadClientAccountNumber();
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            PrintClientRecord(C);
            cout << "\n\nAre you sure you want delete this client? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                C.MarkForDelete = true;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                vClients = LoadDateClinetFromFile(ClientsFileName);
                cout << "\n\nClient Deleted Successfully.";
                GoBackMainScreen();
                return true;
            }

            return false;
        }

    }
    cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    GoBackMainScreen();
    return false;
}
bool DeleteUser()
{

    vector <sUser> vUsers = LoadDateUsersFromFile();
    char Answer = 'n';
    string Username = ReadUsername();
    for (sUser& U : vUsers)
    {
        if (U.UserName == Username)
        {

            if (isAllowedForModificationUser(U.Permissions))
            {
                PrintUserRecord(U);
                cout << "\n\nAre you sure you want to delete this user ? y/n ? ";
                cin >> Answer;
                if (Answer == 'y' || Answer == 'Y')
                {
                    U.MarkForDelete = true;
                    SaveUsersDataToFile(UsersFileName, vUsers);
                    vUsers = LoadDateUsersFromFile();
                    cout << "\n\nUser Deleted Successfully.";
                    GoBackUsersScreen();
                    return true;
                }
                return false;
            }
            else
            {
                cout << "You do not have permissions to delete the admin\n";
                GoBackUsersScreen();
                return false;
            }
        }
    }
    cout << "\nUser with Username (" << Username << ") is Not Found!";
    GoBackUsersScreen();
    return false;
}

double ReadAccountBlance()
{
    double b = 0;
    cout << "\nEnter the Balance : ";
    cin >> b;
    return b;
}
void DepositToAccountOfClient()
{
    vector <sClient> vClients = LoadDateClinetFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();
    bool else_ = true;
    for (sClient& Client : vClients)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            else_ = false;
            PrintClientRecord(Client);
            Client.AccountBalance += ReadAccountBlance();

            SaveCleintsDataToFile(ClientsFileName, vClients);
            vClients = LoadDateClinetFromFile(ClientsFileName);
            cout << "Sucsucful..\n\n";
            GoBacktransactionsScreen();
        }
    }

    if (else_)
    {
        cout << "The Client doesn't exsist" << endl;
        GoBacktransactionsScreen();
    }

}
void WithdrawFromAccountOfClient()
{
    vector <sClient> vClients = LoadDateClinetFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    bool NotExist = true;
    for (sClient& Client : vClients)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            NotExist = false;
            PrintClientRecord(Client);
            Client.AccountBalance += (ReadAccountBlance() * -1);

            SaveCleintsDataToFile(ClientsFileName, vClients);
            vClients = LoadDateClinetFromFile(ClientsFileName);
            cout << "Sucsucful..\n\n";
            GoBacktransactionsScreen();
        }
    }
    if (NotExist)
    {
        cout << "The Client doesn't exsist" << endl;
        GoBacktransactionsScreen();
    }
}

void PrintBalanceClient(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}
void ShowTotalBalances()
{
    vector <sClient> vClients = LoadDateClinetFromFile(ClientsFileName);
    system("cls");
    double Total_B = 0;
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";

    cout << "_________________________________________\n" << endl;

    for (sClient Client : vClients)
    {
        PrintBalanceClient(Client);
        Total_B += Client.AccountBalance;
        cout << endl;
    }
    cout << "\nTotalBalancs : " << Total_B;
    GoBacktransactionsScreen();
}
void transactionsMenueScreen()
{
    if (!CheckPermission(enPermissionProcess::eTransactions))
    {
        ShowAccessDeniedMessage();
        GoBackMainScreen();
        return;
    }
    char Choice;
    do
    {
        system("cls");
        cout << "=========================================\n";
        cout << "       transactions Menue Screen\n";
        cout << "=========================================\n";
        cout << "\t[1]- Deposit.\n";
        cout << "\t[2]- Withdraw.\n";
        cout << "\t[3]- Total Balances.\n";
        cout << "\t[4]- Main Menue.\n";
        cout << " Choose what do you want to do ? [1 to 4] -> ";

        cin >> Choice;
        switch (Choice)
        {
        case '1':DepositToAccountOfClient();break;
        case '2':WithdrawFromAccountOfClient();break;
        case '3':ShowTotalBalances();break;
        case '4':MainScreen();break;
        default:
            cout << "The out Range the Choose\n";
            break;
        }
    } while (true);
}
void MainScreen()
{

    char Choice;
    do
    {
        system("cls");
        cout << "=========================================\n";
        cout << "          Main Menue Screen\n";
        cout << "=========================================\n";
        cout << "[1]- show Client List.\n";
        cout << "[2]- Add Client.\n";
        cout << "[3]- Delete Client\n";
        cout << "[4]- Upadate Client.\n";
        cout << "[5]- Find Client.\n";
        cout << "[6]- Transactions.\n";
        cout << "[7]- Manage Users.\n";
        cout << "[8]- logout." << endl;
        cout << " Choose what do you want to do ? [1 to 8] -> ";

        cin >> Choice;
        switch (Choice)
        {
        case '1':PrintAllClients();break;
        case '2':AddClients();break;
        case '3':DeleteClient();break;
        case '4':Upadate_Client;break;
        case '5':FindClient(); break;
        case '6':transactionsMenueScreen();break;
        case '7':ManageUsersScreen();break;
        case '8':LoginScreen(); break;
        case '9':exit;
        default:
            cout << "The out Range the Choose\n";
            break;
        }
    } while (Choice != '9');
}

void ManageUsersScreen()
{
    if (!CheckPermission(enPermissionProcess::eManageUsers))
    {
        ShowAccessDeniedMessage();
        GoBackMainScreen();
        return;
    }


    char Choice;
    do
    {
        system("cls");
        cout << "===========================================\n";
        cout << "\tManage Users Menue Screen\n";
        cout << "===========================================\n";
        cout << "\t[1] List Users.\n";
        cout << "\t[2] Add New User.\n";
        cout << "\t[3] Delete User.\n";
        cout << "\t[4] Update User.\n";
        cout << "\t[5] Find User.\n";
        cout << "\t[6] Main Menue.\n";
        cout << "===========================================\n";
        cout << " Choose what do you want to do ? [1 to 6] -> ";
        cin >> Choice;
        switch (Choice)
        {
        case '1':PrintAllUsers();break;
        case '2':AddUsers();break;
        case '3':DeleteUser(); break;
        case '4':Upadate_User();break;
        case '5':FindUser(); break;
        case '6':MainScreen();break;
        default:cout << "The out Range the Choose\n";break;
        }

    } while (true);
}
void LoginScreen()
{
    string Username;
    string Password;

    bool UserExist = false;

    do
    {
        system("cls");
        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (UserExist)
        {
            cout << "Invlaid Username/Password!\n";
        }

        cout << "Enter Username? ";
        cin >> Username;
        cout << "Enter Password? ";
        cin >> Password;

        UserExist = !FindUserByUsernameAndPassword(Username, Password, CurrentUser);

    } while (UserExist);

    MainScreen();
}

int main()
{
    LoginScreen();
}

