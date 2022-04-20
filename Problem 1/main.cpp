#include <iostream>
#include <algorithm>

using namespace std;

class BigInt {
private:
    string number;
    bool negative;

public:
    BigInt() { negative = false; }

    BigInt(string value) {
        // check if the entered number is negative
        if (value.front() == '-') {
            // check if the entered string is valid number
            for (int i = 1; i < value.size(); ++i) {
                if (isdigit(value[i]) == false) {
                    throw "bad input!!";
                }
            }
            negative = true;
            value.erase(0, 1);
        } else {
            // check if the entered string is valid number
            for (int i = 0; i < value.size(); ++i) {
                if (isdigit(value[i]) == false) {
                    throw "bad input!!";
                }
            }
            negative = false;
        }
        number = value;
    }

    BigInt(int value) {
        negative = false;
        if (value < 0) {
            negative = true;
            value *= -1;
        }
        while (value) {
            number.push_back(static_cast<char>(value % 10 + '0'));
            value /= 10;
        }
        reverse(number.begin(), number.end());
    }

    friend ostream &operator<<(ostream &os, const BigInt &ob) {
        os << (ob.negative ? "-" : "") << ob.number << '\n';
        return os;
    }

    BigInt operator=(const BigInt &ob) {
        number = ob.number;
        negative = ob.negative;
        return *this;
    }

    int getSize() {
        return number.size();
    }

    // operator to check which is smaller without the comparison of the sign
    bool operator<(BigInt &ob) {
        if (ob.getSize() == getSize()) {
            for (int i = 0; i < ob.getSize(); ++i) {
                if (number[i] < ob.number[i]) {
                    return true;
                } else if (number[i] > ob.number[i]) {
                    return false;
                }
            }
            return true;
        } else {
            return getSize() < ob.getSize();
        }
    }

    bool operator==(BigInt &ob) {
        if (ob.getSize() == getSize()) {
            for (int i = 0; i < ob.getSize(); ++i) {
                if (ob.number[i] != number[i])
                    return false;
            }
            return true;
        } else {
            return false;
        }
    }

    BigInt operator+(BigInt &ob) {
        BigInt temp;
        // if both numbers have the same sign this mean we perform addation
        // the result sign will be the sign of any of them
        if (negative == ob.negative) {
            temp.negative = negative;
            int carry = 0;
            string s = number, t = ob.number;
            reverse(s.begin(), s.end());
            reverse(t.begin(), t.end());
            for (int i = 0; i < max(s.size(), t.size()); ++i) {
                // put value to each digit
                int a = (i < s.size() ? s[i] - '0' : 0);
                int b = (i < t.size() ? t[i] - '0' : 0);
                int sum = a + b + carry;
                carry = sum / 10;
                temp.number.push_back(static_cast<char>(sum % 10 + '0'));
            }
            // if we finished the operation and we have carry
            // we need to put one in the left
            if (carry == 1)
                temp.number.push_back('1');
            reverse(temp.number.begin(), temp.number.end());
            return temp;
        } else {
            // if they have diffrent signs this means we substarct them
            // the result sign will be the sign of the biggest number
            BigInt temp;
            if (ob == *this) {
                temp.negative = false;
                temp.number = "0";
            } else {
                string s, t;
                if (ob < *this) {
                    // this is the biggiset
                    temp.negative = this->negative;
                    s = number, t = ob.number;
                } else {
                    // ob is the biggest
                    temp.negative = ob.negative;
                    t = number, s = ob.number;
                }
                int carry = 0;
                // s is the bigger
                reverse(s.begin(), s.end());
                reverse(t.begin(), t.end());
                for (int i = 0; i < max(s.size(), t.size()); ++i) {
                    // put value to each digit
                    int a = (i < s.size() ? s[i] - '0' : 0);
                    int b = (i < t.size() ? t[i] - '0' : 0);
                    int sum = 0;
                    // check if we need to borrow from the neighbour digit
                    if (a + carry >= b) {
                        sum = (a + carry) - b;
                        carry = 0;
                    } else {
                        sum = (a + carry + 10) - b;
                        carry = -1;
                    }
                    temp.number.push_back(static_cast<char>(sum + '0'));
                }
                // we can't have leading zeros in our number so we remove them
                while (temp.number.back() == '0') {
                    temp.number.pop_back();
                }
                reverse(temp.number.begin(), temp.number.end());
            }
            return temp;
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++) {
        string s, t;
        cin >> s >> t;
        try {
            BigInt num1(s);
            BigInt num2(t);
            cout << "num1 = " << num1;
            cout << "num2 = " << num2;
            BigInt result = num1 + num2;
            cout << "num1 + num2 = " << result << '\n';
        }
        catch (const char *msg) {
            cout << "There's something went wrong.\n";
            cout << "Error Message : " << msg << "\n\n";
        }
    }
    return 0;
}
