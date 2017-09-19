/*
 * Autor: Cristobal Liendo i.
 * Fecha: 11/09/17
 * Diagrama de flujo
*/

#include <stdio.h>

int main() {
    int numero;
    printf("Que numero? ");
    scanf("%d", &numero);

    if (numero < 0)
        printf("Es negativo\n");
    else {
        if (numero == 0)
            printf("Es cero\n");
        else
            printf("Es positivo\n");
    }

    return 0;
}
