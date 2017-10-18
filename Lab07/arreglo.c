/*
 * autor: cristobal liendo i.
 * fecha: 18/10/17
 * descripcion: arreglo
*/

#include <stdio.h>

void arreglo();

int main() {
    arreglo();

    return 0;
}

void arreglo(void) {
    int numero[5] = {200, 150, 100, -50, 300};
    int suma;

    suma = numero[0] + numero[1] + numero[2] + numero[3] + numero[4];

    printf("Su suma es %d\n", suma);
}
