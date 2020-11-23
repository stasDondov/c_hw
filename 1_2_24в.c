/* 1.2.24в
 * Задані натуральне число n, дійсні числа y_1,…y_n. Скласти  програму визначення:
в) z_1+z_2+ ... +z_n, де z_i={y_i, при 0<y_i<10; 1 у інших випадках}
 */

#include <stdio.h>
#include <conio.h>

int main() {
    int n;
    float y, z = 0;
    printf("n = ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("y%d = ", i + 1);
        scanf("%f", &y);
        if (0 < y && y < 10) z += y;
        else z++;
    }

    printf("z = %f\n", z);

    getch();
    return 0;
}
