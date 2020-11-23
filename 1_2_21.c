/* 1.2.21
 * Скласти  програму друку таблиці значень функції y=sin(x) на
відрізку [0,1] з кроком h=0.1.
 */

#include <stdio.h>
#include <math.h>
#include <conio.h>

int main() {
    printf(" x  | sin(x)\n-------------\n");
    for (int i = 0; i <= 10; i++){
        printf("%3.1f | %.5f\n", i * 0.1, sin(0.1 * i));
    }

    getch();
    return 0;
}
