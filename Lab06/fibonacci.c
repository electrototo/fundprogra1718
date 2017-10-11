/*
 * autor: cristobal liendo i
 * fecha: 11/10/17
 * descripcion: serie de fibonacci
*/

#include <stdio.h>

int main() {
    unsigned long fib1 = 0, fib2 = 1, tmp;
    int stop;

    printf("Cuantos numeros de fibonacci? ");
    scanf("%d", &stop);
    if (stop == 1){
        printf("%d\n", 0);
    }
    else if (stop == 2) {
        printf("%lu, %lu\n", fib1, fib2);
    }
    else {
        stop -= 2;

        printf("%lu, %lu,", fib1, fib2);

        for (int i = 0; i < stop; i++) {
            tmp = fib1 + fib2;
            fib1 = fib2;
            fib2 = tmp;

            printf(" %lu%c", tmp, (i == stop - 1) ? '\n' : ',');
        }
    }

    return 0;
}
