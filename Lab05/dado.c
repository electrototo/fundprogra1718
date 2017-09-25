/*
 * Autor: Cristobal Liendo I.
 * Fecha: 25/09/17
 * Decripcion: Simula un dado y cuenta las probabilidades
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice();

int main() {
    srand(time(0));
    static int times[6], total;

    for (int i = 0; i < 1000; i++)
        times[dice() - 1]++;

    printf("\nEl dado de la fortuna ha hablado!\n");

    for (int i = 0; i < 6; i++) {
        printf("Lado %d: %d veces\n", i+1, times[i]);
        total += times[i];
    }

    printf("Total: %d\n", total);

    return 0;
}

int dice() {
    return (rand() % 6 + 1);
}
