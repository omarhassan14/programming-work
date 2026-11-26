// WEEK 5 - ACTIVITY 3: SIMPLE AND TAIL RECURSIVE FACTORIAL
#include <iostream>
using namespace std;

long long factorialRecursive(int n) {
    if (n <= 1) return 1;                 // Base case
    return n * factorialRecursive(n - 1);
}

long long factorialTail(int n, long long accumulator = 1) {
    if (n <= 1) return accumulator;       // Base case
    return factorialTail(n - 1, n * accumulator);
}

int main() {
    int num;
    cout << "Enter a whole number from 0 to 20: ";
    if (!(cin >> num) || num < 0 || num > 20) {
        cout << "Invalid input. Please enter a number from 0 to 20." << endl;
        return 1;
    }

    cout << "\\nUsing simple recursion:" << endl;
    cout << num << "! = " << factorialRecursive(num) << endl;

    cout << "\\nUsing tail recursion:" << endl;
    cout << num << "! = " << factorialTail(num) << endl;

    cout << "\\nBoth methods give the same answer." << endl;
    cout << "Simple recursion: clear mathematical structure." << endl;
    cout << "Tail recursion: carries the result in an accumulator." << endl;
    return 0;
}
