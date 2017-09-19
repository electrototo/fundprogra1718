/*
 * Autor: Cristobal Liendo I.
 * Fecha: 04/09/17
 * Ejemplo de variables float
*/

#include <stdio.h>

void numReales();

int main() {
    numReales();
    return 0;
}

void numReales(void) {
    float x = 12.56;

    printf("El valor de x es: %f\n", x);
    printf(" pero lo podemos escribir con 2 decimales: %5.2f\n", x);
    printf(" o solo con uno %5.1f\n", x);
    printf(" o con 7 cifras %7.1f\n", x);
    printf(" o alineado a la izquierda %-7.1f\n", x);
    printf(" o sin decimales %2.0f\n", x);
    printf(" o solo con una cifra %1.0f\n", x);
}
