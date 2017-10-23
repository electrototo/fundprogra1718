/*
 * autor: cristobal liendo i.
 * fecha: 23/10/17
 * descripcion: pide 10 numeros, calcula la media y muestra
 *              aquellos que se encuentre por encima de la media
*/

#include <stdio.h>

int main() {
    float nums[10];
    float media = 0, actual;

    for (int i = 0; i < 10; i++) {
        printf("Ingresa el %d numero: ", i + 1);
        scanf("%f", &actual);

        nums[i] = actual;
        media += actual;
    }

    media /= 10;

    printf("\nLa media es %.2f, imprimiendo numeros que son mayores a esta: \n", media);

    for (int i = 0; i < 10; i++)
        if (nums[i] > media)
            printf("\tNumero mayor a la media: %.2f\n", nums[i]);

    return 0;
}
