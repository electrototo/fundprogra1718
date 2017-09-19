/*
 * Autor: Cristobal Liendo I.
 * Fecha: 18/09/17
 * Descripcion: Imprime una piramide de letras
*/

#include <stdio.h>

int main() {
    char stop;
    printf("Ingresa una letra mayuscula: ");
    scanf("%c", &stop);

    int row, column, maxrow;

    maxrow = ((stop - 'A') * 2) + 1;

    for (row = 0; row < maxrow; row++) {
        printf("Row %d\n", row);
    }

    return 0;
}
