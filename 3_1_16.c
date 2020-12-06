/* 3.1.16
 * Скласти функцію підрахунку найбільшої кількості цифр, що йдуть підряд
у рядку А.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100   // обмеження на довжину рядка, що вводиться


int main() {
    char* A = calloc(MAX, sizeof(*A));
    fgets(A, MAX, stdin);
    int counter = 0, mem = 0;  // mem - найбільша кількість цифр, що йдуть підряд

    char prev_el = A[0];
    if (isdigit((int)A[0])) {
        counter = 1;
        mem = 1;
    }
    int i = 1;

    while (i < strlen(A)) {
        if (!isspace(A[i])) {
            if (isdigit((int)A[i])) {
                if (isdigit((int)prev_el)) {
                    counter++;
                } else {
                    counter = 1;
                }
            }
        }
        prev_el = A[i];
        if (counter > mem) {
            mem = counter;
        }
        i++;
    }

    printf("Answer: %d\n", mem);
    free(A);

    system("pause");
    return 0;
}
