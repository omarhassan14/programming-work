// ============================================================
// WEEK 6 - ACTIVITY 3: C-STRINGS (C)
// ============================================================
#include <stdio.h>
#include <string.h>

int main(void) {
    char name[50];

    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Could not read the name.\n");
        return 1;
    }

    // Remove the newline, if fgets stored one.
    name[strcspn(name, "\n")] = '\0';

    printf("Name: %s\n", name);
    printf("Length: %zu\n", strlen(name));

    if (name[0] != '\0') {
        printf("First character: %c\n", name[0]);
    } else {
        printf("First character: (empty)\n");
    }

    char copy[50];
    strcpy(copy, name); // Safe here because copy has the same capacity.
    printf("Copy: %s\n", copy);
    return 0;
}
