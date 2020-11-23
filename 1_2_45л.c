/* 1.2.45л
 * Скласти  програми наближеного обчислення суми всіх доданків, абсолютна
величина яких не менше eps>0:
л) y=1/(1+x^2 )=1-x^2+x^4-x^6+...,(|x|<1);
 */

#include <stdio.h>
#include <math.h>
#include <conio.h>


int main() {
    float x, eps = 0.0001f, y = 0, yi = eps + 1, i = 0;

    printf("-1 < x < 1:  x = ");
    scanf("%f", &x);

    while (fabs(yi) >= eps) {
        yi = powf(-1, i) * powf(x, 2 * i);
        y += yi;
        i++;
    }

    printf("y = %f\n", y);
    getch();
    return 0;
}
