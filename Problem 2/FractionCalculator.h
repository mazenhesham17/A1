//
// Created by Mazen Hesham on 4/27/2022.
//

#ifndef A1_FRACTIONCALCULATOR_H
#define A1_FRACTIONCALCULATOR_H

#include "Fraction.h"

class FractionCalculator {
private:
    Fraction A;
    Fraction B;
    Fraction M;
    bool prev;
public:
    FractionCalculator();

    void use();

    void operation();

    void comparing();

    void arithmetic();

};

#endif //A1_FRACTIONCALCULATOR_H
