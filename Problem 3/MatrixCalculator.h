
#ifndef A1_MATRIXCALCULATOR_H
#define A1_MATRIXCALCULATOR_H

# include "Matrix.h"
# include "Matrix.cpp"


class MatrixCalculator {
public:
    void showMenu();

    void input(int);

    void addition(Matrix<int> &, Matrix<int> &);

    void subtraction(Matrix<int> &, Matrix<int> &);

    void multiplication(Matrix<int> &, Matrix<int> &);

    void transpose(Matrix<int> &);
};


#endif //A1_MATRIXCALCULATOR_H
