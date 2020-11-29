/*   2.0.12
 * Наступний спосіб призначений для шифрування послідовностей
нулів і одиниць (або ж, наприклад, точок і тире). Нехай a_1,…,a_n-
така послідовність. Те, що пропонується в якості її шифру, -це послідовність
b_1,…,b_n , утворена по наступному закону:
b_1=a_1, b_i={1,якщо a_i=a_(i-1); 0 в іншому випадку); i=2,...,n
Користуючись викладеним способом:
a)	Зашифрувати дану послідовність;
b)	Розшифрувати дану послідовність.
c)	"Виправлення помилок". Нехай по деякому каналу зв'язку передається
 повідомлення, що має вигляд послідовності нулів і одиниць (або, аналогічно,
 крапок і тире). Через перешкод можливий помилковий прийом деяких  сигналів:
 нуль  може  бути  сприйнятий  як  одиниця  і  навпаки.  Можна  передавати
 кожен  сигнал  тричі,  замінюючи,  наприклад,  послідовність  1, 0, 1
 послідовністю  1, 1, 1, 0, 0, 0, 1, 1.  Три послідовні цифри  при
 розшифровці  замінюються  тієї цифрою,  яка  зустрічається  серед них
 принаймні двічі. Таке  укроювання  сигналів  істотно підвищує
 ймовірність  правильного  прийому  повідомлення. Написати програму
 розшифровки.
 */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100  // максимальна довжина рядка для шифрування


void encrypt(char *list0, char *list1)
{
    /* list0 - послідовність, яку слід закодувати
     * функція запусує закодовану послівність в list1
     */
    list1[0] = list0[0];
    for (int i = 1; i < MAX; i++) {
        if (i < strlen(list0) - 1) {
            if (list0[i] == list0[i - 1]) {
                list1[i] = '1';
            } else {
                list1[i] = '0';
            }
        } else {
            list1[i] = '\0';
        }
    }
}

void decrypt(char *list0, char *list1)
{
    /* list0 - послідовність, яку слід розкодувати
     * функція запусує розкодовану послівність в list1
     */
    list1[0] = list0[0];
    for (int i = 1; i < MAX; i++) {
        if (i < strlen(list0)) {
            if (list0[i] != list1[i - 1]) {
                list1[i] = '0';
            } else {
                list1[i] = '1';
            }
        } else {
            list1[i] = '\0';
        }
    }
}

void reliable_encrypt(char *list0, char *list1)
{
    /* list0 - послідовність, яку слід розкодувати
     * функція запусує розкодовану послівність в list1
     */
    int N = (int)strlen(list0) - 1;
    for (int i = 0; i < MAX; i++) {
        int m = i / 3;
        if (m * 3 < ((N / 3) * 3) && i % 3 == 0) {   
            if ((int) list0[i] + (int) list0[i + 1] + (int) list0[i + 2] -
                48 * 3 >= 2) { // номер симолу 0 - 48, 1 - відповідно 49
                list1[m] = '1';
            } else {
                list1[m] = '0';
            }
        } else if (N - m * 3 == 2 && list0[m * 3] == list0[m * 3 + 1]) {
            if (list0[m * 3] == '0') {
                list1[m] = '0';
            } else {
                list1[m] = '1';
            }
        }
    }
    for (int i = 0; i < MAX; i++) {
        if (list1[i] != '0' && list1[i] != '1') {
            list1[i] = '\0';
        }
    }
}


int main ()
{
    char original[MAX];
    printf("Input your sequence of symbols 0 and 1:\n");
    fgets(original, MAX, stdin);   // for example 11100011

    char encrypted[MAX];
    encrypt(original, encrypted);
    printf("Encrypted: \n%s", encrypted);

    char decrypted[MAX];
    decrypt(encrypted, decrypted);
    printf("\nDecrypted: \n%s", decrypted);

    char reliably_decryptd[MAX];
    reliable_encrypt(original, reliably_decryptd);
    printf("\nReliably decrypted: \n%s\n", reliably_decryptd);

    getch();
    return 0;
}
