# include <iostream>
# include "Fraction.h"

using namespace std;

class FractionCalculator {
private:
    Fraction A;
    Fraction B;
    Fraction M;
    bool prev;
public:
    FractionCalculator() { prev = false; }

    void use() {
        cout << "Do you want to use previous result(y/n) ?";
        char x;
        cin >> x;
        x = tolower(x);
        if (x == 'y') {
            if (prev) {
                A = M;
            } else {
                throw "there's no previous result.";
            }
            try {
                cout << "Please Enter the second fraction : ";
                cin >> B;
            } catch (const char *msg) {
                cout << "There's something went wrong.\n";
                cout << "Error Message : " << msg << "\n\n";
            }

        } else if (x == 'n') {
            try {
                cout << "Please Enter the first fraction : ";
                cin >> A;
            } catch (const char *msg) {
                cout << "There's something went wrong.\n";
                cout << "Error Message : " << msg << "\n\n";
            }
            try {
                cout << "Please Enter the second fraction : ";
                cin >> B;
            } catch (const char *msg) {
                cout << "There's something went wrong.\n";
                cout << "Error Message : " << msg << "\n\n";
            }
        } else {
            throw "Invalid Input.";
        }
        try {
            operation();
        } catch (const char *msg) {
            cout << "There's something went wrong.\n";
            cout << "Error Message : " << msg << "\n\n";
        }
    }

    void operation() {
        cout << "1. Comparing\n";
        cout << "2. Arthimitc\n";
        cout << "Please choose the type of operation you want to use : ";
        int x;
        cin >> x;
        if (x == 1) {
            try {
                comparing();
            } catch (const char *msg) {
                cout << "There's something went wrong.\n";
                cout << "Error Message : " << msg << "\n\n";
            }
        } else if (x == 2) {
            try {
                arithmetic();
            } catch (const char *msg) {
                cout << "There's something went wrong.\n";
                cout << "Error Message : " << msg << "\n\n";
            }
        } else {
            throw "Invalid Input.";
        }
    }

    void comparing() {
        cout << "Please enter one of the comparing operators (<,>,==,<=,>=) : ";
        string x;
        cin >> x;
        bool result = false;
        if (x == "<") {
            result = (A < B);
        } else if (x == ">") {
            result = (A > B);
        } else if (x == ">=") {
            result = (A >= B);
        } else if (x == "<=") {
            result = (A <= B);
        } else if (x == "==") {
            result = (A == B);
        } else {
            throw "Invalid Input.";
        }
        cout << A << ' ' << x << ' ' << B << (result ? " is True." : " is False.") << '\n';
    }

    void arithmetic() {
        cout << "Please enter one of the arithmetic operators (+,-,*,/) : ";
        char x;
        cin >> x;
        bool result = false;
        if (x == '+') {
            M = A + B;
        } else if (x == '-') {
            M = A - B;
        } else if (x == '*') {
            M = A * B;
        } else if (x == '/') {
            M = A / B;
        } else {
            throw "Invalid Input.";
        }
        cout << A << ' ' << x << ' ' << B << " = " << M << '\n';
        prev = true;
    }

};

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