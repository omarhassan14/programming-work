// ACTIVITY 3: RETURN CODES VS EXCEPTIONS IN C++
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

bool readFileWithReturnCode(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    // Example placeholder for reading file contents.
    return true;
}

void readFileWithException(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("File not found: " + filename);
    }
    // Example placeholder for reading file contents.
}

int main() {
    cout << "--- Testing Return Code Strategy ---" << endl;
    if (!readFileWithReturnCode("data.txt")) {
        cout << "Return Code: Handled error gracefully. Program continues." << endl;
    }

    cout << "\n--- Testing Exception Strategy ---" << endl;
    try {
        readFileWithException("data.txt");
    } catch (const runtime_error& e) {
        cout << "Exception Caught: " << e.what() << endl;
        cout << "Exception Strategy: The error was caught and handled." << endl;
    }

    return 0;
}
