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

void imprime_cartas(struct carta *b_cartas) {
    for (int i = 0; i < 52; i++) {
        printf("Carta:\n");
        printf("\tValor: %s\n", b_cartas[i].valor);
        printf("\tPalo: %s\n", b_cartas[i].palo);
        printf("\tPuntaje: %d\n", b_cartas[i].puntaje);
        printf("\n");
    }
}

int main() {
    srand(time(0));

    struct carta baraja_total[52];

    char palos[4][10] = {"corazon", "diamante", "espada", "trevol"};
    char valores[13][3] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    // Crea la baraja del jugador y de la computadora
    struct baraja b_jugador, b_computadora;

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
    imprime_cartas(baraja_total);

    //Imprime desordenadas
    shuffle(baraja_total);
    imprime_cartas(baraja_total);

    return 0;
}
