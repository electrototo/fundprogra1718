/*
 * Autor: Cristobal Liendo I.
 * Fecha: 25/09/17
 * Descripcion: Calcula el factorial
*/

#include <stdio.h>

unsigned long factorial(unsigned long);

int main() {
    for (int i = 0; i <= 10; i++)
        printf("%2d! %lu\n", i, factorial(i));

    return 0;
}

unsigned long factorial(unsigned long n) {
    if (n <= 1)
        return 1;

    return n * factorial(n-1);
}
