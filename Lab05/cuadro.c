/*
 * Autor: Cristobal Liendo I.
 * Fecha: 25/09/17
 * Descripcion: pide un numero y hacer un cuadro de n * n
*/

#include <stdio.h>

int main() {
    int n, row, column;
    printf("Ingrese un numero, entre el 1 y el 50: ");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("No entra dentro del rango.\n");
        return -1;
    }

    for (column = 0; column < n; column++) {
        for (row = 0; row < n; row++) {
            if (column == 0 || column == (n - 1))
                printf("*");
            else if (row == 0 || row == (n - 1))
                printf("*");
            else
                printf(" ");
        }

        printf("\n");
    } 
}
