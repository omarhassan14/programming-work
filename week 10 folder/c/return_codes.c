// ACTIVITY 3: RETURN CODES AND STDERR IN C
#include <stdio.h>
#include <errno.h>
#include <string.h>

int readFileWithReturnCode(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s': %s\n",
                filename, strerror(errno));
        return 1; // Failure
    }

    // Example placeholder for reading file contents.
    fclose(file);
    return 0; // Success
}

int main(void) {
    printf("--- Testing Return Code Strategy ---\n");

    if (readFileWithReturnCode("data.txt") == 1) {
        printf("Main function: Handled error gracefully. Program continues.\n");
    }

    printf("\n--- Evaluation ---\n");
    printf("In C, we must manually check return codes.\n");
    printf("If the programmer forgets to check, later code may use invalid data.\n");
    return 0;
}
