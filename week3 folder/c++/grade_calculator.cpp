// PROGRAM 4: Grade calculator, plus/minus modifiers, messages, multiple students
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

char baseGrade(double score) {
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    if (score >= 60) return 'D';
    return 'F';
}
char gradeModifier(double score, char grade) {
    if (grade == 'F') return ' ';
    int lastDigit = static_cast<int>(score) % 10;
    if (grade == 'A') {
        if (score >= 97) return '+';
        if (score < 93) return '-';
    } else {
        if (lastDigit >= 7) return '+';
        if (lastDigit <= 3) return '-';
    }
    return ' ';
}
string messageFor(char grade) {
    switch (grade) {
        case 'A': return "Excellent work!";
        case 'B': return "Good job!";
        case 'C': return "Satisfactory.";
        case 'D': return "Needs improvement.";
        default: return "Please seek help.";
    }
}
int main() {
    int count;
    cout << "===== GRADE CALCULATOR =====\nHow many students? ";
    if (!(cin >> count) || count < 1) { cout << "Enter a positive number of students.\n"; return 1; }
    int totals[5] = {0, 0, 0, 0, 0}; // A, B, C, D, F
    const char grades[5] = {'A', 'B', 'C', 'D', 'F'};
    for (int i = 0; i < count; ++i) {
        string name;
        double score;
        cout << "\nStudent " << i + 1 << " name: ";
        cin >> ws; getline(cin, name);
        cout << "Enter percentage score (0-100): ";
        if (!(cin >> score) || score < 0 || score > 100) {
            cout << "Invalid score! Must be between 0 and 100. This student was not counted.\n";
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            --i; continue;
        }
        char grade = baseGrade(score);
        char modifier = gradeModifier(score, grade);
        int index = grade == 'A' ? 0 : grade == 'B' ? 1 : grade == 'C' ? 2 : grade == 'D' ? 3 : 4;
        ++totals[index];
        cout << "\n===== GRADE REPORT =====\nStudent: " << name
             << "\nScore: " << fixed << setprecision(1) << score << "%\nGrade: " << grade;
        if (modifier != ' ') cout << modifier;
        cout << "\n" << messageFor(grade) << "\n";
    }
    cout << "\n===== CLASS SUMMARY =====\n";
    for (int i = 0; i < 5; ++i) cout << grades[i] << " grades: " << totals[i] << '\n';
    return 0;
}
