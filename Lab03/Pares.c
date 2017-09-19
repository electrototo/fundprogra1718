/* 
 * Autor: Cristobal Liendo I.
 * Fecha: 11/09/17
 * Genera numeros pares. 0 es par porque es multiplo de 2 (2 * 0 = 0)
*/

#include <stdio.h>

int main() {
    int gen, i;

    printf("Primeros 50 pares: \n\n");

    for(gen = i = 0; i < 50; i++, gen += 2) {
        if (i < 49)
            printf("%d, ", gen);
        else
            printf("%d\n\n", gen);
    }

    return 0;
}
