#include <iostream>
#include <string>
using namespace std;
struct stInfo
{
	int age;
	bool HasDriveLicense;
	bool HasRecommendation;
};

stInfo ReadInfo()
{
	stInfo Info;
	cout << "Please Enter Your Age?" << endl;
	cin >> Info.age;
	cout << "Do you have driver License?" << endl;
	cin >> Info.HasDriveLicense;
	cout << "Do you have Recommendation?" << endl;
	cin >> Info.HasRecommendation;
	return Info;
}

bool IsAccepted(stInfo Info)
{
	if (Info.HasRecommendation)
		return true;
	else
	return (Info.age > 21 && Info.HasDriveLicense);
}

void printResult(stInfo Info)
{
	if (IsAccepted(Info))
		cout << "\n Hired" << endl;

	else
		cout << "\n Rejected" << endl;


}
int main()
{
	printResult(ReadInfo());

}

