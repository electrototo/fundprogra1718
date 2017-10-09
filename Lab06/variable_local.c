/*
 * Autor: cristobal liendo i.
 * Fecha: 09/10/17
 * Descripcion: variables locales
*/

void local();

#include <stdio.h>

int main() {
    int x = 5;

    local();

    printf("\nLa variable local x en main es: %d\n", x);

    return 0;
}

void local() {
    int x = 25;
    printf("\nLa variable local x tiene un valor de %d al ingresar a la funcion local\n", x);
    x++;
    printf("La variable local x tiene un valor de %d al salir de la funcion local\n", x);
}
