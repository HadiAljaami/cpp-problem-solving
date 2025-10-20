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

int MarksAverage(stMarks Marks)
{
	int Average = 0;
	Average = (Marks.mark1 + Marks.mark2 + Marks.mark3)/3;
	return Average;
}

void printAverageMarks(int Average)
{

	cout << "The Average of Marks : " << Average << endl;

}

int main()
{
	printAverageMarks(MarksAverage(ReadMarks()));
}
