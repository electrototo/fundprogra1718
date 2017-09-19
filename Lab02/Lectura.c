/*
 * Autor: Cristobal Liendo I.
 * Fecha: 04/09/17
*/

#include <stdio.h>

void leer();

int main() {
    
    leer();
    return 0;
}

void leer(void) {
    char letra;
    int numero;

    printf("Escribe un número: ");
    scanf(" %d", &numero);

    printf("Escribe una letra: ");
    scanf(" %c", &letra);

    printf("El número es %d y la letra es %c\n", numero, letra);
}
