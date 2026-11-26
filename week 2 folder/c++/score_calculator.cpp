/*
 * WEEK 2 - STUDENT SCORE CALCULATOR (C++ VERSION)
 * Variables, data types, input/output, arithmetic, validation and decisions.
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

const int TEST_COUNT = 4;
const int MAX_SCORE = 100;

int readScore(int testNumber) {
    int score;
    while (true) {
        cout << "Enter score for Test " << testNumber
             << " (0-" << MAX_SCORE << "): ";
        if (cin >> score && score >= 0 && score <= MAX_SCORE) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return score;
        }
        cout << "Invalid score. Enter a whole number from 0 to "
             << MAX_SCORE << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    string studentName, course;
    int scores[TEST_COUNT], totalScore = 0, highestScore;
    double average, percentage;
    char grade;

    cout << "Enter student name: ";
    getline(cin, studentName);
    cout << "Enter course (BBIT/BCS): ";
    getline(cin, course);

    for (int i = 0; i < TEST_COUNT; ++i) {
        scores[i] = readScore(i + 1);
        totalScore += scores[i];
    }

    average = totalScore / 4.0;
    percentage = (totalScore / 400.0) * 100.0;

    highestScore = scores[0];
    for (int i = 1; i < TEST_COUNT; ++i) {
        if (scores[i] > highestScore) highestScore = scores[i];
    }

    if (percentage >= 90.0) grade = 'A';
    else if (percentage >= 80.0) grade = 'B';
    else if (percentage >= 70.0) grade = 'C';
    else if (percentage >= 60.0) grade = 'D';
    else grade = 'F';

    cout << fixed << setprecision(2);
    cout << "\n========================================\n";
    cout << "          STUDENT REPORT CARD\n";
    cout << "========================================\n";
    cout << "Student:       " << studentName << '\n';
    cout << "Course:        " << course << "\n\n";
    for (int i = 0; i < TEST_COUNT; ++i)
        cout << "Test " << i + 1 << ":         " << scores[i]
             << "/" << MAX_SCORE << '\n';
    cout << "\nTotal:          " << totalScore << "/400\n";
    cout << "Average:        " << average << '\n';
    cout << "Percentage:     " << percentage << "%\n";
    cout << "Highest score:  " << highestScore << "/" << MAX_SCORE << '\n';
    cout << "Grade:          " << grade << '\n';
    cout << "Result:         " << (percentage >= 50.0 ? "PASS" : "FAIL") << '\n';
    cout << "========================================\n";
    return 0;
}
