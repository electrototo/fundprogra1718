/*
 * Autor: Cristobal Liendo I. 
 * Fecha: 13/09/17
 * Juego de imprimir numeros
*/

#include <stdio.h>

int main() {
    int stop, j, num;

    printf("Ingrese un numero entre el 1 y el 9: ");
    scanf("%d", &stop);

    if (stop < 1 || stop > 9) {
        printf("El numero ingresado no entra dentro del rango\n");
        return 1;
    }

    for (int i = 1; i <= stop; i++){
        if (i % 2 != 0)
            for (j = 1; j <= stop; j++)
                printf("%d", j);
        else
            for (j = stop; j >= 1; j--)
                printf("%d", j);

        printf("\n");

    }

    return 0;
}
