// PROGRAM 3: Event admission (nested conditionals)
#include <stdio.h>
int main(void) {
    int age, hasTicket;
    printf("Enter age: "); if (scanf("%d", &age) != 1 || age < 0) return 1;
    printf("Has ticket? (1 for yes, 0 for no): "); if (scanf("%d", &hasTicket) != 1) return 1;
    if (age >= 18) {
        printf("Adult verified.\n");
        if (hasTicket) printf("Welcome to the event!\n");
        else printf("Please purchase a ticket at the door.\n");
    } else {
        printf("Minor detected.\n");
        if (age >= 12) printf("Teenager - needs guardian signature.\n");
        else printf("Child - must be accompanied by adult.\n");
    }
    return 0;
}
