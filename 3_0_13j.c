/* 3.0.13j
 * Сформувати динамічний двовимірний масив, заповнити його випадковими
числами і вивести на екран.
 * j)	Додати К стовпців в початок матриці.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100  // найбільше значення для елемента матриці
#define MIN (-100) // найбільше значення для елемента матриці


int** generate (int n, int m)
{
    srand(time(NULL));
    int** arr = NULL;
    arr = (int **)calloc(n, sizeof(*arr));
    for(int i = 0; i < n; i++){
        arr[i] = (int*)calloc(m, sizeof(*arr[i]));
        for(int j = 0; j < m; j++) {
            arr[i][j] = rand() % (MAX - MIN + 1) + MIN;
        }
    }
    return arr;
}


void output (int** matr, int n, int m)
{
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            printf("%3d ", matr[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int rows, cols, K;
    printf("rows = ");
    scanf_s("%d", &rows);
    printf("cols = ");
    scanf_s("%d", &cols);

    printf("Your matrix:\n");
    int** matr = generate(rows, cols);
    output(matr, rows, cols);

    printf("K = ");
    scanf_s("%d", &K);
    int** m0 = generate(rows, K);
    printf("Second matrix:\n");
    output(m0, rows, K);

    int** new_m = (int **)calloc(rows, sizeof(*new_m));
    for(int i = 0; i < rows; i++) {
        new_m[i] = (int *) calloc(cols + K, sizeof(*new_m[i]));
        for (int j = 0; j < cols + K; j++) {
            if (j > K - 1) {
                new_m[i][j] = matr[i][j - K];
            } else {
                new_m[i][j] = m0[i][j];
            }
        }
    }
    cols += K;
    printf("New matrix:\n");
    output(new_m, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(matr[i]);
        free(m0[i]);
        free(new_m[i]);
    }

    system("pause");
    return 0;
}
