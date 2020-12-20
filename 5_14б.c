/* 5.14б
 *  Задано вектор розмірності N, компоненти якого містять інформацію
про студентів деякого вишу. Відомості про кожного студента містять дані
про його прізвище, ім'я, по батькові, стать, вік, курс. Визначити процедуру
пошуку:
 б) прізвищ та ініціалів усіх студентів, вік яких є найпоширенішим.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* surname;
    char* first_name;
    char* second_name;
    char* gender;  // male / female
    int age;
    int course;
} Student;


void print_info (Student* A)
{
    // виводить інформацію про 1 студента
    printf("%s %s %s %s %d %d\n", A->surname, A->first_name, A->second_name,
            A->gender, A->age, A->course);
}


Student* read_info (char* filename)
{
    FILE* myfile = fopen(filename, "r");
    Student* arr = calloc(10, sizeof(Student));  // припустимо що найбільша кількість студентів про яких є дані в файлі - 10

    int N;
    char* buffer = calloc(150, sizeof(*buffer));

    int t=0;
    while (fgets(buffer, 150, myfile) != NULL) {
        char* words[6];
        int k = 0;
        char* pch = strtok(buffer, ", ");

        while (pch != NULL) {
            words[k] = (char*)malloc(strlen(pch) * sizeof(pch[0]));
            strcpy(words[k++], pch);
            pch = strtok(NULL, " ");
        }
        arr[t].surname = words[0];
        arr[t].first_name = words[1];
        arr[t].second_name = words[2];
        arr[t].gender = words[3];
        arr[t].age = atoi(words[4]);
        arr[t].course = atoi(words[5]);
        t++;
    }
    return arr;
}


void find_students (Student* arr, int N)
{
    // знайдемо найпоширеніший вік
    int num, k, max_k;
    num = arr[0].age;
    max_k = 1;
    for (int i = 1; i < N; i++) {
        k = 1;
        for (int j = i + 1; j < N; j++)
            if (arr[i].age == arr[j].age)
                k += 1;
        if (k > max_k) {
            max_k = k;
            num = arr[i].age;
        }
    }

    printf("\nStudents with the most common age (%d y.o.):\n", num);
    for (int i = 0; i < N; i++) {
        if (arr[i].age == num) {
            printf("%s %c. %c.\n", arr[i].surname, arr[i].first_name[0], arr[i].second_name[0]);
        }
    }
}



int main() {
    // для зручності зчитуватимемо інформацію з файлу
    Student* info = read_info("students.txt");
    int N = 0;
    printf("All students:\n");
    while (info[N].surname != NULL) {
        print_info(&info[N]);
        N++;
    }
    find_students(info, N);

    system("pause");
    return 0;
}
