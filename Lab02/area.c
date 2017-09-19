/* Autor: Cristobal Liendo I.
 * Fecha: 06/09/17
 * Obtiene el area de un circulo a partir de su radio
*/

#include <stdio.h>

int main() {
    float r, pi;
    pi = 3.14159;

    printf("Ingrese el radio del circulo: ");
    scanf("%f", &r);

    printf("El area del circulo es %.4f unidades\n", (pi * r * r));

    return 0;
}
