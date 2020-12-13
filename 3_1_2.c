/* 3.1.2
 * 2) Дано рядок, серед символів якого є принаймні одна кома, а може й немає її. Знайти номер
а) першої по порядку коми;
б) останньої по порядку коми;
в) кількості ком.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int function (char* Str, char el)
{
    char* first;
    char* last;
    int counter = 0;

    first = strchr(Str, (int)el);
    if (first != NULL) {
        printf("First coma index: %d\n", first - Str);
    } else {
        printf("There are no comas\n");
        return 0;
    }

    last = strrchr(Str, (int)el);
    if (last != NULL) {
        printf("Last coma index: %d\n", last - Str);
    } else {
        printf("There is no second coma\n");
    }

    for (int i = 0; i < strlen(Str); i++) {
        if (Str[i] == ',') counter++;
    }
    printf("There are %d comas\n", counter);

    return 0;
}


int main() {
    char* S = calloc(30, sizeof(*S));
    fgets(S, MAX, stdin);

    function(S, ',');

    system("pause");
    return 0;
}
