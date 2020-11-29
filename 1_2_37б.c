/* 1.2.37б
 * Скласти  програми обчислення довільного елемента послідовностей, заданих рекурентними співвідношеннями:
б) v_0=v_1=v_2=1, v_i=(i+4)(v_(i-1)-1)+(i+5)v_(i-3), i=3,4,…
 */

#include <stdio.h>
#include <conio.h>


int recur(int i) {
    if (i == 0 || i == 1 || i == 2) return 1;
    else return (i + 4) * (recur(i - 1) - 1) + (i + 5) * recur(i - 3);
}

int main() {
    int i;
    printf("i = ");
    scanf("%d", &i);

    printf("v%d = %d\n", i, recur(i));

    getch();
    return 0;
}
