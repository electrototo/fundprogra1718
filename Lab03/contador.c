/*
 * Autor: Cristobal Liendo I.
 * Fecha: 11/09/17
 * Ejemplo: Funcion for 
*/

#include <stdio.h>

void contador();

int main() {
    contador();

    return 0;
} /* Fin del programa */

void contador(void) {
    int count = 1; /* Declaracion/inicio de variable */
    int stop;

    printf("Hasta donde guste que cuente? ");
    scanf("%d", &stop);

    for (count = 1; count <= stop; count++) /* Funcion ciclica */
            printf("%d\n", count); /* Imprimir en pantalla */
}
