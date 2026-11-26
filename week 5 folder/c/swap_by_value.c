// WEEK 5 - ACTIVITY 1: PASS-BY-VALUE AND POINTER SWAP
#include <stdio.h>

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue: a = %d, b = %d\n", a, b);
}

void swapByPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 10, y = 20;

    printf("Before swapByValue: x = %d, y = %d\n", x, y);
    swapByValue(x, y);
    printf("After swapByValue:  x = %d, y = %d\n", x, y);

    printf("\nNow swapping the originals using pointers:\n");
    swapByPointer(&x, &y);
    printf("After swapByPointer: x = %d, y = %d\n", x, y);
    return 0;
}
