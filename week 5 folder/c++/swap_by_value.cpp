// WEEK 5 - ACTIVITY 1: PASS-BY-VALUE AND PASS-BY-REFERENCE
#include <iostream>
using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByValue: a = " << a << ", b = " << b << endl;
}

void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;

    cout << "Before swapByValue: x = " << x << ", y = " << y << endl;
    swapByValue(x, y);
    cout << "After swapByValue:  x = " << x << ", y = " << y << endl;

    cout << "\\nNow swapping the originals using references:" << endl;
    swapByReference(x, y);
    cout << "After swapByReference: x = " << x << ", y = " << y << endl;
    return 0;
}
