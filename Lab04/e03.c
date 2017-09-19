/*
 * Autor: Cristobal Liendo I.
 * Fecha: 18/09/17
 * Pide numeros hasta que un cero sea encontrado
 * Imprime max y min
*/

#include <stdio.h>

int main() {
    int max, min;
    int num;

    int init = 0;

    printf("Escriba 0 cuando desee imprimir el maximo y minimo\n\n");

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    while(num != 0) {
        if (!init) {
            max = min = num;
            init = 1;
        }

        max = (num > max) ? num : max;
        min = (num < min) ? num : min;

        printf("Ingrese un numero: ");
        scanf("%d", &num);
    }

    if (init) {
        printf("Numero maximo: %d\n", max);
        printf("Numero minimo: %d\n", min);
    }

    return 0;
}
