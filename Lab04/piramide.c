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

    int whitespaces = (stop - 'A');
    printf("Whitespaces: %d\n", whitespaces);

    int step = -1;

    for (row = 0; row < maxrow; row++) {
        //printf("Row %d, whitespaces: %d\n", row, whitespaces);
        //
        //maxrow
        for (column = 0; column < maxrow - whitespaces; column++) {
            if (whitespaces > column)
                printf("*");
            else {
                printf("A");
            }
        }

        printf("\n");

        whitespaces += step;

        if (whitespaces == 0)
            step = -step;
    }

    return 0;
}
