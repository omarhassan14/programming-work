// ============================================================
// WEEK 6 - ACTIVITY 4: STUDENT SCORE ANALYZER (C++)
// ============================================================
#include <iostream>
#include <iomanip>
using namespace std;

double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return static_cast<double>(sum) / size;
}

void displayAboveAverage(int scores[], int size, double average) {
    bool found = false;
    cout << "\nScores above average (" << fixed << setprecision(2)
         << average << "):" << endl;

    for (int i = 0; i < size; i++) {
        if (scores[i] > average) {
            cout << " Score " << scores[i] << " at position " << i + 1 << endl;
            found = true;
        }
    }
    if (!found) {
        cout << " None" << endl;
    }
}

int main() {
    const int SIZE = 10;
    int scores[SIZE];

    cout << "Enter " << SIZE << " student scores (0-100):" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Score " << i + 1 << ": ";
        if (!(cin >> scores[i]) || scores[i] < 0 || scores[i] > 100) {
            cout << "Invalid score. Enter whole-number scores from 0 to 100." << endl;
            return 1;
        }
    }

    double average = calculateAverage(scores, SIZE);
    int highest = scores[0], lowest = scores[0];
    int highestPosition = 1, lowestPosition = 1, aboveCount = 0;

    for (int i = 0; i < SIZE; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
            highestPosition = i + 1;
        }
        if (scores[i] < lowest) {
            lowest = scores[i];
            lowestPosition = i + 1;
        }
        if (scores[i] > average) {
            aboveCount++;
        }
    }

    cout << "\n--- Results ---" << endl;
    cout << "Average score: " << fixed << setprecision(2) << average << endl;
    displayAboveAverage(scores, SIZE, average);
    cout << "\nHighest score: " << highest << " at position " << highestPosition << endl;
    cout << "Lowest score: " << lowest << " at position " << lowestPosition << endl;
    cout << "Number of scores above average: " << aboveCount << endl;
    return 0;
}
