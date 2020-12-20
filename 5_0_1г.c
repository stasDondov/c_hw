/* 5.0.1г
 *  Визначити типи запису для зображення таких понять:
г) адреса (місто, вулиця, будинок, квартира);
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char* city;
    char* street;
    char* house;
    int flat;
} Adress;


void print_adress (Adress* m, char* name) {
    printf("%s lives in %s, his adress is %s Street %s, flat %d\n", name, m->city, m->street, m->house, m->flat);
}

int main() {
    Adress p;
    p.city = "Zhitomir";
    p.street = "Vokzalna";
    p.house = "23a";
    p.flat = 11;

    print_adress(&p, "Slava");

    system("pause");
    return 0;
}
