/*
 * Autor: Cristobal Liendo I.
 * Fecha: 25/09/17
 * Descripcion: Pide 4 letras y las imprime de manera inversa
*/

#include <stdio.h>

int main() {
    char a, b, c, d;
    printf("Ingrese cuatro letras, separadas por un espacio: ");
    scanf("%c %c %c %c", &a, &b, &c, &d);

    do {
        printf("\"%c%c%c%c\"\n", d, c, b, a);
    }
    while (0);

    return 0;
}
