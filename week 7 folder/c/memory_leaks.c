// ============================================================
// ACTIVITY 3A: MEMORY LEAK (C VERSION)
// This function intentionally demonstrates a small memory leak.
// ============================================================
#include <stdio.h>
#include <stdlib.h>

void createLeak(void) {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    *ptr = 42;
    printf("Inside function. The value is: %d\n", *ptr);
    printf("Memory allocated at address: %p\n", (void *)ptr);

    // INTENTIONAL LEAK FOR DEMONSTRATION:
    // The allocated memory is not freed before ptr goes out of scope.
}

int main(void) {
    printf("Calling function that leaks memory...\n");
    createLeak();
    printf("Function finished. The memory is now leaked.\n");
    return 0;
}
