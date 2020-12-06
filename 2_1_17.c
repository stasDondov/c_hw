/* 2.1.17
 * 17)	Отримати квадратну матрицю порядку n - 1 шляхом викидання з вихідної матриці
 * будь-якого рядка і стовпця, на перетині яких розташований елемент зі знайденим
 * значенням. Виконуйте до тих пір, поки не залишиться останній елемент.
 * Ймовірно ця задача є продовженням
 * 16)	У даній квадратній матриці порядку n знайти найбільший по модулю
 * елемент.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int** generate (int n, int MIN, int MAX)
{
    // створює матрицю порядку n і заповнює випадковими числами від MIN до MAX
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

void output (int** matr, int n)
{
    // виводить матрицю
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            printf("%3d ", matr[i][j]);
        }
        printf("\n");
    }
}


int find_el (int** matr, int n) // n - порядок матриці
{
    int **arr2 = NULL;

    while (n > 1) {
        arr2 = (int**)calloc(n, sizeof(*arr2)); // допоміжна матриця

        // знаходимо найбільший
        int biggest = matr[0][0], ii = 0, jj = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(matr[i][j]) > biggest) {
                    biggest = abs(matr[i][j]);
                    ii = i;
                    jj = j;
                }
            }
        }
        printf("biggest = %d  [%d][%d]\n", biggest, ii, jj);

        int iii, jjj; // допоміжні індекси
        // записуємо в допоміжну матрицю вихідну матрицю з викресленим рядком і стовпцем
        for (int i = 0; i < n; i++) {
            arr2[i] = (int *) calloc(n, sizeof(*arr2[i]));
            for (int j = 0; j < n; j++) {
                if (i < ii) {
                    iii = i;
                } else if (i != n - 1) {
                    iii = i + 1;
                }
                if (j < jj) {
                    jjj = j;
                } else if (j != n - 1) {
                    jjj = j + 1;
                }
                arr2[i][j] = matr[iii][jjj];
            }
        }

        // очистимо стару матрицю
        for(int i = 0; i < n; i++) free(matr[i]);
        n--;

        // перезапишемо в стару матрицю значення з допоміжної
        matr = (int **)calloc(n, sizeof(*arr2));
        for (int i = 0; i < n; i++) {
            matr[i] = (int *) calloc(n, sizeof(*matr[i]));
            for (int j = 0; j < n; j++) {
                matr[i][j] = arr2[i][j];
                printf("%3d", matr[i][j]);
            }
            printf("\n");
        }

        // очистимо допоміжну матрицю
        for (int i = 0; i < n; i++)
            free(arr2[i]);
    }
    return matr[0][0];
}


int main() {
    int n; // порядок матриці
    int MIN, MAX;
    printf("Input n (n should be even): ");
    scanf_s("%d", &n);
    printf("MIN = ");
    scanf_s("%d", &MIN);
    printf("MAX = ");
    scanf_s("%d", &MAX);

    int **mas = generate(n, MIN, MAX);
    printf("Your matrix:\n");
    output(mas, n);

    int last = find_el(mas, n);
    printf("The last element: %d\n", last);

    system("pause");
    return 0;
}
