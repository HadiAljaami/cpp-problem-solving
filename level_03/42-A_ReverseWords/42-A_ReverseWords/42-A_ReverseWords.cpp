
// wirte a program toreplace words in string:
/* origial string : Welocme to jorden, jordan is a nice country
string After Replace: Welcome to USA, is a nice countery*/
#include<string>
#include<iostream>
#include<vector>
using namespace std; 

string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo)
{
	// áÇ ÃÏÑí áãÇĞÇ -1  İŞØ íÓÊØíÚ ÇáÊÚÇãá ãÚÇå ÈÇáÑÛã Ãäå áÇ íÍŞŞ ÇáÔÑØ
	// ÇÓÊØíÚ ÊÚÑíİ ãÊÛíÑ ÈÏá 	 std::string::npos
	//short npos = -1;
	short pos = S1.find(StringToReplace);
	//cout <<endl<<" if don't find the pos return : "<< pos << endl;
	while (pos != std::string::npos)
	{	
		//cout << endl<< std::string::npos << endl;//4294967295
		S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
		pos = S1.find(StringToReplace);//find next
	
	}
	return S1;
}
int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "Jordan";
	string ReplaceTo = "USA";
	short pos = S1.find(StringToReplace);
	//cout << "================================\n"
	//	<< pos << " " << std::string::npos << endl;
	//while (pos != std::string::npos)
	//{
	//	cout << "true :" << endl;
	//	cout << pos << " " << std::string::npos << endl;
	//	pos = -1;
	//}

	
	cout << "\nOrigial String\n" << S1;
	cout << "\n\nString After Replace:";
	cout << "\n" << ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, ReplaceTo);
    
	system("pause>0");
	

}