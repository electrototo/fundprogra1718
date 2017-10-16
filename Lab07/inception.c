/*
 * autor: cristobal liendo i.
 * fecha: 16/10/17
 * descripcion: recursion
*/

#include <stdio.h>

void dream(int);

int main() {
    printf("Estoy despierto, nivel 1. Listo para dormir...\n");
    dream(1);
    printf("Desperte en un avion aterrizando en LA\n");

    return 0;
}

void dream(int nivel) {
    if (nivel == 5)
        return;

    printf("Estoy durmiendo en el nivel %d\n", ++nivel);
    dream(nivel);
}
