/* 0.1.3
 * Ввести в двох різних рядках послідовно два дійсних числа та
обчислити значення їх різниці та добутку. Результат вивести в
десятковому представленні.
 */

#include <stdio.h>
#include <conio.h>

int main()
{
    float a, b;
    printf("a =");
    scanf("%f", &a);
    printf("b =");
    scanf("%f", &b);
    printf("a - b = %f\n", a - b);
    printf("a * b = %f\n", a * b);
    getch();
    return 0;
}
