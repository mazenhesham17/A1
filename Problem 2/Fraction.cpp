#include "Fraction.h"
#include <iostream>

using namespace std;

// greatest common divisor
int gcd(int x, int y) {
    return (y ? gcd(y, x % y) : x);
}

// least common multiplayer
int lcm(int x, int y) {
    return (x / gcd(x, y)) * y;
}

void Fraction::simplify() {
    bool sign = ((numerator < 0) ^ (denominator < 0));
    numerator = abs(numerator);
    denominator = abs(denominator);
    int common = gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;
    numerator *= (sign ? -1 : 1);
}

Fraction::Fraction(int x, int y) {
    numerator = x;
    denominator = y;
    simplify();
}

ostream &operator<<(ostream &os, const Fraction &ob) {
    os << ob.numerator << '/' << ob.denominator << ' ';
    return os;
}

istream &operator>>(istream &is, Fraction &ob) {
    is >> ob.numerator >> ob.denominator;
    if (ob.denominator == 0)
        throw "The denominator cannot be zero";
    ob.simplify();
    return is;
}

Fraction Fraction::operator+(const Fraction &ob) {
    Fraction temp;
    int common = lcm(denominator, ob.denominator);
    temp.numerator = (numerator * common) / denominator + (ob.numerator * common) / ob.denominator;
    temp.denominator = common;
    temp.simplify();
    return temp;
}

Fraction Fraction::operator-(const Fraction &ob) {
    Fraction temp;
    int common = lcm(denominator, ob.denominator);
    temp.numerator = (numerator * common) / denominator - (ob.numerator * common) / ob.denominator;
    temp.denominator = common;
    temp.simplify();
    return temp;
}

Fraction Fraction::operator*(const Fraction &ob) {
    Fraction temp;
    temp.numerator = numerator * ob.numerator;
    temp.denominator = denominator * ob.denominator;
    temp.simplify();
    return temp;
}

Fraction Fraction::operator/(const Fraction &ob) {
    Fraction temp;
    temp.numerator = numerator * ob.denominator;
    temp.denominator = denominator * ob.numerator;
    temp.simplify();
    return temp;
}


bool Fraction::operator==(Fraction &ob) {
    simplify();
    ob.simplify();
    return (numerator == ob.numerator && denominator == ob.denominator);
}

bool Fraction::operator<=(Fraction &ob) {
    simplify();
    ob.simplify();
    int common = lcm(denominator, ob.denominator);
    int x = common / denominator * (numerator < 0 ? -1 : 1);
    int y = common / ob.denominator * (ob.numerator < 0 ? -1 : 1);
    return (x <= y);
}

bool Fraction::operator>=(Fraction &ob) {
    simplify();
    ob.simplify();
    int common = lcm(denominator, ob.denominator);
    int x = common / denominator * (numerator < 0 ? -1 : 1);
    int y = common / ob.denominator * (ob.numerator < 0 ? -1 : 1);
    return (x >= y);
}

bool Fraction::operator<(Fraction &ob) {
    simplify();
    ob.simplify();
    int common = lcm(denominator, ob.denominator);
    int x = common / denominator * (numerator < 0 ? -1 : 1);
    int y = common / ob.denominator * (ob.numerator < 0 ? -1 : 1);
    return (x < y);
}

bool Fraction::operator>(Fraction &ob) {
    simplify();
    ob.simplify();
    int common = lcm(denominator, ob.denominator);
    int x = common / denominator * (numerator < 0 ? -1 : 1);
    int y = common / ob.denominator * (ob.numerator < 0 ? -1 : 1);
    return (x > y);
}