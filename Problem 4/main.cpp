#include <iostream>
#include <map>
#include <chrono>

using namespace std;

void RecPermute(string soFar, string rest) {
    if (rest == "") {// No more characters
        cout << soFar << endl; // Print the word

    } else { // Still more chars
        // For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            RecPermute(next, remaining);
        }
    }
}

map<string, bool> mp;

// "wrapper" function
void wrapper(string soFar, string rest) {
    // check if I visit the same state before
    if (mp[soFar])
        return;
    mp[soFar] = true;
    if (rest == "") { // No more characters
        cout << soFar << endl; // Print the word

    } else { // Still more chars
        // For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            wrapper(next, remaining);
        }
    }
}


void ListPermutations(string s) {

    auto start = chrono::steady_clock::now();
    RecPermute("", s);
    auto end = chrono::steady_clock::now();

    double diff1 = chrono::duration<double, milli>(end - start).count();

    // separate the two outputs
    for (int i = 0; i < s.size(); ++i) {
        cout << '-';
    }
    cout << '\n';

    start = chrono::steady_clock::now();
    wrapper("", s);
    end = chrono::steady_clock::now();

    double diff2 = chrono::duration<double, milli>(end - start).count();


    cout << "Time Taken by RecPermute Function : " << diff1 << " ms\n";
    cout << "Time Taken by Wrapper Function : " << diff2 << " ms\n";

}

int main() {
    string s = "makka";
    ListPermutations(s);
    return 0;
}
