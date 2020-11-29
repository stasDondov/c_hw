/* 1.2.28
 * Представити дане натуральне число як суму двох квадратів
натуральних чисел. Якщо це неможливо представити як суму трьох
квадратів. Якщо і це неможливо, представити у вигляді суми чотирьох
квадратів натуральних чисел.
 */

#include <stdio.h>
#include <math.h>
#include <conio.h>

int sqrt_sum (int n) {
    if (n == 2) {
        printf("2 = 1^2 + 1^2\n");
        return 0;
    }

    int q = (int)round(sqrt(n));
    for (int i = 1; i < q; i++) { // 2 доданка
        if (sqrt(n - i * i) - (int)sqrt(n - i * i) == 0) {
            printf("%d = %d^2 + %d^2\n", n, i, (int)sqrt(n - i * i));
            return 0;
        }
    }

    for (int i = 1; i < q; i++){ // 3 доданка
        for (int j = 1; j < q; j++) {
            if (sqrt(n - i * i - j * j) - (int)sqrt(n - i * i - j * j) == 0) {
                printf("%d = %d^2 + %d^2 + %d^2\n", n, i, j,
                       (int)sqrt(n - i * i - j * j));
                return 0;
            }
        }
    }

    for (int i = 1; i < q; i++){ // 4 доданка
        for (int j = 1; j < q; j++) {
            for (int k = 1; k < q; k++) {
                if (sqrt(n - i * i - j * j - k * k) - (int)sqrt(n - i * i - j * j - k * k) == 0) {
                    printf("%d = %d^2 + %d^2 + %d^2 + %d^2\n", n, i, j, k,
                           (int) sqrt(n - i * i - j * j - k * k));
                    return 0;
                }
            }
        }
    }

    printf("such sum doesn't exist\n");
    return 0;
}


int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);
    sqrt_sum(n);

    getch();
    return 0;
}
