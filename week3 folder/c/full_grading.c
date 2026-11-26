// PROGRAM 8: Full grading program (if-else chain and switch recommendations)
#include <stdio.h>
#include <string.h>
int main(void) {
    char studentName[50]; double score; char grade;
    printf("Enter student name: ");
    if (!fgets(studentName, sizeof studentName, stdin)) return 1;
    studentName[strcspn(studentName, "\n")] = '\0';
    printf("Enter percentage score (0-100): ");
    if (scanf("%lf", &score) != 1 || score < 0 || score > 100) { printf("ERROR: Score must be between 0 and 100!\n"); return 1; }
    if (score >= 90) grade = 'A'; else if (score >= 80) grade = 'B';
    else if (score >= 70) grade = 'C'; else if (score >= 60) grade = 'D'; else grade = 'F';
    printf("\n===== GRADE REPORT =====\nStudent: %s\nScore: %.2f%%\nLetter Grade: %c\n", studentName, score, grade);
    printf("\n===== RECOMMENDATIONS =====\n");
    switch (grade) {
        case 'A': printf("Consider becoming a peer tutor\nExplore advanced topics\n"); break;
        case 'B': printf("Review topics where you lost points\nPractice more problems\n"); break;
        case 'C': printf("Attend office hours regularly\nForm a study group\n"); break;
        case 'D': case 'F': printf("Mandatory tutoring sessions\nMeet with academic advisor\n"); break;
        default: printf("Continue your good work\n"); break;
    }
    return 0;
}
