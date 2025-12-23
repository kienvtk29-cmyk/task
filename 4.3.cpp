#include <stdio.h>
#include <stdlib.h>
/// @brief Копировать матрицу
/// @param matrix Исходная матрица
/// @param n Количество строк
/// @param m Количество столбцов
/// @return Указатель на новую матрицу
int** copyMatrix(int** matrix, const int n, const int m);
// @brief Проверьте, выделена ли память для матрицы.
// @param arr Массив чисел
// @param size Размер массива
void checkarr(const int* arr);
/// @brief Создает динамическую матрицу размером n×m
/// @param n Количество строк
/// @param m Количество столбцов
/// @return Указатель на созданную матрицу
int** createMatrix(const int n, const int m);

/// @brief Заполняет матрицу вручную
/// @param a Указатель на матрицу
/// @param n Количество строк
/// @param m Количество столбцов
void fillMatrixManual(int** a, const int n, const int m);

/// @brief Заполняет матрицу случайными числами в заданном диапазоне
/// @param a Указатель на матрицу
/// @param n Количество строк
/// @param m Количество столбцов
void fillMatrixRandom(int** a, const int n, const int m);

/// @brief Выводит матрицу на экран
/// @param a Указатель на матрицу
/// @param n Количество строк
/// @param m Количество столбцов
void printMatrix(int** a, const int n, const int m);

/// @brief Заменяет минимальный элемент каждой строки на 0
/// @param a Указатель на матрицу
/// @param n Количество строк
/// @param m Количество столбцов
void replaceMinWithZero(int** a, const int n, const int m);

/// @brief Считает количество столбцов, не содержащих положительных нечетных чисел
/// @param a Указатель на матрицу
/// @param n Количество строк
/// @param m Количество столбцов
/// @return Количество столбцов, удовлетворяющих условию
int countValidColumns(int** a, const int n, const int m);

/// @brief Создает новую матрицу без столбцов, содержащих положительные нечетные числа
/// @param a Исходная матрица
/// @param n Количество строк
/// @param m Количество столбцов
/// @param newM Указатель на новый размер столбцов
/// @return Указатель на новую матрицу
int** removeOddPositiveColumns(int** a, const int n, const int m, int* newM);

/// @brief Проверяет, что значение положительное
/// @param value Проверяемое значение
void checkPositive(const int value);

/// @brief Считывает целое число с клавиатуры
/// @return Введенное значение
int inputValue();
// @brief Позволяет пользователям выбрать RANDOM = 1 или MANUAL = 2
enum { RANDOM = 1, MANUAL = 2 };

/// @brief Точка входа в программу
/// @return 0 при успешном завершении программы
int main() {
    

    int n=0, m=0;
    printf("Enter number of rows (n): ");
    n = inputValue();
    checkPositive(n);
    printf("Enter number of columns (m): ");
    m = inputValue();
    checkPositive(m);
    int** matrix = createMatrix(n, m);

    printf("choose RANDOM press %d, MANUAL press %d: ", RANDOM, MANUAL);
    int choice = inputValue();

    switch (choice) {
    case RANDOM:
        fillMatrixRandom(matrix, n, m);
        break;
    case MANUAL:
        fillMatrixManual(matrix, n, m);
        break;
    default:
        printf("Invalid choice.\n");
        return 1;
    }
    int** matrixCopy = copyMatrix(matrix, n, m);
    printf("Original matrix:\n");
    printMatrix(matrix, n, m);
    replaceMinWithZero(matrix, n, m);
    printf("Matrix after replacing minimum in each row with 0:\n");
    printMatrix(matrix, n, m);
    int newM = countValidColumns(matrix, n, m);
    matrix = removeOddPositiveColumns(matrix, n, m, &newM);
    printf("Matrix after removing columns with odd positive numbers:\n");
    printMatrix(matrix, n, newM);
    for (size_t i = 0; i < n; i++)
        free(matrix[i]);

    free(matrix);
    for (int i = 0; i < n; i++)
        free(matrixCopy[i]);
    free(matrixCopy);
    return 0;
}
void checkPositive(const int value)
{
    if (value <= 0)
    {
        printf("error \n");
        exit(1);
    }
}
int inputValue() {
    int value=0;
    if (!scanf_s("%d", &value)) {
        printf("error\n");
        exit(1);
    }
    return value;
}

int** createMatrix(int n, int m) {
    int** a = (int**)malloc(n * sizeof(int*));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(m * sizeof(int));
        if (a[i] == NULL) {
            printf("Memory allocation failed\n");

            for (int j = 0; j < i; j++)
                free(a[j]);
            free(a);

            return NULL;
        }
    }
    return a;
}

void fillMatrixManual(int** a, int n, int m) {
    printf("Enter %d×%d elements:\n", n, m);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);
            a[i][j] = inputValue();
        }
}

void fillMatrixRandom(int** a, int n, int m) {
    printf("Enter random range start: ");
    int s = inputValue();
    printf("Enter random range end: ");
    int e = inputValue();

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            a[i][j] = rand() % (e - s + 1) + s;
}

void printMatrix(int** a, int n, int m) {
    checkarr((int*)a);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }
}

void replaceMinWithZero(int** copyMatrix, int n, int m) {
    checkarr((int*)copyMatrix);
    for (size_t  i = 0; i < n; i++) {
        int minIndex = 0;
        for (size_t j = 1; j < m; j++)
            if (copyMatrix[i][j] < copyMatrix[i][minIndex])
                minIndex = j;

        copyMatrix[i][minIndex] = 0;
    }
}

int countValidColumns(int** copyMatrix, int n, int m) {
    checkarr((int*)copyMatrix);
    int count = 0;
    for (size_t col = 0; col < m; col++) {
        int ok = 1;
        for (size_t row = 0; row < n; row++) {
            if (copyMatrix[row][col] > 0 && copyMatrix[row][col] % 2 == 1) {
                ok = 0;
                break;
            }
        }
        if (ok) count++;
    }
    return count;
}

int** removeOddPositiveColumns(int** copyMatrix, int n, int m, int* newM) {
    checkarr((int*)copyMatrix);
    int validCols = countValidColumns(copyMatrix, n, m);
    int** newMatrix = createMatrix(n, validCols);

    int colIndex = 0;
    for (size_t col = 0; col < m; col++) {
        int ok = 1;
        for (size_t row = 0; row < n; row++)
            if (copyMatrix[row][col] > 0 && copyMatrix[row][col] % 2 == 1)
                ok = 0;

        if (ok) {
        
            for (size_t  row = 0; row < n; row++)
                newMatrix[row][colIndex] = copyMatrix[row][col];
            colIndex++;
        }
    }

    *newM = validCols;
    for (int i = 0; i < n; i++)
        free(copyMatrix[i]);
    free(copyMatrix);

    return newMatrix;
}

void checkarr(const int* arr) {
    if (arr == NULL)
    {
        printf("Memory error\n");
        exit(1);
    }
}
int** copyMatrix(int** matrix, const int n, const int m) {
    checkarr((int*)copyMatrix);
    if (matrix == NULL) {
        printf("Source matrix is NULL\n");
        exit(1);
    }

    int** Nmatrix = createMatrix(n, m);
    if (Nmatrix== NULL) {
        printf("Failed to allocate memory for copied matrix\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            Nmatrix[i][j] = matrix[i][j];

    return Nmatrix;
}
