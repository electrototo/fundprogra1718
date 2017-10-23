/*
 * autor: cristobal liendo i
 * fecha: 23/10/17
 * primeros caracteres
*/

#include <stdio.h>
#include <string.h>

void caracteres() {
    char texto1[40], texto2[40], texto3[40];

    printf("Introduce una frase: ");
    gets(texto1);

    strcpy(texto2, texto1);
    printf("Una copia de tu texto: %s\n", texto2);

    strncpy(texto3, texto1, 4);
    printf("Y sus 4 primeras letras son: %s\n", texto3);
}

int main() {

    caracteres();

    return 0;
}
