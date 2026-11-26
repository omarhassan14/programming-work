// ACTIVITY 1: BASIC FILE I/O IN C
#include <stdio.h>

int main(void) {
    FILE *inputFile = fopen("numbers.txt", "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Could not open numbers.txt for reading!\n");
        return 1;
    }

    int num;
    int sum = 0;
    printf("Reading numbers from file...\n");

    while (fscanf(inputFile, "%d", &num) == 1) {
        printf("Read: %d\n", num);
        sum += num;
    }

    if (ferror(inputFile)) {
        fprintf(stderr, "Error while reading numbers.txt\n");
        fclose(inputFile);
        return 1;
    }
    fclose(inputFile);

    printf("Total Sum: %d\n", sum);

    FILE *outputFile = fopen("sum.txt", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Could not create sum.txt for writing!\n");
        return 1;
    }

    if (fprintf(outputFile,
                "The total sum is: %d\n"
                "Calculated automatically by the C program.\n", sum) < 0) {
        fprintf(stderr, "Error writing to sum.txt\n");
        fclose(outputFile);
        return 1;
    }

    if (fclose(outputFile) != 0) {
        fprintf(stderr, "Error closing sum.txt\n");
        return 1;
    }

    printf("Result successfully saved to sum.txt!\n");
    return 0;
}
