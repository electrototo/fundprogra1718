/*
 * autor: cristobal liendo i.
 * fecha: 11/10/17
 * descripcion: "juego" de dado
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int dado();

int main() {
    srand(time(0));
    printf("Juego de dado\n");

    printf("|---------------------------------|\n");
    printf("| N° tiro | Jugador 1 | Jugador 2 |\n");

    int p1 = 0, p2 = 0;
    int l1 = 0, l2 = 0;

    int ac1, ac2;
    char ganador[2];

    for (int i = 0; i < 20; i++){
        ac1 = dado();
        ac2 = dado();

        printf("|   %2d    |    %2d     |    %2d     |\n", i, ac1, ac2);

        switch (ac1) {
            case 5:
                p1++;
                break;

            case 6:
                l1++;
                break;

            default:
                break;
        }

        switch (ac2) {
            case 5:
                p2++;
                break;

            case 6:
                l2++;
                break;

            default:
                break;
        }

        sleep(1);
    }

    printf("|---------------------------------|\n");
    printf("\n");

    if (p1 > p2 && l1 < p1){
        printf("Jugador 1 gana con %d veces 5\n", p1);
        printf("Estadisticas: p1 %d veces 5, %d veces 6; p2 %d veces 5, %d veces 6\n", p1, l1, p2, l2);
    }

    else if (p1 < p2 && l2 < p2) {
        printf("Jugador 2 gana con %d veces 5\n", p2);
        printf("Estadisticas: p1 %d veces 5, %d veces 6; p2 %d veces 5, %d veces 6\n", p1, l1, p2, l2);
    }

    else {
        printf("Empate entre jugador 1 y 2\n");
        printf("Estadisticas: p1 %d veces 5, %d veces 6; p2 %d veces 5, %d veces 6\n", p1, l1, p2, l2);
    }

}

int dado() {
    return (rand() % 6) + 1;
}
