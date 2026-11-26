// ACTIVITY 4: ROBUST CSV PARSER IN C++
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

int main() {
    ifstream file("students.csv");
    if (!file.is_open()) {
        cerr << "Error: Could not find students.csv!" << endl;
        return 1;
    }

    string line;
    cout << "--- Processing Student Records ---" << endl;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string name, scoreStr1, scoreStr2, scoreStr3, extra;

        if (!getline(ss, name, ',') ||
            !getline(ss, scoreStr1, ',') ||
            !getline(ss, scoreStr2, ',') ||
            !getline(ss, scoreStr3, ',') ||
            getline(ss, extra, ',')) {
            cout << "WARNING: Skipping malformed CSV line." << endl;
            continue;
        }

        try {
            size_t p1, p2, p3;
            int s1 = stoi(scoreStr1, &p1);
            int s2 = stoi(scoreStr2, &p2);
            int s3 = stoi(scoreStr3, &p3);

            // Reject trailing non-whitespace characters and out-of-range scores.
            auto onlyWhitespaceRemains = [](const string& value, size_t pos) {
                return value.find_first_not_of(" \t\r\n", pos) == string::npos;
            };

            if (!onlyWhitespaceRemains(scoreStr1, p1) ||
                !onlyWhitespaceRemains(scoreStr2, p2) ||
                !onlyWhitespaceRemains(scoreStr3, p3) ||
                s1 < 0 || s1 > 100 || s2 < 0 || s2 > 100 ||
                s3 < 0 || s3 > 100) {
                throw invalid_argument("Invalid score");
            }

            double average = (s1 + s2 + s3) / 3.0;
            cout << name << " -> Average: " << average << endl;
        } catch (const invalid_argument&) {
            cout << "WARNING: Skipping malformed record for " << name
                 << " (Invalid score data)." << endl;
        } catch (const out_of_range&) {
            cout << "WARNING: Skipping malformed record for " << name
                 << " (Score out of range)." << endl;
        }
    }

    if (file.bad()) {
        cerr << "Error while reading students.csv" << endl;
        return 1;
    }

    file.close();
    cout << "\n--- Processing Complete ---" << endl;
    return 0;
}
