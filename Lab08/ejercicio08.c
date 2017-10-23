/*
 * autor: cristobal liendo i
 * fecha: 23/10/17
 * descripcion: genera 10 numeros aleatorios entre el 0 y 100
 *              y muestra cual fue el mayor y a continuacion
 *              todos los numeros que son menores al mayor
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int nums[10], max = 0;

    printf("Serie original: \n\t");
    for (int i = 0; i < 10; i++) {
        nums[i] = (rand() % 100) + 1;

        if (nums[i] > max)
            max = nums[i];

        printf("%d%s", nums[i], (i == 9) ? "\n" : ", ");
    }

    printf("\nImprimiendo numeros que son menores a %d:\n", max);

    for (int i = 0; i < 10; i++)
        if (nums[i] < max)
            printf("\t%d\n", nums[i]);

    return 0;
}
