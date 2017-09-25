/*
 * Autor: Cristobal Liedno I.
 * Fecha: 25/09/17
 * Descripcion: Imprime numeros aleatorios
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aleatorio(void);

int main() {
    aleatorio();
    return 0;
}

void aleatorio() {
    int n, n2, n3;
    srand(time(0));

    n = rand() % 10 + 1;
    n2 = rand() % 20 + 10;
    n3 = rand() % 100 + 1;

    printf("Un numero entre 1 y 10: %d\n", n);
    printf("Un numero entre 10 y 29: %d\n", n2);
    printf("Un numero entre 1 y 100: %d\n", n3);
}
