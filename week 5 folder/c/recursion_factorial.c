// WEEK 5 - ACTIVITY 3: SIMPLE AND TAIL RECURSIVE FACTORIAL
#include <stdio.h>

long long factorialRecursive(int n) {
    if (n <= 1) return 1;                 // Base case
    return n * factorialRecursive(n - 1);
}

long long factorialTailHelper(int n, long long accumulator) {
    if (n <= 1) return accumulator;       // Base case
    return factorialTailHelper(n - 1, n * accumulator);
}

long long factorialTail(int n) {
    return factorialTailHelper(n, 1);
}

int main(void) {
    int num;
    printf("Enter a whole number from 0 to 20: ");
    if (scanf("%d", &num) != 1 || num < 0 || num > 20) {
        printf("Invalid input. Please enter a number from 0 to 20.\n");
        return 1;
    }

    printf("\nUsing simple recursion:\n");
    printf("%d! = %lld\n", num, factorialRecursive(num));

    printf("\nUsing tail recursion:\n");
    printf("%d! = %lld\n", num, factorialTail(num));

    printf("\nBoth methods give the same answer.\n");
    printf("Simple recursion: clear mathematical structure.\n");
    printf("Tail recursion: carries the result in an accumulator.\n");
    return 0;
}
