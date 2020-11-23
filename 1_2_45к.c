/* 1.2.45к
 * Скласти  програми наближеного обчислення суми всіх доданків, абсолютна
величина яких не менше eps>0:
к) y=1/((1+x)^3)=1-((2*3)/2)*x+((3*4)/2)*x^2-((4*5)/2)*x^3+..., (|x|<1);
 */

#include <stdio.h>
#include <math.h>
#include <conio.h>


int main() {
    float x, eps = 0.0001f, y = 0, yi = eps + 1, i = 0;

    printf("-1 < x < 1:  x = ");
    scanf("%f", &x);

    while (fabs(yi) >= eps) {
        yi = powf(-1, i) * ((i+1) * (i+2) / 2.0) * powf(x, i);
        y += yi;
        i++;
    }

    printf("y = %f\n", y);
    getch();
    return 0;
}
