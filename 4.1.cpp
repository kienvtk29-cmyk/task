#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void find36(int* arr, const size_t size);
int findeven(int* arr, const size_t size);
void printArray(int* arr, const size_t size);
void fillArray(int* arr, const size_t size);
void fillRandom(int* arr, const size_t size);
void findMaxMin(int* arr, size_t size, int* minindex, int* maxindex);
void replaceN(int minindex, int maxindex, int* arr, size_t size);
size_t getSize();
int Value();

enum { RANDOM = 1, MANUAL = 2 };

int main()
{


    printf("enter array size: ");
    size_t size = getSize();

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory error\n");
        exit(1);
    }

    printf("choose RANDOM press 1, MANUAL press 2: ");
    int choice = Value();

    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, size);
        break;

    case MANUAL:
        fillArray(arr, size);
        break;

    default:
        printf("error");
        free(arr);
        return 0;
    }

    printArray(arr, size);

 


    find36(arr, size);
    int sum = findeven(arr, size);
    printf("Sum of negative even numbers: %d\n", sum);

    int minindex, maxindex;
    findMaxMin(arr, size, &minindex, &maxindex);
    printf("Min index = %d, Max index = %d\n", minindex, maxindex);
    replaceN(minindex, maxindex, arr, size);
    free(arr);
    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("ERROR\n");
        exit(1);
    }
    return value;
}

size_t getSize()
{
    int value = Value();
    if (value <= 0)
    {
        printf("ERROR\n");
        exit(1);
    }
    return value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("enter number: ");
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    printf("Array: ");
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void fillRandom(int* arr, const size_t size)
{
    printf("start: ");
    int start = Value();
    printf("end: ");
    int end = Value();

    for (size_t i = 0; i < size; i++)
        arr[i] = (rand() % (end - start + 1)) + start;
}

int findeven(int* arr, const size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
        if (arr[i] < 0 && arr[i] % 2 == 0)
            sum += arr[i];

    return sum;
}

void find36(int* arr, const size_t size)
{
    printf("Numbers divisible by 6: ");
    for (size_t i = 0; i < size; i++)
        if (arr[i] % 6 == 0)
            printf("%d ", arr[i]);
    printf("\n");
}

void findMaxMin(int* arr, size_t size, int* minindex, int* maxindex)
{
    *maxindex = 0;
    *minindex = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[*maxindex])
            *maxindex = i;
        if (arr[i] < arr[*minindex])
            *minindex = i;
    }
}

void replaceN(int minindex, int maxindex, int* arr, size_t size)
{
    for (int i = minindex+1; i < maxindex; i++)
        arr[i] = 0;

    printf("Array after replacement: ");
    printArray(arr, size);
}
