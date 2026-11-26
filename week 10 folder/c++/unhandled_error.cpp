// ACTIVITY 2: IGNORING FILE ERRORS IN C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream myFile("missing_file.txt");

    // INTENTIONALLY OMITTED: check whether myFile opened successfully.
    string data;

    cout << "Attempting to read from missing file..." << endl;
    myFile >> data;

    cout << "Data read: " << data << endl;
    cout << "Program continued running without crashing." << endl;
    return 0;
}
