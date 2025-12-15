#include <stdio.h>
#include <stdlib.h>

/// @brief Выводит массив на экран
/// @param arr Массив чисел
/// @param size Размер массива
void printArray(const int* arr, const size_t size);

/// @brief Заполняет массив вручную
/// @param arr Массив чисел
/// @param size Размер массива
void fillArray(int* arr, const size_t size);

/// @brief Заполняет массив случайными числами в заданном диапазоне
/// @param arr Массив чисел
/// @param size Размер массива
void fillRandom(int* arr, const size_t size);

/// @brief Заменяет максимальный элемент массива на противоположный по знаку
/// @param arr Массив чисел
/// @param size Размер массива
void replaceMaxWithOpposite(int* arr, const size_t size);

/// @brief Проверяет, содержит ли число цифру 1
/// @param x Число для проверки
/// @return 1, если содержит цифру 1, иначе 0
int containsDigit1(int x);

/// @brief Вставляет максимальный элемент после всех элементов, содержащих цифру 1
/// @param arr Указатель на массив чисел
/// @param size Указатель на размер массива (может изменяться)
void insertMaxAfterOnes(int** arr,size_t* size);

/// @brief Находит индекс максимального элемента массива
/// @param arr Массив чисел
/// @param size Размер массива
/// @return Индекс максимального элемента
int findMaxIndex(const int* arr, const size_t size);

/// @brief Создаёт массив A на основе массива C с изменениями в первых 10 элементах
/// @param A Массив для заполнения
/// @param C Исходный массив
/// @param size Размер массива
void makeArrayA(int* A, int* C, const size_t size);

/// @brief Считывает размер массива с клавиатуры
/// @return Значение размера
size_t getSize();

/// @brief Считывает целое число с клавиатуры
/// @return Введённое число
int Value();
// @brief Позволяет пользователям выбрать RANDOM = 1 или MANUAL = 2
enum { RANDOM = 1, MANUAL = 2 };

/// @brief Точка входа в программу
/// @return 0 при успешном завершении программы
int main()
{
    printf("Enter array size: ");
    size_t size = getSize();

    int* arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory error\n");
        return 0;
    }

    printf("choose RANDOM press %d, MANUAL press %d: ", RANDOM, MANUAL);
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
    int x=0;
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

void fillArray(int* arr,const size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Enter number: ");
        arr[i] = Value();
    }
}

void fillRandom(int* arr,const  size_t size) {
    printf("start = ");
    int start = Value();
    printf("end = ");
    int end = Value();
    for (size_t i = 0; i < size; i++)
        arr[i] = (rand() % (end - start + 1)) + start;
}

void printArray(const int* arr,const  size_t size) {
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr[i]);

}

int findMaxIndex(const int* arr, const size_t size) {
    size_t maxI = 0;
    for (size_t i = 1; i < size; i++)
        if (arr[i] > arr[maxI])
            maxI = i;
    return maxI;
}

void replaceMaxWithOpposite(int* arr,const size_t size) {
    int idx = findMaxIndex(arr, size);
    arr[idx] = -arr[idx];
}

int containsDigit1( int x) {
    x = abs(x);
    while (x > 0) {
        if (x % 10 == 1) return 1;
        x /= 10;
    }
    return 0;
}

void insertMaxAfterOnes(int** arr,size_t* size) {
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

void makeArrayA(int* A, int* C,const  size_t size) {
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
