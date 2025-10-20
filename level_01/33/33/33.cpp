#include <iostream>
using namespace std;

void ReadGrade(int& g)
{
    
    cout << "Enter Your Grade : ";cin >> g;
}

char Grade(int g)
{
    if (g >= 90 && g <= 100)
        return 'A';
    else if (g >= 80 && g <= 89)
        return 'B';

    else if (g >= 70 && g <= 79)
        return 'C';

    else if (g >= 60 && g <= 69)
        return 'D';

    else if (g >= 50 && g <= 59)
        return 'E';

    return '0';
}
void printGrade(char g)
{
    cout << " is : " << g << endl;
}
int main()
{
    int g = 0;
    ReadGrade(g);

    printGrade(Grade(g));
}
