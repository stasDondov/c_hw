/* 1.1.19б
 * Реалізуйте функції та напишить відповідні власні функцію, що буде
рахувати похідні даних функцій:
б) ReLu(x) = max(0, x)
 */

#include <stdio.h>
#include <conio.h>

double ReLu(double x)
{
    if (x >= 0) {
        return x;
    } else {
        return 0;
    }
}

double deriv(float x, float eps) {
    return (ReLu(x + eps) - ReLu(x)) / eps;
}

int main() {
    float x, eps = 0.001;
    printf("x = ");
    scanf("%f", &x);

    printf("deriv(ReLu(x)) = %lf\n", deriv(x, eps));

    getch();
    return 0;
}
