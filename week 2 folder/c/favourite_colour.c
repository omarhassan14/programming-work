/* BONUS: Favourite Colour - C VERSION */
#include <stdio.h>
#include <string.h>
#define MAX_LEN 50
int main(void) {
    char colour[MAX_LEN];
    printf("Enter your favourite colour: ");
    if (fgets(colour, sizeof(colour), stdin) == NULL) return 1;
    colour[strcspn(colour, "\n")] = '\0';
    printf("Your favourite colour is %s.\n", colour);
    return 0;
}
