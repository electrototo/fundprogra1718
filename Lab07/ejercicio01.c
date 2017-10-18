/*
 * autor: cristobal liendo i.
 * fecha: 18/10/17
 * descripcion: llenar arreglo
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int arr[20];
    srand(time(0));

    for (int i = 0; i < 20; i++)
        arr[i] = 0;

    for (int i = 0; i < 20; i++)
        printf("Valor de la posicion %d: %d\n", i, arr[i]);

    printf("\n");

    for (int i = 0; i < 20; i++)
        arr[i] = (rand() % 10) + 1;

    for (int i = 0; i < 20; i++)
        printf("Valor de la posicion %d: %d\n", i, arr[i]);

    printf("\n");

    return 0;
}
