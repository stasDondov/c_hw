/* 1.1.16a
 *  Точка площини задана декартовими координатами (x, y).
Перевірити, чи належить вона:
а) трикутнику з вершинами А(x1, y1), B(x2, y2), C(x3, y3).
 */

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

double geron(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    return round(sqrt(p * (p - a) * (p - b) * (p - c)) * 1000.0) / 1000.0;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    double x1, y1, x2, y2, x3, y3, x, y, s1, s2, s3, S;

    printf("Вершина А:\n");
    printf("x1 = ");
    scanf("%lf", &x1);
    printf("y1 = ");
    scanf("%lf", &y1);
    printf("Вершина B:\n");
    printf("x2 = ");
    scanf("%lf", &x2);
    printf("y2 = ");
    scanf("%lf", &y2);
    printf("Вершина C:\n");
    printf("x3 = ");
    scanf("%lf", &x3);
    printf("y1 = ");
    scanf("%lf", &y3);
    printf("Точка для перевірки:\n");
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);

    s1 = geron(sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)),
               sqrt(pow(x - x2, 2) + pow(y - y2, 2)),
               sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));  // x, x1, x2
    s2 = geron(sqrt(pow(x2 - x, 2) + pow(y2 - y, 2)),
               sqrt(pow(x - x3, 2) + pow(y - y3, 2)),
               sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)));  // x, x2, x3
    s3 = geron(sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)),
               sqrt(pow(x - x3, 2) + pow(y - y3, 2)),
               sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2)));  // x, x1, x3
    S = geron(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)),
              sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2)),
              sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2)));  // x1, x2, x3

    if (s1 + s2 + s3 == S) {
        printf("належить\n");
    } else {
        printf("не належить\n");
    }

    getch();
    return 0;
}
