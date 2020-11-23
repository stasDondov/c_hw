/* 1.2.41б
 * б)  P_n=П_(k=1)^n a_k*b_k,
де {a_1=1, a_k=(sqrt(b_(k-1))+a_(k-1))/5, {b_1=1, b_k=2b_(k-1)+5a_(k-1)^2, k = 2,3,...
 */

#include <stdio.h>
#include <math.h>
#include <conio.h>

double a(int k);

double b (int k) {
    if (k == 1) return 1;
    else return 2 * b(k - 1) + 5 * pow(a(k - 1), 2);
}

double a (int k) {
    if (k == 1) return 1;
    else return (sqrt(b(k - 1) + a(k - 1))) / 5;
}


int main() {
    int k;
    printf("k = ");
    scanf("%d", &k);

    printf("Pn = %lf\n", a(k) * b(k));
    getch();
    return 0;
}
