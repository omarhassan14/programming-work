/*
 * WEEK 1 - ABOUT ME (C++)
 * Six required questions plus the Week 1 C++ challenges:
 * - Ask favourite food and dream job
 * - Validate an empty name
 * - Print a personalized closing message
 * - Format the output neatly
 */
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    string name, course, hobby, reason, expectation, definition;
    string favouriteFood, dreamJob;

    cout << "========================================" << endl;
    cout << " WELCOME TO YOUR FIRST C++ PROGRAM!" << endl;
    cout << "========================================" << endl << endl;

    cout << "1. What is your name? ";
    getline(cin, name);
    if (name.empty()) {
        cout << "You didn't enter a name!" << endl;
    }

    cout << "2. What course are you doing? (BBIT/BCS): ";
    getline(cin, course);

    cout << "3. What is your hobby? ";
    getline(cin, hobby);

    cout << "4. Why did you choose this course? ";
    getline(cin, reason);

    cout << "5. What do you expect to learn in programming? ";
    getline(cin, expectation);

    cout << "6. In your own words, what is programming? ";
    getline(cin, definition);

    // Week 1 Challenge 1: add two more questions.
    cout << "7. What is your favourite food? ";
    getline(cin, favouriteFood);

    cout << "8. What is your dream job? ";
    getline(cin, dreamJob);

    cout << "\n========================================" << endl;
    cout << "          YOUR PROFILE SUMMARY          " << endl;
    cout << "========================================" << endl;
    cout << "Name:             " << name << endl;
    cout << "Course:           " << course << endl;
    cout << "Hobby:            " << hobby << endl;
    cout << "Reason:           " << reason << endl;
    cout << "Expectation:      " << expectation << endl;
    cout << "Programming is:   " << definition << endl;
    cout << "Favourite food:   " << favouriteFood << endl;
    cout << "Dream job:        " << dreamJob << endl;
    cout << "========================================" << endl;
    cout << "Great job, " << name
         << "! You are on your way to becoming a programmer!" << endl;
    cout << "========================================" << endl;

    return 0;
}
