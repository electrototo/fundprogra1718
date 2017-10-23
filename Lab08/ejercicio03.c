/*
 * autor: cristobal liendo i
 * fecha: 23/10/17
 * descripcion: comparacion de cadenas
*/

#include <stdio.h>
#include <string.h>

void compara() {
    char texto1[40], texto2[40], texto3[40];

    printf("Introduce una palabra: ");
    gets(texto1);

    printf("Introduce otra palabra: ");
    gets(texto2);

    int comparacion = strcmp(texto1, texto2);

    if (comparacion == 0)
        printf("Son iguales.\n");
    else if (comparacion > 0)
        printf("La primera palabra es mayor.\n");
    else
        printf("La segunda palabra es mayor.\n");
}

int main() {

    compara();

    return 0;
}
