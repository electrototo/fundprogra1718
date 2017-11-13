/*
 * autor: cristobal liendo i
 * fecha: 13/11/17
 * descripcion: intercambia dos valores mediante apuntadores
*/

#include <stdio.h>

void swap(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 5, b = 8;

    printf("a: %d, b: %d\n", a, b);
    swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);

    return 0;
}
