// ============================================================
// ACTIVITY 3: EVALUATING STRUCT DESIGN IN C
// ============================================================
#include <stdio.h>

struct BadBankAccount {
    double balance;
};

struct GoodBankAccount {
    double balance; // C cannot make this member private.
};

void goodDeposit(struct GoodBankAccount *acc, double amount) {
    if (amount > 0) {
        acc->balance += amount;
    } else {
        printf("Deposit rejected: amount must be positive.\n");
    }
}

int main(void) {
    printf("--- Testing BAD Design ---\n");
    struct BadBankAccount badAccount = {100.0};
    badAccount.balance = -5000.00;
    printf("Bad Account Balance: %.2f\n", badAccount.balance);

    printf("\n--- Testing GOOD Design ---\n");
    struct GoodBankAccount goodAccount = {100.0};
    goodDeposit(&goodAccount, 500.00);
    printf("Good Account Balance: %.2f\n", goodAccount.balance);

    // C structs do not enforce privacy: code could still directly change
    // goodAccount.balance. The safe function is a programming convention.
    return 0;
}
