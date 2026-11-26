// ============================================================
// ACTIVITY 3: MEMORY LEAKS AND THE FIX
// The first function intentionally leaks memory for demonstration.
// The second function shows the correct cleanup with delete.
// ============================================================
#include <iostream>
using namespace std;

void createLeak() {
    int* ptr = new int(42);
    cout << "Inside leaking function. The value is: " << *ptr << endl;
    cout << "Memory allocated at address: " << static_cast<void*>(ptr) << endl;

    // INTENTIONAL LEAK FOR DEMONSTRATION:
    // Do not use this pattern in real programs. The memory is not deleted.
}

void fixLeak() {
    int* ptr = new int(42);
    cout << "Inside fixed function. Value: " << *ptr << endl;
    cout << "Memory allocated at address: " << static_cast<void*>(ptr) << endl;

    delete ptr;
    ptr = nullptr;
    cout << "Memory has been successfully freed." << endl;
}

int main() {
    cout << "Calling function that leaks memory..." << endl;
    createLeak();
    cout << "Function finished. The memory is now leaked." << endl;

    cout << "\n--- Testing the Fix ---" << endl;
    fixLeak();

    return 0;
}
