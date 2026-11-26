// ============================================================
// WEEK 6 - ACTIVITY 1: LINEAR SEARCH IN AN INTEGER ARRAY (C)
// ============================================================
#include <stdio.h>

// Returns the index of target if found; otherwise returns -1.
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int numbers[8] = {15, 42, 7, 89, 23, 56, 11, 74};
    int size = (int)(sizeof(numbers) / sizeof(numbers[0]));
    int target;

    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\nEnter a number to search: ");

    if (scanf("%d", &target) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    int position = linearSearch(numbers, size, target);
    if (position != -1) {
        printf("Element found at index: %d\n", position);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}
