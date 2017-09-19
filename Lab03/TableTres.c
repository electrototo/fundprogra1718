/* 
 * Autor: Cristobal Liendo I.
 * Fecha: 11/09/17
 * Imprime los primeros 50 multiplos de tres
*/

#include <stdio.h>

int main() {
    int m, i;

    printf("Primeros 50 multiplos de 3: \n\n");

    for (m = i = 0; i < 50; i++, m += 3) {
        if (i < 49)
            printf("%d, ", m);
        else
            printf("%d\n\n", m);
    }

    return 0;
}
