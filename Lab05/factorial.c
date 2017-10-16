/*
 * Autor: Cristobal Liendo I.
 * Fecha: 25/09/17
 * Descripcion: Calcula el factorial
*/

#include <stdio.h>

unsigned long factorial(unsigned long);

int main() {
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if (num > 20) {
        printf("Factorial demasiado grande\n");
        return -1;
    }

    if (num >= 0)
        printf("%d! = %lu\n", num, factorial(num));
    else
        printf("No existen los factoriales de numeros negativos\n");

    return 0;
}

unsigned long factorial(unsigned long n) {
    if (n <= 1)
        return 1;

    return n * factorial(n-1);
}
