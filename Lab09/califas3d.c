/*
 * autor: cristobal liendo i.
 * fecha: 30/10/17
 * descripion: array3d
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int calis[2][3][10];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            for(int k = 0; k < 10; k++)
                calis[i][j][k] = (rand() % 6) + 5;

    for (int i = 0; i < 2; i++) {
        printf("Calificaciones del colegio %d:\n\t", i + 1);

        for (int j = 0; j < 3; j++) {
            printf("Calificaciones del grupo %d:\n\t\t", j + 1);

            for(int k = 0; k < 10; k++) {
                printf("%d%s", calis[i][j][k], (k == 9) ? "\n\n" : ", ");
            }
            printf("\t");
        }
        printf("\n");
    }

    return 0;
}
