/*
 * autor: cristobal liendo i.
 * fecha: 01/11/17
 * descripcion: arreglos a funciones
*/

#include <stdio.h>

void modificar(int *a) {
    int count;
    printf("\nDesde la funcion, despues de modificar los valores:\n");

    for(count = 0; count < 3; count++) {
        a[count] = 123;
        printf("a[%d] = %d\n", count, a[count]);
    }
}

int main() {
    int count, a[3];
    printf("\nDesde main, antes de llamar a a la funcion\n");

    for (count = 0; count < 3; count++) {
        a[count] = count + 1;
        printf("a[%d] = %d\n", count, a[count]);
    }

    modificar(a);
    printf("\nDesde main, despues de llamar a a la funcion\n");
    for (count = 0; count < 3; count++)
        printf("a[%d] = %d\n", count, a[count]);

    return 0;
}
