/* 3.1.8e
 * В заданий рядок входять тільки цифри та літери. Визначити, чи задовольняє він
наступній властивості:
е) рядок складається тільки з цифр, причому їх числові значення складають арифметичну прогресію
 (наприклад, 3 5 7 9, 8 5 2, 2).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50  // максимальна довжина рядка для введення


int is_ar_progression (char* Str) {   // числа можуть бути багаторозрядними, тому вводяться через пробіл
    char* words[70];
    int k = 0;
    char* pch = strtok(Str, " ,.;");
    while (pch != NULL) {
        words[k] = (char*)malloc(strlen(pch) * sizeof(pch[0]));
        strcpy(words[k++], pch);
        pch = strtok(NULL, " ,.;");
    }

    if (k == 1) return 1;  // вважатимемо прогресією послідовність з 1 числа
    else if (k > 1) {
        int dif = atoi(words[1]) - atoi(words[0]);  // різниця прогресії
        for (int i = 0; i < k - 1; i++) {
            if (atoi(words[i + 1]) - atoi(words[i]) != dif) {
                return 0;
            }
        }
    } else return 0;

    return 1;
}


int main() {
    printf("Input your string: ");
    char* bufer = calloc(MAX, sizeof(*bufer));
    fgets(bufer, MAX, stdin);

    if (is_ar_progression(bufer)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}

