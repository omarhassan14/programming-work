// ============================================================
// WEEK 6 - ACTIVITY 4: STUDENT SCORE ANALYZER (C)
// ============================================================
#include <stdio.h>

#define SIZE 10

double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return (double)sum / size;
}

void displayAboveAverage(int scores[], int size, double average) {
    int found = 0;
    printf("\nScores above average (%.2f):\n", average);
    for (int i = 0; i < size; i++) {
        if (scores[i] > average) {
            printf(" Score %d at position %d\n", scores[i], i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf(" None\n");
    }
}

int main(void) {
    int scores[SIZE];

    printf("Enter %d student scores (0-100):\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Score %d: ", i + 1);
        if (scanf("%d", &scores[i]) != 1 || scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score. Enter whole-number scores from 0 to 100.\n");
            return 1;
        }
    }

    double average = calculateAverage(scores, SIZE);
    int highest = scores[0], lowest = scores[0];
    int highestPosition = 1, lowestPosition = 1, aboveCount = 0;

    for (int i = 0; i < SIZE; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
            highestPosition = i + 1;
        }
        if (scores[i] < lowest) {
            lowest = scores[i];
            lowestPosition = i + 1;
        }
        if (scores[i] > average) {
            aboveCount++;
        }
    }

    printf("\n--- Results ---\n");
    printf("Average score: %.2f\n", average);
    displayAboveAverage(scores, SIZE, average);
    printf("\nHighest score: %d at position %d\n", highest, highestPosition);
    printf("Lowest score: %d at position %d\n", lowest, lowestPosition);
    printf("Number of scores above average: %d\n", aboveCount);
    return 0;
}
