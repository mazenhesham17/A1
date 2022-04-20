#include <iostream>
#include <vector>

using namespace std;

class PhoneDirectory {
private:
    struct Entry {
        string first_name;
        string last_name;
        string phone_number;

        Entry(string first, string last, string phone) : first_name(first), last_name(last), phone_number(phone) {}

        friend ostream &operator<<(ostream &os, const Entry &ob) {
            os << "First Name : " << ob.first_name << " Last Name : " << ob.last_name << " Phone : " << ob.phone_number
               << '\n';
            return os;
        }
    };

    vector<Entry> entries;

public:
    // default constructor
    PhoneDirectory() {}

    //parameterized constructor
    PhoneDirectory(string first, string last, string phone) {
        entries.push_back(Entry(first, last, phone));
    }

    //function that store the data the user entered
    void addEntry(string first, string last, string phone) {

        entries.push_back(Entry(first, last, phone));
    }

    //function that delete the data the user want by first name
    void delete_entry(string name) {
        bubble_sort();
        bool deleted = false;
        for (int i = 0; i < entries.size(); i++) {
            if (name == entries[i].first_name) {
                entries.erase(entries.begin() + i);
                deleted = true;
            }
        }
        if (deleted)
            cout << " deleted  successfully " << endl;
        else
            cout << " sorry this name not exist to delete ! " << endl;
    }

    //function that view the data the user want to show by first name
    void look_firstname(string name) {
        insertion_sort();
        bool found = false;
        for (int i = 0; i < entries.size(); i++) {
            if (entries[i].first_name == name) {

                cout << entries[i];
                found = true;
            }
        }
        if (found == false)
            cout << "sorry the name you entered not exist! " << endl;
    }

    //function that view the data the user want to show by phone number
    void look_phone(string x) {
        selection_Sort();
        bool found = false;
        for (int i = 0; i < entries.size(); i++) {
            if (entries[i].phone_number == x) {

                found = true;
                cout << entries[i];
                break;
            }

        }
        if (found == false)
            cout << "sorry the phone number not exist!" << endl;
    }

    //function that sort the date using insertion sort
    void insertion_sort() {
        for (int i = 1; i < entries.size(); i++) {
            Entry key = entries[i];
            int j;
            j = i - 1;
            while (j >= 0 && entries[j].first_name > key.first_name) {
                entries[j + 1] = entries[j];
                j = j - 1;
            }
            entries[j + 1] = key;
        }
    }

    //function that sort the date using selection sort
    void selection_Sort() {
        for (int i = 0, j, least; i < entries.size(); i++) {

            for (j = i + 1, least = i; j < entries.size(); j++) {
                if (entries[j].first_name < entries[least].first_name)
                    least = j;
            }
            swap(entries[i], entries[least]);
        }
    }

    //function that sort the date using bubble sort
    void bubble_sort() {
        for (int i = 0; i < entries.size() - 1; i++) {

            for (int j = entries.size() - 1; j > i; --j)
                if (entries[j].first_name < entries[j - 1].first_name) {
                    swap(entries[j], entries[j - 1]);
                }
        }
    }

    void print() {
        for (auto &entry: entries) {
            cout << entry;
        }
    }


};

int main() {

    PhoneDirectory directory;
    bool flag = true;
    while (flag) {
        cout << "1.Add an entry to the directory " << endl;
        cout << "2.Look up a phone number " << endl;
        cout << "3.Look up by first name " << endl;
        cout << "4.Delete an entry from the directory " << endl;
        cout << "5.List All entries in phone directory " << endl;
        cout << "6.Exit form this program " << endl;
        cout << "please choose number : ";
        int n;
        cin >> n;
        if (n == 1) {
            string first, last, phone;
            cout << "please enter first name : ";
            cin >> first;
            cout << "please enter last name : ";
            cin >> last;
            cout << "please enter phone number : ";
            cin >> phone;
            directory.addEntry(first, last, phone);
            cout << "__________________________" << endl;
        } else if (n == 2) {
            cout << "please enter the phone number : ";
            string x;
            cin >> x;
            directory.look_phone(x);
            cout << "__________________________" << endl;

        } else if (n == 3) {
            cout << "please enter the first name : ";
            string name;
            cin >> name;
            directory.look_firstname(name);
            cout << "__________________________" << endl;

        } else if (n == 4) {
            cout << "please enter the first name : ";
            string name;
            cin >> name;
            directory.delete_entry(name);
            cout << "__________________________" << endl;

        } else if (n == 5) {
            cout << "choose the type of sorting you want : " << endl;
            cout << "1.insertion" << endl << "2.selection" << endl << "3.bubble" << endl;
            int m;
            cin >> m;
            if (m == 1) {
                directory.insertion_sort();
            } else if (m == 2) {
                directory.selection_Sort();
            } else if (m == 3) {
                directory.bubble_sort();
            } else {
                cout << "you chose invalid type !" << endl;
            }
            directory.print();
        } else if (n != 6) {
            cout << "you chose invalid value !" << endl;
        }
        flag = (n != 6);
    }

    return 0;
}
