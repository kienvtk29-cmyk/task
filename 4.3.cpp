#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int n, int m);
void fillMatrixManual(int** a, int n, int m);
void fillMatrixRandom(int** a, int n, int m);
void printMatrix(int** a, int n, int m);
void replaceMinWithZero(int** a, int n, int m);
int countValidColumns(int** a, int n, int m);
int** removeOddPositiveColumns(int** a, int n, int m, int* newM);

int inputValue();

int main() {
    

    int n, m;
    printf("Enter number of rows (n): ");
    n = inputValue();
    printf("Enter number of columns (m): ");
    m = inputValue();

    int** matrix = createMatrix(n, m);

    printf("Choose fill method: 1 - RANDOM, 2 - MANUAL: ");
    int choice = inputValue();

    switch (choice) {
    case 1:
        fillMatrixRandom(matrix, n, m);
        break;
    case 2:
        fillMatrixManual(matrix, n, m);
        break;
    default:
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Original matrix:\n");
    printMatrix(matrix, n, m);
    replaceMinWithZero(matrix, n, m);
    printf("Matrix after replacing minimum in each row with 0:\n");
    printMatrix(matrix, n, m);
    int newM = m;
    matrix = removeOddPositiveColumns(matrix, n, m, &newM);

    printf("Matrix after removing columns with odd positive numbers:\n");
    printMatrix(matrix, n, newM);
    for (int i = 0; i < n; i++)
        free(matrix[i]);

    free(matrix);
    return 0;
}

int inputValue() {
    int x;
    scanf_s("%d", &x);
    return x;
}

int** createMatrix(int n, int m) {
    int** a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        a[i] = (int*)malloc(m * sizeof(int));
    return a;
}

void fillMatrixManual(int** a, int n, int m) {
    printf("Enter %d×%d elements:\n", n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);
            a[i][j] = inputValue();
        }
}

void fillMatrixRandom(int** a, int n, int m) {
    printf("Enter random range start: ");
    int s = inputValue();
    printf("Enter random range end: ");
    int e = inputValue();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % (e - s + 1) + s;
}

void printMatrix(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }
}

void replaceMinWithZero(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        int minIndex = 0;
        for (int j = 1; j < m; j++)
            if (a[i][j] < a[i][minIndex])
                minIndex = j;

        a[i][minIndex] = 0;
    }
}

int countValidColumns(int** a, int n, int m) {
    int count = 0;
    for (int col = 0; col < m; col++) {
        int ok = 1;
        for (int row = 0; row < n; row++) {
            if (a[row][col] > 0 && a[row][col] % 2 == 1) {
                ok = 0;
                break;
            }
        }
        if (ok) count++;
    }
    return count;
}

int** removeOddPositiveColumns(int** a, int n, int m, int* newM) {
    int validCols = countValidColumns(a, n, m);
    int** newMatrix = createMatrix(n, validCols);

    int colIndex = 0;
    for (int col = 0; col < m; col++) {
        int ok = 1;
        for (int row = 0; row < n; row++)
            if (a[row][col] > 0 && a[row][col] % 2 == 1)
                ok = 0;

        if (ok) {
        
            for (int row = 0; row < n; row++)
                newMatrix[row][colIndex] = a[row][col];
            colIndex++;
        }
    }

    *newM = validCols;
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);

    return newMatrix;
}
