//by Hadi Ameen

#include <iostream>
using namespace std;
struct stMarks
{
	int mark1;
	int mark2;
	int mark3;


};

stMarks ReadMarks()
{
	stMarks Marks;

	cout << "Enter Mark 1 : ";cin >> Marks.mark1;
	cout << "Enter Mark 2 : ";cin >> Marks.mark2;
	cout << "Enter Mark 3 : ";cin >> Marks.mark3;
	return Marks;
}


int sumOf3Marks(stMarks Marks)
{
	
	int sum = Marks.mark1 + Marks.mark2 + Marks.mark3;
	return sum;
}

int  MarksAverage(int Marks)
{
	int Average=Marks / 3;
	return Average;
}

bool checkMarks(int Average)
{
	return (Average >= 50);
}

void printAverageMarks(int Average)
{

	cout << "The Average of Marks : " << Average << endl;
	if (checkMarks(Average))
		cout << "pass" << endl;
	else
		cout << "fail" << endl;

}



int main()
{
	printAverageMarks(MarksAverage(sumOf3Marks(ReadMarks())));

	
}
