// ============================================================
// WEEK 6 - ACTIVITY 2: 2D ARRAY MEMORY LAYOUT (ROW-MAJOR) (C)
// ============================================================
#include <stdio.h>

int main(void) {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printf("Row-major traversal (row by row):\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    printf("\nMemory addresses (address spacing depends on sizeof(int)):\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("matrix[%d][%d] = %d at address %p\n",
                   row, col, matrix[row][col],
                   (void *)&matrix[row][col]);
        }
    }

    printf("\nColumn-major traversal (column by column):\n");
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 3; row++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    printf("\nObservation: C stores 2D arrays in row-major order.\n");
    printf("Row 0 is stored completely, then row 1, then row 2.\n");
    return 0;
}
