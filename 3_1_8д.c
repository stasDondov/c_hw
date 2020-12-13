/* 3.1.8д
 * В заданий рядок входять тільки цифри та літери. Визначити, чи задовольняє він
наступній властивості:
д) рядок співпадає з початковим (кінцевим, будь-яким) відрізком ряду 0123456789
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10


char* mySubstring (const char* myString, int i1, int i2) {
    // повертає підрядок myString[i1:i2]
    char* Substring = calloc(MAX, sizeof(*Substring));
    int i = 0;
    for (i; i < i2 - i1; i++) {
        Substring[i] = myString[i + i1];
    }
    Substring[i] = '\n';
    return Substring;
}

int is_equal (char* Sub1, char* Sub2) {
    // перевіряє чи попарно рівні символи рядків
    if (strlen(Sub1) == strlen(Sub2)) {
        for (int i = 0; i < strlen(Sub1); i++) {
            if (Sub1[i] != Sub2[i]) {
                return 1;
            }
        }
    }
    return 0;
}

int is_subStr (char* Str, char* Sub) {
    // перевіряє чи є Sub підрядком Str
    for (int i = 0; i < strlen(Str) - strlen(Sub) + 2; i++) {
        char* subs = mySubstring(Str, i, i + strlen(Sub) - 1);
        if (!is_equal(subs, Sub)) {
            return 1;
        }
    }
    return 0;
}


int main() {
    char myStr[] = "0123456789";

    printf("Input substring: ");
    char* bufer = calloc(MAX, sizeof(*bufer));
    fgets(bufer, MAX, stdin);

    if (is_subStr(myStr, bufer)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
