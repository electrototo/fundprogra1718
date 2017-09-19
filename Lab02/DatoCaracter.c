/*
 * Autor: Cristobal Liendo I.
 * Fecha: 04/09/17
 * Ejemplo de variables char
*/

#include <stdio.h>

void DatoCaracter();

int main() {

    DatoCaracter();
    return 0;
}

void DatoCaracter(void) {
    char a = 'A';
    char b = 'B';
    char c = 'C';

    printf("Las primeras tres letras del abecedario son: %c, %c, %c\n", a, b, c);
}
