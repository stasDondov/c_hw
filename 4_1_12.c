/* 4.1.12
 * Додати в вказане місце файлу задану кількість рядків, починаючи
з зазначеного місця іншого файлу. Місце задається номером рядка.
Результат вивести в третій файл.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char* mySubstring (const char* myString, int i1, int i2) {
    // повертає підрядок myString[i1:i2]
    char* Substring = calloc(MAX, sizeof(*Substring));
    int i = 0;
    for (i; i < i2 - i1; i++) {
        Substring[i] = myString[i + i1];
    }
    return Substring;
}


int main() {
    int line, index;
    printf("Input line: ");
    scanf_s("%d", &line);
    printf("Input index: ");
    scanf_s("%d", &index);

    FILE* myfile1 = fopen("file1.txt", "r");
    FILE* myfile3 = fopen("file3.txt", "w");

    char* buffer = calloc(100, sizeof(*buffer));
    int k = 0;


    while (fgets(buffer, 100, myfile1) != NULL) {
        if (k == line) {
            fprintf(myfile3, "%s\n", mySubstring(buffer, 0, index));
            char* buffer2 = calloc(100, sizeof(*buffer2));
            FILE* myfile2 = fopen("file2.txt", "r");
            while (fgets(buffer2, 100, myfile2) != NULL) {
                fprintf(myfile3, "%s\n", mySubstring(buffer2, index, (int)strlen(buffer2) - 1));
            }
            fclose(myfile2);
            fprintf(myfile3, "%s\n", mySubstring(buffer, index, (int)strlen(buffer) - 1)); // останній символ перенесення рядка прибираємо
        } else {
            fprintf(myfile3, "%s\n", mySubstring(buffer, 0, (int)strlen(buffer) - 1));
        }
        k++;
    }

    fclose(myfile1);
    fclose(myfile3);

    return 0;
}
