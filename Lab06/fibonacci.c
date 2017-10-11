/*
 * autor: cristobal liendo i
 * fecha: 11/10/17
 * descripcion: serie de fibonacci
*/

#include <stdio.h>

int main() {
    unsigned long fib1 = 0, fib2 = 1, tmp = 0;
    int stop;

    printf("Cuantos numeros de fibonacci? ");
    scanf("%d", &stop);

    for (int i = 0; i < stop; i++) {
        printf("%lu%s", fib1, (i == stop - 1) ? "\n" : ", ");

        tmp = fib1 + fib2;
        fib1 = fib2;
        fib2 = tmp;
    }

    return 0;
}
