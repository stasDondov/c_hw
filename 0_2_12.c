/* 0.2.12
 * Знайти корені квадратного рівняння з коефіцієнтами a,b,c, якщо
відомо, що одбидва корені в ньому існують. Перевірте ваш розвязок на
коефіцієтах рівняння a=3,b=100,c=2.
 */

#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    float a, b, c, D;
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("c = ");
    scanf("%f", &c);

    D = sqrtf(powf(b, 2) - 4 * a * c);
    printf("x1 = %f, x2 = %f\n", (-b + D) / (2 * a), (-b - D) / (2 * a));

    getch();
    return 0;
}
