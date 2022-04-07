#include <iostream>
#include <map>
#include "time.h"
#include <iomanip>

using namespace std;

void RecPermute(string soFar, string rest)
{
    if (rest == "") {// No more characters
        cout << soFar << endl ; // Print the word

    }
    else { // Still more chars
        // For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining);
        }
    }
}


map<string,bool> mp1 ;

// "wrapper" function
void wrapper1(string soFar, string rest)
{
    // check if i printed the word before
    if (rest == "" && !mp1[soFar]){ // No more characters
        cout << soFar << endl ; // Print the word
        mp1[soFar] = true ;
    }
    else { // Still more chars
        // For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            wrapper1(next, remaining);
        }
    }
}


map<string,bool> mp2 ;

// "wrapper" function
void wrapper2(string soFar, string rest)
{
    // check if i vis the same state before
    if (mp2[soFar])
        return;
    mp2[soFar] = true ;
    if (rest == "" ){ // No more characters
        cout << soFar << endl ; // Print the word

    }
    else { // Still more chars
        // For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            wrapper2(next, remaining);
        }
    }
}


void ListPermutations(string s) {
    time_t st , en ;
    double d = 0 ;
    time(&st) ;
    RecPermute("",s) ;
    time(&en) ;
    d = (double(en-st)*1e3) ;
    cout << "Time Taken by RecPermute Function : " << setprecision(10) << d << " msec.\n" ;
    time(&st) ;
    wrapper1("",s) ;
    time(&en) ;
    d = (double(en-st)*1e3) ;
    cout << "Time Taken by First Wrapper Function : " << setprecision(10) << d << " msec.\n" ;
    time(&st) ;
    wrapper2("",s) ;
    time(&en) ;
    d = (double(en-st)*1e3) ;
    cout << "Time Taken by Second Wrapper Function : " << setprecision(10) << d << " msec.\n" ;
}

int main() {
    string s = "makka" ;
    ListPermutations(s) ;
    return 0 ;
}
