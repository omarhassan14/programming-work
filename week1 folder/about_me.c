/*
 * WEEK 1 - ABOUT ME (C)
 * Six required questions plus the Week 1 C challenges:
 * - Ask favourite food
 * - Use MAX_LEN 200
 * - Print a personalized closing message
 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 200

static void read_answer(const char *prompt, char answer[MAX_LEN]) {
    printf("%s", prompt);
    if (fgets(answer, MAX_LEN, stdin) == NULL) {
        answer[0] = '\0';
        return;
    }
    answer[strcspn(answer, "\r\n")] = '\0';
}

int main(void) {
    char name[MAX_LEN], course[MAX_LEN], hobby[MAX_LEN];
    char reason[MAX_LEN], expectation[MAX_LEN], definition[MAX_LEN];
    char favourite_food[MAX_LEN];

    printf("========================================\n");
    printf(" WELCOME TO YOUR FIRST C PROGRAM!\n");
    printf("========================================\n\n");

    read_answer("1. What is your name? ", name);
    if (name[0] == '\0') {
        printf("You didn't enter a name!\n");
    }

    read_answer("2. What course are you doing? (BBIT/BCS): ", course);
    read_answer("3. What is your hobby? ", hobby);
    read_answer("4. Why did you choose this course? ", reason);
    read_answer("5. What do you expect to learn in programming? ", expectation);
    read_answer("6. In your own words, what is programming? ", definition);
    read_answer("7. What is your favourite food? ", favourite_food);

    printf("\n========================================\n");
    printf(" YOUR PROFILE SUMMARY\n");
    printf("========================================\n\n");
    printf("Name:             %s\n", name);
    printf("Course:           %s\n", course);
    printf("Hobby:            %s\n", hobby);
    printf("Reason:           %s\n", reason);
    printf("Expectation:      %s\n", expectation);
    printf("Programming is:   %s\n", definition);
    printf("Favourite food:   %s\n", favourite_food);
    printf("\n========================================\n");
    printf("Great job, %s! Thanks for completing this!\n", name);
    printf("========================================\n");

    return 0;
}
