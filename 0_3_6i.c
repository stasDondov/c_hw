/* 0.3.6i
 * Напишить власні функції, що обчислюють наступні вирази та напишить
відповідні власні функції, що будуть рахувати похідні даних
функцій.
 */

#include <stdio.h>
#include <conio.h>
#include <math.h>

double sigmweight(float x) {
    return x * 1.0 / (1.0 + expf(-x));
}

double deriv(float x, float eps) {
    return (sigmweight(x + eps) - sigmweight(x)) / eps;
}

int main() {
    float x, eps = 0.001;
    printf("x = ");
    scanf("%f", &x);

    printf("deriv(sigmweight(x)) = %lf\n", deriv(x, eps));

    getch();
    return 0;
}
