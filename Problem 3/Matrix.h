#ifndef A1_MATRIX_H
#define A1_MATRIX_H

#include <iostream>

using namespace std;

template<class T>
class Matrix {
private:
    T **mat;
    int row;
    int col;
public:
    int getRow();

    int getCol();

    Matrix(int = 0, int = 0);

    Matrix(const Matrix<T> &);

    template<class Te>
    friend ostream &operator<<(ostream &, const Matrix<Te> &);

    template<class Te>
    friend istream &operator>>(istream &, Matrix<Te> &);

    Matrix<T> operator+(const Matrix<T> &);

    Matrix<T> operator-(const Matrix<T> &);

    Matrix<T> operator*(const Matrix<T> &);

    Matrix<T> operator=(const Matrix<T> &);

    Matrix<T> transpose();

    ~Matrix<T>();

};

#endif //A1_MATRIX_H
