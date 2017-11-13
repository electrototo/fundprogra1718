/*
 * autor: cristobal liendo i
 * fecha: 13/11/17
 * descripcion: mas apuntadores
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arreglo(int *a, int *b) {
    int arr[10];
    int max, index, valor;

    for (int i = 0; i < 10; i++) {
        valor = (rand() % 100) + 1;
        arr[i] = valor;

        if (i == 0) {
            max = valor;
            index = i;
        }
        else if (valor > max) {
            max = valor;
            index = i;
        }
    }

    *a = max;
    *b = index;
}

int main() {
    srand(time(0));
    
    int valor, posicion;
    arreglo(&valor, &posicion);

    printf("El maximo valor es %d\n", valor);
    printf("Y su posicion es la %d\n", posicion);

    return 0;
}

