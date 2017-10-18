/*
 * autor: cristobal liendo i.
 * fecha: 18/10/17
 * descripcion: strings
*/

#include <stdio.h>

void cadena();

int main() {
    cadena();

    return 0;
}

void cadena() {
    char text[40];

    printf("Introduce tu nombre: ");
    scanf("%s", text);

    printf("Hola, %s\n", text);
    printf("Tu inicial es: %c\n", text[0]);
}
