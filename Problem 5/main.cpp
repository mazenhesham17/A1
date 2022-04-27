#include <iostream>
#include <vector>

using namespace std;

class StudentName {
private:
    string name;
    vector<string> names;
public:
    //constructor
    StudentName(string _name) {
        string temp;
        name = _name;
        for (int i = 0; i < name.length(); i++) {
            if (isspace(name[i])) {
                names.push_back(temp);
                temp.clear();
            } else {
                temp.push_back(name[i]);
            }
        }
        names.push_back(temp);
        // copy last name until there is 2 spaces
        while (names.size() < 3) {
            names.push_back(names.back());
        }
    }

    //function that print the details of the name
    void printname() {
        int c = 1;
        for (int i = 0; i < names.size(); ++i) {
            cout << c << ") " << names[i] << endl;
            c++;
        }
    }

    //function that check if we can replace the name or not
    bool replace_username(int y, int z) {
        if (y > names.size() || z > names.size() || y < 1 || z < 1) {
            return false;
        }

        if (y <= names.size() && z <= names.size()) {
            swap(names[y - 1], names[z - 1]);
            return true;
        }
    }
};


int main() {
    freopen("input.txt", "r", stdin);
    int tests;
    cin >> tests;
    cin.ignore();
    for (int i = 0; i < tests; i++) {
        string s;
        getline(cin, s);
        StudentName studentName(s);
        bool flag = studentName.replace_username(1, 4);
        if (flag) {
            cout << "test " << i + 1 << " : " << "\nreplaced\n" << endl;
        } else {
            cout << "test " << i + 1 << " : " << "\ncannot be replaced\n" << endl;
        }
        studentName.printname();
    }
    return 0;
}

