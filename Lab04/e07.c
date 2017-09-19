/*
 * Autor: Cristobal Liendo I.
 * Fecha: 18/09/17
 * Descripccion: pide un numero al 20 y dice si es primo o no
*/

#include <stdio.h>

int main() {
    int p, n;
    printf("Ingrese un numero entre el 1 y el 20: ");
    scanf("%d", &n);

    p = 1;

    if (n == 1) {
        printf("No es primo\n");
    }
    else if (n == 2) {
        printf("Primo!\n");
    }
    else {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                p = 0;
                break;
            }
        }

        if (p)
            printf("Primo!\n");

        else
            printf("No es primo\n");
    }

    return 0;
}
