// ============================================================
// ACTIVITY 3: EVALUATING CLASS DESIGN
// ============================================================
#include <iostream>
using namespace std;

class BadBankAccount {
public:
    double balance;

    BadBankAccount() : balance(0.0) {}
};

class GoodBankAccount {
private:
    double balance;

public:
    GoodBankAccount() : balance(0.0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Deposit rejected: amount must be positive." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    cout << "--- Testing BAD Design ---" << endl;
    BadBankAccount badAccount;
    badAccount.balance = -5000;
    cout << "Bad Account Balance: " << badAccount.balance << endl;

    cout << "\n--- Testing GOOD Design ---" << endl;
    GoodBankAccount goodAccount;
    goodAccount.deposit(1000);
    cout << "Good Account Balance: " << goodAccount.getBalance() << endl;

    return 0;
}
