/* 5.0.1в
 *  Визначити типи запису для зображення таких понять:
в) дата (число, місяць, рік);
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int day, month, year;
} Date;


int input_date (Date* m)
{
    // введення дати з консолі
    printf("\nyear: ");
    scanf_s("%d", &m->year);
    printf("month: ");
    scanf_s("%d", &m->month);
    printf("day: ");
    scanf_s("%d", &m->day);
    if (m->year < 1 || (m->month < 1 || m->month > 12) || (m->day < 1 || m->day > 31)) {
        printf("Wrong input! Try again\n");
        return 0;
    }
    return 1;
}


void print_date (Date m) {
    // виводить дату в стандартному форматі
    if (m.day < 10) {
        printf("\n0%d.", m.day);
    } else {
        printf("\n%d.", m.day);
    }
    if (m.month < 10) {
        printf("0%d.", m.month);
    } else {
        printf("%d.", m.month);
    }
    printf("%d\n", m.year);
}


int main() {
    Date m = {-1, -1, -1}; // "ініціалізуємо" з неправильними значеннями
    while (!input_date(&m)) {     // якщо введені неправильні дані - введемо їх ще раз
        input_date(&m);
    }
    print_date(m);

    system("pause");
    return 0;
}