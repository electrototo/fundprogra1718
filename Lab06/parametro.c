/*
 * Autor: Cristobal Liendo I.
 * Fecha: 09/10/17
 * Descripcion: Parametros de funciones
*/

#include <stdio.h>

int cuadrado(int);

int main() {
    int numero, resultado;

    numero = 5;
    resultado = cuadrado(numero);
    printf("El cuadrado del numero es %d", resultado);
    printf(" y el de 3 es %d\n", cuadrado(3));


    return 0;
}

int cuadrado(int n) {
    return n * n;
}
