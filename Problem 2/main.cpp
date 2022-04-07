# include <iostream>
# include "Fraction.h"

using namespace std ;

class  FractionCalculator {
private:
    Fraction M ;
    Fraction A ;
    Fraction B ;
public:
    void input(){
        char flag ;
        cout << "Do you want to use the previous result (y/n) ? " ;
        cin >> flag ;
        flag = tolower(flag) ;
        if ( flag == 'y' ){
            A = M ;
        }else if ( flag == 'n' ){
            cout << "Please enter the first Fraction : " ;
            try {
                cin >> A ;
            }catch (const char *msg)
            {
                cout << "There's something went wrong.\n";
                cout << "Error Message : " << msg << "\n\n";
            }
        }else{
            cout << "You Entered wrong value!!\n" ;
            exit(0) ;
        }

        cout << "Please enter the Second Fraction : " ;
        try {
            cin >> B ;
        }catch (const char *msg)
        {
            cout << "There's something went wrong.\n";
            cout << "Error Message : " << msg << "\n\n";
        }
        cout << "Please enter the operation you want to preform (+,-,*,/) : " ;
        char operation ;
        cin >> operation ;
        if ( operation == '+' ){
            M = A + B ;
        }else if ( operation == '-'){
            M = A - B ;
        }else if ( operation == '*'){
            M = A * B ;
        }else if ( operation == '/'){
            M = A / B ;
        }else{
            cout << "You Entered wrong value!!\n" ;
            exit(0) ;
        }
        cout << A << operation << ' ' << B << '=' << M << '\n' ;

    }
};

int main (){
    FractionCalculator c ;
    c.input() ;
    return 0 ;
}