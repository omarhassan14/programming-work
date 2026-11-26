/*
 * WEEK 2 - STUDENT SCORE CALCULATOR (C VERSION)
 * Variables, data types, input/output, arithmetic, validation and decisions.
 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define TEST_COUNT 4
#define MAX_SCORE 100

static void read_line(const char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);
    if (fgets(buffer, (int)size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
}

static int read_score(int test_number) {
    char line[MAX_LEN];
    int score, consumed;
    while (1) {
        printf("Enter score for Test %d (0-%d): ", test_number, MAX_SCORE);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            puts("Input ended. Please restart the program.");
            return 0;
        }
        if (sscanf(line, "%d %n", &score, &consumed) == 1 &&
            line[consumed] == '\0' && score >= 0 && score <= MAX_SCORE) {
            return score;
        }
        printf("Invalid score. Enter a whole number from 0 to %d.\n", MAX_SCORE);
    }
}

int main(void) {
    char studentName[MAX_LEN], course[MAX_LEN], grade;
    int scores[TEST_COUNT], totalScore = 0, highestScore;
    double average, percentage;

    read_line("Enter student name: ", studentName, sizeof(studentName));
    read_line("Enter course (BBIT/BCS): ", course, sizeof(course));

    for (int i = 0; i < TEST_COUNT; ++i) {
        scores[i] = read_score(i + 1);
        totalScore += scores[i];
    }

    average = totalScore / (double)TEST_COUNT;
    percentage = (totalScore / (double)(TEST_COUNT * MAX_SCORE)) * 100.0;

    highestScore = scores[0];
    for (int i = 1; i < TEST_COUNT; ++i) {
        if (scores[i] > highestScore) highestScore = scores[i];
    }

    if (percentage >= 90.0) grade = 'A';
    else if (percentage >= 80.0) grade = 'B';
    else if (percentage >= 70.0) grade = 'C';
    else if (percentage >= 60.0) grade = 'D';
    else grade = 'F';

    printf("\n========================================\n");
    printf("          STUDENT REPORT CARD\n");
    printf("========================================\n");
    printf("Student:       %s\n", studentName);
    printf("Course:        %s\n\n", course);
    for (int i = 0; i < TEST_COUNT; ++i)
        printf("Test %d:         %d/%d\n", i + 1, scores[i], MAX_SCORE);
    printf("\nTotal:          %d/%d\n", totalScore, TEST_COUNT * MAX_SCORE);
    printf("Average:        %.2f\n", average);
    printf("Percentage:     %.2f%%\n", percentage);
    printf("Highest score:  %d/%d\n", highestScore, MAX_SCORE);
    printf("Grade:          %c\n", grade);
    printf("Result:         %s\n", percentage >= 50.0 ? "PASS" : "FAIL");
    printf("========================================\n");
    return 0;
}
