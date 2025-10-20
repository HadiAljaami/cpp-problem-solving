
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int Random(int From, int To)
{
    int randNum = rand() % (To - From + 1)+From;
    return randNum;
}
int main()
{
    srand((unsigned)time(NULL));
    cout << Random(5, 10);
    cout << Random(5, 10);
    cout << Random(5, 10);
    cout << Random(5, 10);

    
}