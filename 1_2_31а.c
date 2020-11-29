/* 1.2.31a
 * Маємо дійсне число a. Скласти  програми обчислення:
а)  серед чисел 1, 1+1/2, 1+1/2+1/3,… першого, більшого за k;
 */

#include <stdio.h>
#include <conio.h>
#include <locale.h>


int main () {
    int i = 2;
    float k, sum = 1;
    printf("k = ");
    scanf("%f", &k);

    setlocale(LC_ALL, "Ukrainian");
    printf("Число 1");
    while (sum <= k) {
        printf (" + 1/%d", i);
        sum += 1.0f / (float)i;
        i++;
    }
    printf(" = %g - перше більше за %g\n", sum, k);

    getch();
    return 0;
}
