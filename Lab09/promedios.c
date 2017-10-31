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

    float promedios_salon[2][3];
    float promedios_colegio[2] = {0};

    float p_actual = 0, p_total = 0;

    int x;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++){
            p_actual = 0;

            for(int k = 0; k < 10; k++) {
                x = (rand() % 6) + 5;
                p_actual += x;
                p_total += x;

                promedios_colegio[i] += x;

                calis[i][j][k] = x;
            }

            promedios_salon[i][j] = p_actual / 10;
        }

        promedios_colegio[i] /= 30;
    }

    p_total /= 60;
    for (int i = 0; i < 2; i++) {
        printf("Calificaciones del colegio %d:\n\t", i + 1);
        printf("Promedio del colegio: %.2f\n\t", promedios_colegio[i]);

        for (int j = 0; j < 3; j++) {
            printf("Calificaciones del grupo %d:\n\t\t", j + 1);
            printf("Promedio del grupo: %.2f\n\t\t", promedios_salon[i][j]);

            for(int k = 0; k < 10; k++) {
                printf("%d%s", calis[i][j][k], (k == 9) ? "\n\n" : ", ");
            }
            printf("\t");
        }
        printf("\n");
    }

    printf("Promedio de todos los alumnos: %.2f\n", p_total);

    return 0;
}
