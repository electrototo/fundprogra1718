/*
 * autor: cristobal liendo i.
 * fecha: 18/10/17
 * descripcion: llenar arreglo
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int get_pos();

int main() {
    int arr[20];
    srand(time(0));

    for (int i = 0; i < 20; i++)
        arr[i] = 0;

    for (int i = 0; i < 20; i++)
        printf("Valor de la posicion %d: %d\n", i + 1, arr[i]);

    printf("\n");

    for (int i = 0; i < 20; i++)
        arr[i] = (rand() % 10) + 1;

    for (int i = 0; i < 20; i++)
        printf("Valor de la posicion %d: %d\n", i + 1, arr[i]);

    printf("\n");

    int pos, val;
    pos = get_pos();

    printf("Que valor quieres asignarle? ");
    scanf("%d", &val);

    arr[pos] = val;

    pos = get_pos();

    printf("Que valor quieres asignarle? ");
    scanf("%d", &val);

    arr[pos] = val;

    for (int i = 0; i < 20; i++)
        printf("Valor de la posicion %d: %d\n", i + 1, arr[i]);

    return 0;
}

int get_pos() {
    int pos;
    
    do {
        printf("Que posicion quieres cambiar? ");
        scanf("%d", &pos);
    } while(pos < 1 || pos > 20);

    return pos - 1;
}
