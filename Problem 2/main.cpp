# include <iostream>
# include "FractionCalculator.h"

using namespace std;

int main() {
    FractionCalculator calculator;
    bool flag = true;
    while (flag) {
        try {
            calculator.use();
        } catch (const char *msg) {
            cout << "There's something went wrong.\n";
            cout << "Error Message : " << msg << "\n\n";
        }
        cout << "Do you want to continue using the calculator(y/n) ?";
        char x;
        cin >> x;
        x = tolower(x);
        flag = (x == 'y');
    }
    return 0;
}