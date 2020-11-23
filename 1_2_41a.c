/* 1.2.41a
 * Скласти  програми для обчислення добутків
а) P_n = П_(k=0)^n (a_k/3^k), де {a_0=a_1=1, a_2=3, a_k=a_(k-3)+a_(k-2)/2^(k-1), k=3,4,…;
 */

#include <stdio.h>
#include <math.h>
#include <conio.h>

double dobutok (int k) {
    if (k == 0 || k == 1) return 1;
    else if (k == 2) return 3;
    else return dobutok(k - 3) + dobutok(k - 2) / powf(2, k - 1);
}

int main() {
    int k;
    printf("k = ");
    scanf("%d", &k);

    printf("Pn = %lf\n", dobutok(k) / powf(3, k));
    getch();
    return 0;
}
