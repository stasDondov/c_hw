/* 1.2.2б
 * Скласти  програми для обчислення значень многочленів і виконати їх при заданих значеннях аргументів:
б) y=x^(2^n)+x^(2^(n-1))+ ... +x^4+x^2+1; n=4,x=1;
 */

#include <stdio.h>
#include <conio.h>
#include <math.h>

double polynom (float x, int n)
{
    double y = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) y++;
        else y += pow(x, pow(2, i));
    }
    return y;
}

int main() {
    float x = 1;
    int n = 4;

    printf("if n = 4, x = 1: y = %.3lf\n", polynom(x, n));

    getch();
    return 0;
}
