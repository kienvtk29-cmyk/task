#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, size_t size);
void fillArray(int* arr, size_t size);
void fillRandom(int* arr, size_t size);
void replaceMaxWithOpposite(int* arr, size_t size);
int containsDigit1(int x);
void insertMaxAfterOnes(int** arr, size_t* size);
int findMaxIndex(int* arr, size_t size);
void makeArrayA(int* A, int* C, size_t size);
size_t getSize();
int Value();

enum { RANDOM = 1, MANUAL = 2 };

int main()
{
    printf("Enter array size: ");
    size_t size = getSize();

    int* arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory error\n");
        return 0;
    }

    printf("Choose: 1 = RANDOM, 2 = MANUAL\n");
    int choice = Value();

    switch (choice) {
    case RANDOM:
        fillRandom(arr, size);
        break;
    case MANUAL:
        fillArray(arr, size);
        break;
    default:
        printf("Invalid\n");
        free(arr);
        return 0;
    }
    printf("Original array:\n");
    printArray(arr, size);
    printf("\nReplace max element with opposite sign:\n");
    replaceMaxWithOpposite(arr, size);
    printArray(arr, size);
    printf("\nInsert max after all elements that contain digit 1:\n");
    insertMaxAfterOnes(&arr, &size);
    printArray(arr, size);
    printf("\nCreate array A from C:\n");
    int* A = malloc(size * sizeof(int));
    if (A == NULL) {
        printf("Memory error\n");
        free(arr);
        return 0;
    }

    makeArrayA(A, arr, size);
    printArray(A, size);

    free(A);
    free(arr);
    return 0;
}

int Value() {
    int x;
    if (scanf_s("%d", &x) != 1) {
        printf("Input error\n");
        exit(1);
    }
    return x;
}

size_t getSize() {
    int v = Value();
    if (v <= 0) {
        printf("Size must be positive\n");
        exit(1);
    }
    return v;
}

void fillArray(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Enter number: ");
        arr[i] = Value();
    }
}

void fillRandom(int* arr, size_t size) {
    printf("start = ");
    int start = Value();
    printf("end = ");
    int end = Value();
    for (size_t i = 0; i < size; i++)
        arr[i] = (rand() % (end - start + 1)) + start;
}

void printArray(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr[i]);

}

int findMaxIndex(int* arr, size_t size) {
    size_t maxI = 0;
    for (size_t i = 1; i < size; i++)
        if (arr[i] > arr[maxI])
            maxI = i;
    return maxI;
}

void replaceMaxWithOpposite(int* arr, size_t size) {
    int idx = findMaxIndex(arr, size);
    arr[idx] = -arr[idx];
}

int containsDigit1(int x) {
    x = abs(x);
    while (x > 0) {
        if (x % 10 == 1) return 1;
        x /= 10;
    }
    return 0;
}

void insertMaxAfterOnes(int** arr, size_t* size) {
    int maxVal = (*arr)[findMaxIndex(*arr, *size)];

    for (size_t i = 0; i < *size; i++) {
        if (containsDigit1((*arr)[i])) {

            *arr = realloc(*arr, (*size + 1) * sizeof(int));
            if (!*arr) {
                printf("Memory error\n");
                exit(1);
            }

            for (size_t j = *size; j > i + 1; j--)
                (*arr)[j] = (*arr)[j - 1];

            (*arr)[i + 1] = maxVal;

            (*size)++;
            i++;
        }
    }
}

void makeArrayA(int* A, int* C, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (i < 10) {
            if (i % 2 == 0)
                A[i] = C[i] + (int)i;
            else
                A[i] = C[i] - (int)i;
        }
        else {
            A[i] = C[i];
        }
    }
}