/*
 * Autor: Cristobal Liendo I.
 * Fecha: 11/09/17
 * Ejemplo: Funcion while
*/

#include <stdio.h>

void contador();

int main() {
    contador();

    return 0;
} /* Fin del Programa */

void contador(void) {

    int count = 1; /* Declaracion/Inicio de variable */
    while (count <= 10) { /* Funcion ciclica */
        printf("%d\n", count); /* Imprimir en pantalla */
        count += 1;
    }
}
