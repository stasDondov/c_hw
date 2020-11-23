/* 0.2.10
 * Знайти об'єм конуса, якщо відомо його радіус основи та висоту.
 */

#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    double r, h;
    printf("r ="); // r - радіус основи
    scanf("%lf", &r);
    printf("h ="); // h - висота конуса
    scanf("%lf", &h);
    printf("V = %.3lf\n", 1.0/3.0 * pow(r, 2) * h * 3.1416); // V - об'єм конуса
    getch();
    return 0;
}
