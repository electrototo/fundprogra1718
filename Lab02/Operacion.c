/*
 * Autor: Cristobal Liendo I.
 * Fecha: 04/09/17
 * Pide tres números y regresa la suma de los tres y su multiplicación
*/

#include <stdio.h>

int main() {
    int a, b, c;

    printf("Ingresa el primer número: ");
    scanf("%d", &a);

    printf("Ingresa el segundo número: ");
    scanf("%d", &b);

    printf("Ingresa el tercer número: ");
    scanf("%d", &c);

    printf("La suma de los tres números es: %d\n", (a + b + c));
    printf("La multplicación de los tres números es: %d\n", (a * b * c));

    return 0;
}
