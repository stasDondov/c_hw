/* 3.0.7
 * 7) Створити функцію, що вводить матриці довільних розмірностей, виділяючи
відповідну пам’ять та функцію, що відповідно очищує пам’ять. Напишіть програму,
що вводить масив таких матриць, підраховує та створює як окремий масив добуток
всього масиву матриць, якщо це можливо, та в будь-якому варіанті коректно завершує
програму без витоків пам’яті.
*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 5  // найбільше значення для елемента матриці
#define MIN (-5) // найбільше значення для елемента матриці

int rnum = 52;  // rnum - число на основі якого генеруються випадкові числа


int** init_matr(int rows, int cols) {
    // виділяємо пам'ять для матриці розмірності rows * cols
    int** new = calloc(rows, sizeof(*new));
    for (int k = 0; k < rows; k++) {
        new[k] = calloc(cols, sizeof(*new[k]));
    }
    return new;
}


int** generate (int n, int m)
{
    srand(rnum);  // якщо використовати srand(time(NULL)), то будуть згенеровані однакові матриці
    int** arr = init_matr(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            arr[i][j] = rand() % (MAX - MIN + 1) + MIN;
        }
    }
    rnum++;
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


void clear (int** matr, int n)
{
    for (int i = 0; i < n; i++)
        free(matr[i]);
}


int** multiply_2_matr (int** A, int nrA, int ncA, int** B, int nrB, int ncB) { // матриці мають бути заповнені
    // ncA - number of cols in A, nrB - number of rows in B
    int** ans = init_matr(nrB, ncA);
    for (int i = 0; i < ncA; i++) {
        for (int j = 0; j < nrB; j++) {
            int sum = 0;
            for (int t = 0; t < nrA; t++) {
                sum += A[i][t] * B[t][j];
            }
            ans[i][j] = sum;
        }
    }
    return ans;
}


int** dobutok(int*** List, int N, int rows, int cols)  // N - к-кість матриць в масиві; Sizes - розміри матриці, Sizes[i][0] - rows
{                                                                                                  //   Sizes[i][1] - cols
    // множимо першу матрицю на другу, їх добуток на третю і так далі
    // матрицю А можна помножити на В, якщо к-кість стовпців А == к-кість рядків В
    // всі матриці однакового розміру, тому їх можна перемножити тільки якщо вони квадратні

    if (N == 1) return List[0];
    else if (N > 1) {
        if (raws == cols) {
            int **ans = multiply_2_matr(List[0], rows, cols, List[1], rows, cols);
            for (int k = 2; k < N; k++) {
                ans = multiply_2_matr(ans, rows, cols, List[k], rows, cols);
            }
            return ans;
        }
    }
    return 0;
}



int main() {
    int N;
    printf("Number of matrixes: N = ");
    scanf_s("%d", &N);

    int*** myArr = calloc(N, sizeof(*myArr));
    int rows, cols;

    printf("Number of rows: ");
    scanf_s("%d", &raws);
    printf("Number of cols: ");
    scanf_s("%d", &cols);
    for (int i = 0; i < N; i++) {
        myArr[i] = generate(rows, cols);
        printf("m[%d] = \n", i);
        output(myArr[i], rows, cols);
        printf("\n");
    }

    int** answer = dobutok(myArr, N, rows, cols);
    if (answer != 0) {
        printf("Dobutok matriz:\n");
        output(answer, rows, cols);
    } else {
        printf("Impossible to multiply matrixes\n");
    }

    system("pause");
    return 0;
}

