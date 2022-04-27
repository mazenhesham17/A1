# include <iostream>
# include "MatrixCalculator.h"

using namespace std;

int main() {
    bool flag = true;
    while (flag) {
        MatrixCalculator calculator;
        try {
            calculator.showMenu();
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
