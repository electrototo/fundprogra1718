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

    int step = -1;

    int start = 65;
    int now, sum;

    sum = 0;

    for (row = 0; row < maxrow; row++) {
        for (column = 0; column < maxrow - whitespaces; column++) {
            if (whitespaces > column)
                printf(" ");

            else {
                now = (sum) ? now + 1: start - (column - whitespaces);

                if (now == 'A')
                    sum = 1;

                printf("%c", now);
            }
        }

        printf("\n");

        whitespaces += step;
        start -= step;

        if (whitespaces == 0) {
            step = -step;
        }

        sum = 0;
    }

    return 0;
}
