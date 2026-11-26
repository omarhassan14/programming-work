// ============================================================
// ACTIVITY 4: DYNAMIC ARRAY WRAPPER (C VERSION)
// ============================================================
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

int initArray(DynamicArray *arr, int initialCapacity) {
    if (arr == NULL || initialCapacity <= 0) {
        return 0;
    }

    arr->size = 0;
    arr->capacity = initialCapacity;
    arr->data = (int *)malloc((size_t)arr->capacity * sizeof(int));

    if (arr->data == NULL) {
        arr->size = 0;
        arr->capacity = 0;
        return 0;
    }
    return 1;
}

void freeArray(DynamicArray *arr) {
    if (arr != NULL) {
        free(arr->data);
        arr->data = NULL;
        arr->size = 0;
        arr->capacity = 0;
    }
}

int push_back(DynamicArray *arr, int value) {
    if (arr == NULL || arr->data == NULL) {
        return 0;
    }

    if (arr->size == arr->capacity) {
        int newCapacity = arr->capacity * 2;
        int *newData = (int *)malloc((size_t)newCapacity * sizeof(int));

        if (newData == NULL) {
            printf("Failed to allocate memory during resize.\n");
            return 0;
        }

        for (int i = 0; i < arr->size; i++) {
            newData[i] = arr->data[i];
        }

        free(arr->data);
        arr->data = newData;
        printf("[Resized capacity from %d to %d]\n", arr->capacity, newCapacity);
        arr->capacity = newCapacity;
    }

    arr->data[arr->size] = value;
    arr->size++;
    return 1;
}

void display(const DynamicArray *arr) {
    printf("Array (Size: %d, Capacity: %d): ", arr->size, arr->capacity);
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main(void) {
    DynamicArray myArray;

    if (!initArray(&myArray, 2)) {
        printf("Failed to initialize dynamic array.\n");
        return 1;
    }

    printf("Created dynamic array with capacity 2.\n");
    push_back(&myArray, 10);
    push_back(&myArray, 20);
    display(&myArray);

    printf("\nAdding third element...\n");
    push_back(&myArray, 30);
    display(&myArray);

    printf("\nAdding fourth and fifth elements...\n");
    push_back(&myArray, 40);
    push_back(&myArray, 50);
    display(&myArray);

    freeArray(&myArray);
    return 0;
}
