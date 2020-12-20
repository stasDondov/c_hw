/* 7.0.8
 * Даний рядок, що складається з символів латинського алфавіту,
розділених пробілами (одним або декількома). Вивести рядок, що
містить ці ж слова, але розділені одним символом '.' (точка, крапка). В
кінці крапку не ставити.
 */

#include <iostream>
using namespace std;


int main()
{
    const size_t MAX = 45;    // максимальна довжина рядка
    char Str[MAX];
    cin.getline(Str, MAX);
    for (int i = 0; i < strlen(Str); i++) {
        if (isspace(Str[i])) {
            Str[i] = '.';
        }
    }
    cout << "New string: " << Str << endl;

    cin.get();
    return 0;
}
