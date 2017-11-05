/*
 * autor: cristobal liendo i
 * fecha: 01/11/17
 * descripcion: juego de cartas
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct carta {
    char palo[10];
    char valor[3];
    
    int puntaje;
};

struct baraja {
    int puntaje_total;
    int index;
    struct carta cartas[5];
};

void shuffle(struct carta *b_cartas) {
    int index1, index2;
    struct carta tmp;

    for (int i = 0; i < 52; i++) {
        index1 = rand() % 52;
        index2 = rand() % 52;

        tmp = b_cartas[index1];
        b_cartas[index1] = b_cartas[index2];
        b_cartas[index2] = tmp;
    }
}

void imprime_cartas(struct carta *b_cartas, int start, int finish) {
    int num = finish - start;
    int c_index = start, len = 0;

    for (int row = 0; row < 7; row++) {
        for (int column = 0; column < (12 * num) - 2; column++) {
            if ((row == 0 || row == 6) && (column % 12 != 10 && column % 12 != 11))
                printf("-");
            else if (column % 12 == 0 || column % 12 == 9)
                printf("*");
            else if (row == 1 && column % 12 == 7)
                printf("%s", b_cartas[c_index].valor);
            else if (row == 3 && column % 12 == 1)
                printf("%s", b_cartas[c_index].palo);
            else if ((column % 12 != 8 && row == 1) || (row != 1 && row != 3) || (row == 3 && (column % 12 < 1 || column % 12 > 9)))
                printf(" ");

            if (column % 12 == 0 && column != 0)
                c_index++;
        }

        c_index = start;
        printf("\n");
    }
}

char eleccion() {
    char op;

    do {
        printf("Que carta quieres, derecha [d] o izquierda [i]? ");
        scanf("%c", &op);
        getchar();
    } while (op != 'i' && op != 'd');

    return op;
}

void agrega_carta(struct baraja *baraja1, struct carta a_carta) {
    baraja1->puntaje_total += a_carta.puntaje;
    baraja1->cartas[baraja1->index] = a_carta;
    baraja1->index++;
}

int main() {
    srand(time(0));

    struct carta baraja_total[52];

    char palos[4][10] = {" corazon", "diamante", " espada ", " trevol "};
    char valores[13][3] = {" A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K"};

    // Crea la baraja del jugador y de la computadora
    struct baraja b_jugador, b_computadora;
    b_jugador.index = 0;
    b_computadora.index = 0;

    b_jugador.puntaje_total = 0;
    b_computadora.puntaje_total = 0;

    // Define la eleccion del usuario
    char op;

    // Variables que mantienen el control de que cartas
    // son las que se encuentran en los extremos
    int l = 0, r = 9;

    //Crea las cartas del juego
    int palo_index = 0;
    for (int i = 0; i < 52; i++) {
        strcpy(baraja_total[i].palo, palos[palo_index]);
        strcpy(baraja_total[i].valor, valores[i % 13]);
        baraja_total[i].puntaje = (i % 13) + 1;

        if ((i % 13) + 1 == 13)
            palo_index++;
    }

    //Imprime las cartas del juego
    imprime_cartas(baraja_total, 0, 13);
    imprime_cartas(baraja_total, 13, 26);
    imprime_cartas(baraja_total, 26, 39);
    imprime_cartas(baraja_total, 39, 52);
    printf("\n");

    //Imprime desordenadas
    shuffle(baraja_total);
    printf("\n");
    imprime_cartas(baraja_total, 0, 13);
    imprime_cartas(baraja_total, 13, 26);
    imprime_cartas(baraja_total, 26, 39);
    imprime_cartas(baraja_total, 39, 52);

    for (int i = 0; i < 5; i++) {
        printf("\n");
        imprime_cartas(baraja_total, l, r + 1);

        op = eleccion();

        // El jugador escogio el de la derecha
        if (op == 'd') {
            agrega_carta(&b_jugador, baraja_total[r]);
            agrega_carta(&b_computadora, baraja_total[l]);
        }
        // El jugador escogio el de la izquierda
        else {
            agrega_carta(&b_jugador, baraja_total[l]);
            agrega_carta(&b_computadora, baraja_total[r]);
        }

        l += 10;
        r += 10;
    }

    printf("\nPuntajes:\n");
    printf("\tJugador: %d", b_jugador.puntaje_total);
    printf("\tcomputadora: %d\n", b_computadora.puntaje_total);

    printf("\nCartas del jugador:\n");
    imprime_cartas(b_jugador.cartas, 0, 5);

    printf("\nCartas de la computadora:\n");
    imprime_cartas(b_computadora.cartas, 0, 5);

    return 0;
}
