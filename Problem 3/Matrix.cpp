#include "Matrix.h"

using namespace std;

template<class T>
int Matrix<T>::getRow() {
    return row;
}

template<class T>
int Matrix<T>::getCol() {
    return col;
}

template<class T>
Matrix<T>::Matrix(int _row, int _col) {
    row = _row, col = _col;
    mat = new T *[row];
    for (int i = 0; i < row; i++) {
        mat[i] = new T[col];
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix<T> &ob) {
    mat = nullptr;
    row = ob.row, col = ob.col;
    mat = new T *[row];
    for (int i = 0; i < row; i++) {
        mat[i] = new T[col];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            mat[i][j] = ob.mat[i][j];
        }
    }
}

template<class T>
Matrix<T> Matrix<T>::operator=(const Matrix<T> &ob) {
    mat = nullptr;
    row = ob.row, col = ob.col;
    mat = new T *[row];
    for (int i = 0; i < row; i++) {
        mat[i] = new T[col];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            mat[i][j] = ob.mat[i][j];
        }
    }
    return *this;
}


template<class T>
ostream &operator<<(ostream &os, const Matrix<T> &ob) {
    for (int i = 0; i < ob.row; i++) {
        for (int j = 0; j < ob.col; j++) {
            os << ob.mat[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

template<class T>
istream &operator>>(istream &is, Matrix<T> &ob) {
    for (int i = 0; i < ob.row; i++) {
        for (int j = 0; j < ob.col; j++) {
            is >> ob.mat[i][j];
        }
    }
    return is;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &ob) {
    if (ob.row == row && ob.col == col) {
        Matrix<T> temp(row, col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                temp.mat[i][j] = mat[i][j] + ob.mat[i][j];
            }
        }
        return temp;
    } else {
        throw "can not preform the addition.";
    }
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &ob) {
    if (ob.row == row && ob.col == col) {
        Matrix<T> temp(row, col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                temp.mat[i][j] = mat[i][j] - ob.mat[i][j];
            }
        }
        return temp;
    } else {
        throw "can not preform the subtraction.";
    }
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &ob) {
    if (col == ob.row) {
        Matrix<T> temp(row, ob.col);
        int n = row, m = ob.col;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                temp.mat[i][j] = 0;
                for (int k = 0; k < col; ++k) {
                    temp.mat[i][j] += mat[i][k] * ob.mat[k][j];
                }
            }
        }
        return temp;
    } else {
        throw "can not preform the multiplication.";
    }
}

template<class T>
Matrix<T> Matrix<T>::transpose() {
    Matrix<T> temp(col, row);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            temp.mat[j][i] = mat[i][j];
        }
    }
    *this = temp;
    return *this;
}

template<class T>
Matrix<T>::~Matrix<T>() {
    for (int i = 0; i < row; i++) {
        delete[] mat[i];
    }
    delete[] mat;
    mat = nullptr;
}