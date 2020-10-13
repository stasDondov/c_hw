/*
Task 0.2.10
*/

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#pragma warning(disable:4996)


int main() {
    double r, h;
    printf("r = "); // r - радіус основи
    scanf("%lf", &r);
    printf("h = "); // h - висота конуса
    scanf("%lf", &h);
    printf("V = %lf\n", 1.0/3.0 * r * r * h * M_PI); // V - об'єм конуса
    getchar();
    return 0;
}
