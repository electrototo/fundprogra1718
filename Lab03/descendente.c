/*
 * Autor: Cristobal Liendo I.
 * Fecha: 11/09/17
 * Imprime los numeros pares desde n hasta 10, siendo
 * n un numero ingresado por el usuario, de manera descendente
*/

#include <stdio.h>

int main() {
    int high;
    printf("Ingrese un numero entre el 11 y el 200: ");
    scanf("%d", &high);

    if (high < 10 || high > 200) {
        printf("El numero ingresado no entra dentro del rango\n");
        return 1;
    }

    printf("\nNumeros pares entre el %d y el 10:\n", high);

    high = (high % 2 == 0) ? high : high - 1;

    while (high >= 10) {
        if (high > 10)
            printf("%d, ", high);
        else
            printf("%d\n\n", high);

        high -= 2;
    }

    return 0;
}
