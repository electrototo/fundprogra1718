/*
 * Autor: cristobal liendo i
 * Fecha: 11/10/17
 * Descripcion: switch statement
*/

#include <stdio.h>

int main() {
    char ch;
    printf("Introduzca una vocal: ");
    ch = getchar();

    switch (ch) {
        case 'a':
            printf("Se ha pulsado una a");
            break;
        case 'e':
            printf("Se ha pulsado una e");
            break;
        case 'i':
            printf("Se ha pulsado una i");
            break;
        case 'o':
            printf("Se ha pulsado una o");
            break;
        case 'u':
            printf("Se ha pulsado una u");
            break;
        default:
            printf("Error");
            break;
    }

    printf("\n");

    return 0;
}
