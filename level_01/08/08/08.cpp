#include <iostream>
using namespace std;
int ReadMark()
{
    int Mark;
    cout <<" Enter Your Mark : ";
    cin >> Mark;

    return Mark;
}
bool chack(int mark)
{
    return (mark >= 50);
}

void printMark(bool mark)
{
    if (mark)
        cout << "pass" << endl;
    else
        cout << "fail" << endl;

}
int main()
{
    printMark(chack(ReadMark()));
}
