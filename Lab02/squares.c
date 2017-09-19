/*
 * Autor: Cristobal Liendo I.
 * Fecha: 06/09/17
 * Comprueba que (a + b) * (a - b) es equivalente a a^2 - b^2
*/
#include <stdio.h>
#define sq(x) x * x

int main() {
    float a, b, f, s;
    
    printf("Ingrese el primer numero (a): ");
    scanf("%f", &a);

    printf("Ingrese el segundo numero (b): ");
    scanf("%f", &b);

    f = (a + b) * (a - b);
    s = sq(a) - sq(b);

    printf("\n(a + b) * (a - b): %.2f\n", f);
    printf("a^2 - b^2: %.2f\n", s);

    return 0;
}
