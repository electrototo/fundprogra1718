/*
 * Autor: cristobal liendo i.
 * Fecha: 09/10/17
 * Descripcion variables globales
*/
#include <stdio.h>

void duplica();

int n = 5;

int main() {
    printf("n vale %d\n", n);
    duplica();
    printf("Ahora n vale %d\n", n);

    return 0;
}

void duplica() {
    n = n * 2;
}
