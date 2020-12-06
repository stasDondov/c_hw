/* 2.1.11
 * 11)	Дана квадратна матриця порядку 2n. Повернути її на 180 градусів в позитивному напрямку.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int** generate (int n, int MIN, int MAX)
{
    // створює матрицю і заповнює випадковими числами від MIN до MAX
    srand(time(NULL));
    int** arr = NULL;
    arr = (int **)calloc(n, sizeof(*arr));
    for(int i = 0; i < n; i++){
        arr[i] = (int*)calloc(n, sizeof(*arr[i]));
        for(int j = 0; j < n; j++) {
            arr[i][j] = rand() % (MAX - MIN + 1) + MIN;
        }
    }
    return arr;
}

void output (int** matr, int n)  // n - порядок матриці
{
    // виводить матрицю
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            printf("%3d ", matr[i][j]);
        }
        printf("\n");
    }
}

void turn_180 (int** matr, int n)
{
    // повертає матрицю на 180 градусів
    int **arr2 = NULL;
    arr2 = (int **)calloc(n, sizeof(*arr2)); // допоміжна матриця

    for (int i = 0; i < n; i++) {
        arr2[i] = (int*)calloc(n, sizeof(*arr2[i]));
        for (int j = 0; j < n; j++) {
            arr2[i][j] = matr[n - 1 - i][n - 1 - j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matr[i][j] = arr2[i][j];
        }
    }
}


int main() {
    int n; // порядок матриці
    int MIN, MAX;
    printf("Input order of the matrix (n should be even):\n n = ");
    scanf_s("%d", &n);
    printf("MIN = ");
    scanf_s("%d", &MIN);
    printf("MAX = ");
    scanf_s("%d", &MAX);

    int **mas = generate(n, MIN, MAX);
    printf("Your matrix:\n");
    output(mas, n);

    turn_180(mas, n);
    printf("Turned matrix:\n");
    output(mas, n);

    for(int i = 0; i < n; i++)
        free(mas[i]);

    system("pause");
    return 0;
}
