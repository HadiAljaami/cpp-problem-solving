#include <iostream>
using namespace std;
int readPositiveNumber(string message) {
    int num;
    do {
        cout << message << endl;
        cin >> num;
    } while (num <= 0);

    return num;
}
void printDigitsOfNumber(int num) {
    int result = 0;
    while (num) {
        result = result * 10 + num % 10;       
        num /= 10;
    }
    cout << "Digites of number " << "is " << endl;
    cout << result << endl;


}


int main() {

    printDigitsOfNumber((readPositiveNumber("Please enter Positev Number")));

}