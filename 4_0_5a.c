/* 4.0.5a
 * Дано символьний файл. Групи символів, що відокремлені пропусками
(одним або кількома) і не містять пропусків усередині, називатимемо
словами. Скласти підпрограми для:
а) знаходження найдовшого слова у файлі;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 150      // максимальна довжина кожного зчитаного з файлу рядка


int main() {
    FILE* myfile = fopen("example.txt", "r");

    char* buffer = calloc(MAX, sizeof(*buffer));

    char* words[30];
    int k = 0;

    while (fgets(buffer, MAX, myfile) != NULL) {

        char* pch = strtok(buffer, " ");

        while (pch != NULL) {
            words[k] = (char*)malloc(strlen(pch) * sizeof(pch[0]));
            strcpy(words[k++], pch);
            pch = strtok(NULL, " ");
        }
    }
    fclose(myfile);

    char* answer;
    int len_answer = 0;

    for (int i = 0; i < k; i++) {
        int compare = (int)strlen(words[i]);
        if (strchr(words[i], '\n')) {
            compare--;
        }
        if (compare > len_answer) {
            answer = words[i];
            len_answer = compare;
        }
    }
    printf("The longest word is %s, its length = %d\n", answer, len_answer);

    return 0;
}
