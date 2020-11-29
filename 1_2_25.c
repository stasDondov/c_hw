/* 1.2.25
 * б) Знайти період десяткового дробу для відношення n/m для заданих
натуральних чисел  n та m.
 */

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#define MAX 100   // перевірятимемо для періода з довжиной не більше 100


int division(int a, int b) // a - чисельник, b - знаменник
{
    setlocale(LC_ALL, "Ukrainian");

    if (b == 0) {
        printf("Ділення неможливе!\n");
        return 1;
    }

    // Ділення без остачі
    if (a % b == 0) {
        printf("Чисельник ділиться націло на знаменник: \n%d / %d = %d\n", a, b, a / b);
        return 0;
    }

    // Якщо знаменник - добуток степенів 2 та 5, то дріб можна представити у вигляді
    // u / 10^v, тобто він не періодичний
    int k = b;
    while (k % 2 == 0) {
        k = k / 2;
    }
    while (k % 5 == 0) {
        k = k / 5;
    }
    if (k == 1) {
        printf("Дріб неперіодичний: \n%d / %d = %g\n", a, b, (float)a / (float)b);
        return 0;
    }

    // Якщо дріб періодичний
    int mas[MAX], mas2[MAX];
    int stop = 0;

    printf("Періодичний дріб: \n%d / %d = ", a, b);

    if (a > b) {
        printf("%d,", a / b);
        a = a % b;
    } else {
        printf("0,");
    }

    mas[0] = a;
    int ind = 1; // індекс наступної комірки для залишку

    while (!stop) {
        if (a < b) {
            while (a < b){
                a *= 10;
                if (a >= 100 && (a % 100 == 0)) {
                    printf("0");
                }
            }
        }

        printf("%d", a / b);
        a = a % b;
        mas[ind] = a;

        for (int i = 0; i < ind; i++) {
            if (mas[i] == a) {
                stop = 1;
            }
        }
        ind++;
    }

    printf("(");
    stop = 0;
    //ind = 0;

    mas2[0] = a;
    ind = 1; // індекс наступної комірки для залишку

    while (!stop) {
        if (a < b) {
            while (a < b) {
                a *= 10;
                if (a >= 100 && (a % 100 == 0)) {
                    printf("0");
                }
            }
        }

        printf("%d", a / b);
        a = a % b;
        mas2[ind] = a;

        for (int i = 0; i < ind; i++) {
            if (mas2[i] == a) {
                stop = 1;
            }
        }
        ind++;
    }
    printf(")\n");
    return 0;
}


int main () {
    int n, m;
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);

    division(n, m);
    getch();
    return 0;
}
