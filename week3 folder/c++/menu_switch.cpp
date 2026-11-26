// PROGRAM 3B: Same menu using switch
#include <iostream>
using namespace std;
int main() {
    int choice;
    cout << "Menu:\n1. Start\n2. Load\n3. Settings\n4. Exit\nChoice: ";
    if (!(cin >> choice)) { cout << "Invalid input!\n"; return 1; }
    switch (choice) {
        case 1: cout << "Starting game...\n"; break;
        case 2: cout << "Loading game...\n"; break;
        case 3: cout << "Opening settings...\n"; break;
        case 4: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n"; break;
    }
    return 0;
}
