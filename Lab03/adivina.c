/*
 * Autor: Cristobal Liendo I.
 * Fecha: 11/09/17
 * Juego de adivinanza
*/

#include <stdio.h>

int main() {
    int obj, c, oportunidades, adivinado, i;

    obj = 271; /* Numero aleatorio */
    oportunidades = 5;
    adivinado = i = 0;

    while (i < oportunidades && !adivinado) {
        printf("Ingresa un numero entre el 1 y el 1000: ");
        scanf(" %d", &c);

        if (c < 1 || c > 1000) {
            printf("\tEl numero no entra dentro del rango.\n\n");
        }
        else {
            if (c == obj) {
                printf("\tFelicidades, adivinaste!\n");
                adivinado = 1;
            }
            else if (c > obj) {
                printf("\tEl numero que ingresaste es mayor al que tienes que adivinar\n\n");
            }
            else {
                printf("\tEl numero que ingresaste es menor al que tienes que adivinar\n\n");
            }
        }

        i++;
    }

    if (!adivinado && i == oportunidades)
        printf("Lo lamento, no adivinaste.\n");

    return 0;
}
