#ifndef FRACTION_H
#define FRACTION_H
# include <iostream>

using namespace std ;

class Fraction
{
private:
    int numerator;   // top
    int denominator; // bottom
public:
    void simplify();
    Fraction(int = 0, int = 1);
    friend ostream &operator<<(ostream &, const Fraction &);
    friend istream &operator>>(istream &, Fraction &);
    Fraction operator+(const Fraction &);
    Fraction operator-(const Fraction &);
    Fraction operator*(const Fraction &);
    Fraction operator/(const Fraction &);
    // < , > , <= , >= , ==
    bool operator==(Fraction &);
    bool operator<=(Fraction &);
    bool operator>=(Fraction &);
    bool operator<(Fraction &);
    bool operator>(Fraction &);
};

#endif // FRACTION_H
