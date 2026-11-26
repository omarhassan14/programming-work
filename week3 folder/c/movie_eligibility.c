// PROGRAM 4: Movie eligibility and discount (logical operators)
#include <stdio.h>
int main(void) {
    int age, hasParentalConsent, isWeekend;
    printf("Enter age: "); if (scanf("%d", &age) != 1 || age < 0) return 1;
    printf("Has parental consent? (1 for yes, 0 for no): "); if (scanf("%d", &hasParentalConsent) != 1) return 1;
    printf("Is it weekend? (1 for yes, 0 for no): "); if (scanf("%d", &isWeekend) != 1) return 1;
    int canWatchMovie = (age >= 18) || (age >= 13 && hasParentalConsent) || (isWeekend && age >= 10);
    if (canWatchMovie) printf("You can watch the movie!\n");
    else printf("Sorry, you cannot watch this movie.\n");
    int eligibleForDiscount = (age >= 65) || (age <= 12) || (isWeekend && age <= 18);
    if (eligibleForDiscount) printf("You qualify for a discount!\n");
    return 0;
}
