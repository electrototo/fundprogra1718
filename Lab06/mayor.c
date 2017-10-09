/*
 * Autor: cristobal liendo i.
 * Fecha: 09/10/17
 * Descripcion: funcion que determina que numero es mayor
*/

#include <stdio.h>

float mayor(float, float);

int main() {
    float a, b;
    printf("Ingrese dos numeros, separados por un espacio: ");
    scanf("%f %f", &a, &b);

    printf("El numero mayor es: %.4f\n", mayor(a, b));

    return 0;
}

float mayor(float a, float b) {
    if (a > b)
        return a;
    else
        return b;
}
