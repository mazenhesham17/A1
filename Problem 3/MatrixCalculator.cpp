#include "MatrixCalculator.h"

#include <iostream>

using namespace std;

void MatrixCalculator::showMenu() {
    cout << "Welcome to DS Matrix Calculator.\n";
    cout << "1. Perform Addition\n";
    cout << "2. Perform Subtraction\n";
    cout << "3. Perform Multiplication\n";
    cout << "4. Matrix Transpose\n";
    cout << "Please enter number to choose from the menu : ";
    int x;
    cin >> x;
    input(x);
}

void MatrixCalculator::input(int x) {
    if (x == 1 || x == 2 || x == 3) {
        cout << "Please Enter the First Matrix dimensions (n,m): ";
        int n, m;
        cin >> n >> m;
        Matrix<int> A(n, m);
        cout << "Please Enter the First Matrix :\n";
        cin >> A;
        cout << "Please Enter the Second Matrix dimensions (n,m): ";
        cin >> n >> m;
        Matrix<int> B(n, m);
        cout << "Please Enter the Second Matrix :\n";
        cin >> B;
        switch (x) {
            case 1:
                addition(A, B);
                break;
            case 2:
                subtraction(A, B);
                break;
            case 3:
                multiplication(A, B);
                break;
        }
    } else {
        if (x == 4) {
            cout << "Please Enter the Matrix dimensions (n,m): ";
            int n, m;
            cin >> n >> m;
            Matrix<int> A(n, m);
            cout << "Please Enter the Matrix :\n";
            cin >> A;
            transpose(A);
        } else {
            throw "Invalid Input.\n";
        }
    }
}


void MatrixCalculator::addition(Matrix<int> &A, Matrix<int> &B) {
    try {
        cout << "The result is \n";
        cout << A + B;
    } catch (const char *msg) {
        cout << "There's something went wrong.\n";
        cout << "Error Message : " << msg << "\n\n";
    }
}

void MatrixCalculator::subtraction(Matrix<int> &A, Matrix<int> &B) {
    try {
        cout << "The result is \n";
        cout << A - B;
    } catch (const char *msg) {
        cout << "There's something went wrong.\n";
        cout << "Error Message : " << msg << "\n\n";
    }
}


void MatrixCalculator::multiplication(Matrix<int> &A, Matrix<int> &B) {
    try {
        cout << "The result is \n";
        cout << A * B;
    } catch (const char *msg) {
        cout << "There's something went wrong.\n";
        cout << "Error Message : " << msg << "\n\n";
    }
}

void MatrixCalculator::transpose(Matrix<int> &M) {
    try {
        cout << "The result is \n";
        cout << M.transpose();
    } catch (const char *msg) {
        cout << "There's something went wrong.\n";
        cout << "Error Message : " << msg << "\n\n";
    }
}

