/* 2.0.9i
 * 9) Вводиться масив натуральних чисел заданого розміру N:
і) визначити скільки серед них чисел, які містять рівно 5 біт в
 двійковому записі, що дорівнюють 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int binary(int num)
{
    char* bin = malloc(8 * sizeof(char));  // масив чисел у двоїчному представленні
    _strnset(bin, '0', 8);
    bin[8] = '\0';

    unsigned int n = num, s = 1;
    int k = 7, counter = 0; // counter - кількість 1 в двійковому записі
    while (n) {
        if (n & s) {
            bin[k] = '1';
            counter++;
        } else {
            bin[k] = '0';
        }
        n >>= s;  // s - крок в 1 біт
        k--;
    }
    printf("binary: %s\n", bin);
    if (counter == 5) {
        return 1;
    }
    return 0;
}


int main ()
{
    int N, ans = 0;
    printf("Input array size: N = ");
    scanf_s("%d", &N);

    int* mas = malloc(N * sizeof(int)); // масив натуральних чисел

    for (int i = 0; i < N; i++) {
        printf("mas[%d] = ", i);
        scanf_s("%d", &mas[i]);
        if (binary(mas[i])) {
            ans++;
        }
    }
    printf("Answer: %d\n", ans);

    system("pause");
    return 0;
}
