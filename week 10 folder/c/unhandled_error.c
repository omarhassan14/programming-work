// ACTIVITY 2: IGNORING FILE ERRORS IN C
// WARNING: This example intentionally uses a NULL FILE pointer.
// Running it may terminate with an access violation/segmentation fault.
#include <stdio.h>

int main(void) {
    FILE *myFile = fopen("missing_file.txt", "r");

    // INTENTIONALLY OMITTED: if (myFile == NULL) { ... }
    char data[100];

    printf("Attempting to read from missing file...\n");
    fflush(stdout);

    // Deliberate error for learning purposes: myFile is NULL.
    fscanf(myFile, "%99s", data);

    printf("Data read: %s\n", data);
    fclose(myFile);
    return 0;
}
