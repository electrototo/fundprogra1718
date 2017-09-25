/*
 * Autor: Cristobal Liendo I.
 * Fecha: 25/09/17
 * Descripcion: Juego de adivinanza
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_num();

int main () {
    //printf("Seed: %ld\n", time(0));
    srand(time(0));

    int t = 0, adivinado = 0;
    int input, numero;

    numero = rand_num();

    do {
        printf("\nIngresa un numero entre el 1 y el 100: ");
        scanf("%d", &input);

        if (numero == input)
            adivinado = 1;
        else if (input > numero)
            printf("\tEl numero que ingresaste es mayor al que tienes que adivinar\n");
        else
            printf("\tEl numero que ingresaste es menor al que tienes que adivinar\n");

        t++;
    }
    while (t < 5 && !adivinado);

    if (!adivinado)
        printf("\nSe te acabaron las oportunidades. El numero era: %d\n", numero);
    else
        printf("\nFelicidades! Adivinaste\n");

    return 0;
}

int rand_num() {
    return rand() % 100 + 1;
}
