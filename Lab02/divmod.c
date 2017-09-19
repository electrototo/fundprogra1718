/*
 * Autor: Cristobal Liendo I.
 * Fecha: 06/09/17
 * Pide dos numeros e imprime su division junto con su residuo
*/

#include <stdio.h>

int main() {
    int a, b;

    printf("Ingrese el primer numero entero: ");
    scanf("%d", &a);

    printf("Ingrese el segundo numero entero: ");
    scanf("%d", &b);

    printf("\nLa division de %d entre %d es: %d y su residuo es %d\n", a, b, (a / b), (a % b));

    return 0;
}
