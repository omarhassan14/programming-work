// PROGRAM 1: Event Eligibility Checker (logical operators)
#include <iostream>
using namespace std;

int main() {
    int age;
    bool hasTicket, isMember, isBanned, hasParent;

    cout << "Enter age: ";
    if (!(cin >> age) || age < 0) { cout << "Invalid age.\n"; return 1; }
    cout << "Do you have a ticket? (1 yes, 0 no): "; cin >> hasTicket;
    cout << "Are you a member? (1 yes, 0 no): "; cin >> isMember;
    cout << "Are you banned? (1 yes, 0 no): "; cin >> isBanned;
    cout << "Do you have a parent/guardian? (1 yes, 0 no): "; cin >> hasParent;

    // Under-16 visitors need a parent. Everyone must not be banned.
    bool ageRule = (age >= 16) || hasParent;
    bool canEnter = ageRule && !isBanned &&
                    ((age >= 18 && hasTicket) || isMember);

    if (canEnter) cout << "You can enter the event!\n";
    else cout << "Sorry, you cannot enter.\n";
    return 0;
}
