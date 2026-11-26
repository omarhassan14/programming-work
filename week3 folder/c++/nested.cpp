// PROGRAM 2: Analyse all paths through nested conditionals
#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cout << "Enter three different numbers: ";
    if (!(cin >> a >> b >> c)) { cout << "Invalid input.\n"; return 1; }
    if (a == b || b == c || a == c) { cout << "Please enter three different numbers.\n"; return 1; }
    if (a > b) {
        if (b > c) cout << "Path 1: a > b > c\n";
        else if (a > c) cout << "Path 2: a > c > b\n";
        else cout << "Path 3: c > a > b\n";
    } else {
        if (a > c) cout << "Path 4: b > a > c\n";
        else if (b > c) cout << "Path 5: b > c > a\n";
        else cout << "Path 6: c > b > a\n";
    }
    return 0;
}
