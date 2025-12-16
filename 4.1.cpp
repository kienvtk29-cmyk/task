#include <stdio.h>
#include <stdlib.h>
// @brief Находит и выводит числа массива, кратные 6
// @param arr Массив чисел
// @param size Размер массива
void find36(const int* arr,const size_t size);
// @brief создать матрицу копирования
// @param arr Массив чисел
// @param size Размер массива
// @return Индекс минимального элемента
int* copyArray(const int* arr, const size_t size);
// @brief Вычисляет сумму отрицательных чётных чисел массива
// @param arr Массив чисел
// @param size Размер массива
// @return Сумма отрицательных чётных чисел
int findeven(const int* arr,const size_t size);

// @brief Выводит массив на экран
// @param arr Массив чисел
// @param size Размер массива
void printArray(const int* arr,const size_t size);

// @brief Заполняет массив вручную, вводя значения с клавиатуры
// @param arr Массив чисел
// @param size Размер массива
void fillArray(int* arr,const size_t size);

// @brief Заполняет массив случайными числами в заданном диапазоне
// @param arr Массив чисел
// @param size Размер массива
void fillRandom(int* arr,const size_t size);

// @brief Находит индекс максимального элемента массива
// @param arr Массив чисел
// @param size Размер массива
// @return Индекс максимального элемента
int findMax(const int* arr,const size_t size);

// @brief Находит индекс минимального элемента массива
// @param arr Массив чисел
// @param size Размер массива
// @return Индекс минимального элемента
int findMin(const int* arr,const size_t size);

// @brief Заменяет элементы массива между минимальным и максимальным индексом на 0
// @param minindex Индекс минимального элемента
// @param maxindex Индекс максимального элемента
// @param arr Массив чисел
// @param size Размер массива
void replaceN(const int minindex, const int maxindex, int* copyArr,const  size_t size);

// @brief Считывает размер массива с клавиатуры
// @return Значение размера
size_t getSize();

// @brief Считывает целое число с клавиатуры
// @return Введённое число
int Value();
// @brief Проверьте, выделена ли память для матрицы.
// @param arr Массив чисел
// @param size Размер массива
void checkarr(const int* arr,const  size_t size);
// @brief Позволяет пользователям выбрать RANDOM = 1 или MANUAL = 2
enum { RANDOM = 1, MANUAL = 2 };

// @brief Точка входа в программу
// @return 0 при успешном завершении программы
int main()
{


    printf("enter array size: ");
    size_t size = getSize();

    int* arr = (int*)malloc(size * sizeof(int));
    checkarr(arr, size);

    printf("choose RANDOM press %d, MANUAL press %d: ", RANDOM, MANUAL);
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

    
    int minindex = findMin(arr, size);
    int maxindex = findMax(arr, size);
    printf("Min index = %d, Max index = %d\n", minindex, maxindex);
    int* copyArr = copyArray(arr, size);
    
    replaceN(minindex, maxindex, copyArr, size);
    free(copyArr);
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
    checkarr(arr);
    for (size_t i = 0; i < size; i++)
    {
        printf("enter number: ");
        arr[i] = Value();
    }
}

void printArray(const int* arr, const size_t size)
{
    printf("Array: ");
    checkarr(arr);
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
    checkarr(arr);
    for (size_t i = 0; i < size; i++)
        arr[i] = (rand() % (end - start + 1)) + start;
}

int findeven(const int* arr, const size_t size)
{
    int sum = 0;
    checkarr(arr);
    for (size_t i = 0; i < size; i++)
        if (arr[i] < 0 && arr[i] % 2 == 0)
            sum += arr[i];

    return sum;
}

void find36(const int* arr, const size_t size)
{
    printf("Numbers divisible by 6: ");
    checkarr(arr);
    for (size_t i = 0; i < size; i++)
        if (arr[i] % 6 == 0)
            printf("%d ", arr[i]);

    printf("\n");
}

int findMax(const int* arr,const size_t size)
{
    int maxindex = 0;
    checkarr(arr);
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] > arr[maxindex])
            maxindex = i;

    }
    return maxindex;
}
int findMin(const int* arr,const size_t size)
{
    int minindex = 0;
    checkarr(arr);

    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] < arr[minindex])
            minindex = i;

    }
    return minindex;
}

void replaceN(const int minindex,const int maxindex, int* copyArray,const  size_t size)
{
    for (size_t i = minindex+1; i < maxindex; i++)
       
        checkarr(copyArray);
        copyArray[i] = 0;
    printf("Array after replacement: ");
    printArray(copyArray, size);
}
void checkarr(const int* arr) {
    if (arr == NULL)
    {
        printf("Memory error\n");
        exit(1);
    }
}
int* copyArray(const int* arr, const size_t size)
{
    checkarr(arr);
    int* copyArr = (int*)malloc(sizeof(int) * size);
    checkarr(copyArr);
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

