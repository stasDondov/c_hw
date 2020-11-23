/* 1.2.32а
 * Скласти  програми для обчислення добутків:
а) P_n=П_(i=1)^n(2+1/i!);
 */

#include <stdio.h>
#include <conio.h>

float factorial (int n) {
    float factorial = 1;
    for (int j = 1; j <= n; j++) {
        factorial *= (float)j;
    }
    printf("%f\n", factorial);
    return factorial;
}

int main() {
    int n;
    double Pn = 1;
    printf("n = ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        Pn *= (2.0 + (1.0 / (factorial(i))));
    }

    printf("Pn = %lf\n", Pn);
    getch();
    return 0;
}
