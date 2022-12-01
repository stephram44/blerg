#include <iostream>
using namespace std;

// validates for integer input
int getInt(string prompt = "Enter integer: ") {
    int num = 0;
    cout << prompt;
    cin >> num;
    while (!cin || cin.peek() != '\n' ) {  
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid integer." << endl;
        cout << prompt;
        cin >> num;
    }
    cin.get();
    return num;
}

// validates for float input
float getFloat(string prompt = "Enter float: ") {
    float num = 0;
    cout << prompt;
    cin >> num;
    while (!cin || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid float." << endl;
        cout << prompt;
        cin >> num;
    }
    cin.get();
    return num;
}

// validates for string input
string getString(string prompt = "Enter a string: ") {
    string phrase = "";
    cout << prompt;
    getline(cin, phrase);
    while (phrase == "") {
        cout << "Error. No drink name was entered." << endl;
        cout << prompt;
        getline(cin, phrase);
    }
    return phrase;
}