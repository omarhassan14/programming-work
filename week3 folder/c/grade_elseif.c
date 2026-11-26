// PROGRAM 2: Grade using an else-if chain
#include <stdio.h>
int main(void) {
    int score; char grade;
    printf("Enter score (0-100): ");
    if (scanf("%d", &score) != 1 || score < 0 || score > 100) { printf("Invalid score.\n"); return 1; }
    if (score >= 90) grade = 'A';
    else if (score >= 80) grade = 'B';
    else if (score >= 70) grade = 'C';
    else if (score >= 60) grade = 'D';
    else grade = 'F';
    printf("Grade: %c\n", grade);
    return 0;
}
