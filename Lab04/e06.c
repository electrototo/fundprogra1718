/*
 * Autor: Cristobal Liendo I.
 * Fecha: 18/09/17
 * Descripcion: Pide los tres lados de un triangulo y determina que tipo de
 * triangulo es
*/

#include <stdio.h>

int main() {
    float a, b, c;

    printf("Ingrese la longitud del primer lado: ");
    scanf("%f", &a);

    printf("Ingrese la longitud del segundo lado: ");
    scanf("%f", &b);

    printf("Ingrese la longitud del tercer lado: ");
    scanf("%f", &c);

    if (a < 0 || b < 0 || c < 0) {
        printf("\nLongitudes invalidas\n");
        return -1;
    }

    if (a != b && a != c && b != c)
        printf("\nEs un triangulo escaleno\n");

    else if (a == b && a != c || a == c && a != b || b == c && b != a)
        printf("\nEs un triangulo isoceles\n");

    else
        printf("\nEs un triangulo equilatero\n");

    return 0;
}
