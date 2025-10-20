#include <iostream>
#include <string>
using namespace std;
float readCircmference()
{
   
    float i = 0;
  
    cout << "Enter the Circmference\n";
    cin >> i;
   
    
    while (i<0 || cin.fail())
    {
        
        if (cin.fail())
        {
            cout << "Error, Enter only numbers \n";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> i;
        }
        else
        {
            cout << "Error, Enter the Circmference\n";
            cin >> i;
        }
        
       
    }
   
   
       
    
    
                
    
    return i;
}

float CalculateCircleArea(float i)
{
    const float pi = 3.14;
   
   float area= (i * i) / (4 * pi);
   return area;

}

void printCircleArea(float x)
{
    cout << "The CircleArea = " << x << endl;

}


int main()
{
    printCircleArea(CalculateCircleArea(readCircmference()));
   
}
