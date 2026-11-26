// ============================================================
// WEEK 6 - ACTIVITY 3A: C-STRING VERSION (C++)
// ============================================================
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char name[50];

    cout << "Enter your name: ";
    cin.getline(name, 50);

    cout << "Name: " << name << endl;
    cout << "Length: " << strlen(name) << endl;

    if (name[0] != '\0') {
        cout << "First character: " << name[0] << endl;
    } else {
        cout << "First character: (empty)" << endl;
    }

    char copy[50];
    strcpy(copy, name); // Safe here because both arrays have capacity 50.
    cout << "Copy: " << copy << endl;
    return 0;
}
