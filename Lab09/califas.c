/*
 * autor: cristobal liendo i
 * fecha: 30/10/17
 * descripcion. 2d arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int califas[2][10];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 10; j++)
            califas[i][j] = (rand() % 6) + 5;

    printf("Las calificaciones del primer grupo son:\n");
    for (int i = 0; i < 10; i++)
        printf("%d%s", califas[0][i], (i == 9) ? "\n" : ", ");

    printf("\nLas calificaciones del segundo grupo son:\n");
    for (int i = 0; i < 10; i++)
        printf("%d%s", califas[1][i], (i == 9) ? "\n" : ", ");
}
