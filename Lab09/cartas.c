/*
 * autor: cristobal liendo i
 * fecha: 01/11/17
 * descripcion: juego de cartas
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct carta Carta;
typedef struct baraja Baraja;

// Estructura que representa una sola carta
struct carta {
    char palo[10];
    char valor[3];

    int puntaje;
};

// Estructura que representa la baraja, es decir un conjunto
// de cartas
struct baraja {
    int puntaje_total;
    int index;
    struct carta cartas[5];
};

// Funcion que revuelve las cartas dentro de un arreglo
void shuffle(Carta *b_cartas) {
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

// Funcion que imprime las cartas de un arreglo
void imprime_cartas(Carta *b_cartas, int start, int finish) {
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

// Funcion que le pregunta al jugador cual es la carta que desea
// seguira preguntando hasta que ingrese una opcion valida
char eleccion() {
    char op;

    do {
        printf("Que carta quieres, derecha [d] o izquierda [i]? ");
        scanf(" %c", &op);
    } while (op != 'i' && op != 'd');

    return op;
}

// Funcion que agrega una carta a la baraja especificada
// de este modo solo se puede usar la misma funcion para
// ingresar cartas a distintas barajas
void agrega_carta(Baraja *baraja1, Carta a_carta) {
    baraja1->puntaje_total += a_carta.puntaje;
    baraja1->cartas[baraja1->index] = a_carta;
    baraja1->index++;
}

int main() {
    srand(time(0));

    // genera un arreglo de cartas el cual va a representar
    // todas las cartas que hay en juego
    Carta baraja_total[52];

    // Para no tener que generar las cartas de manera manual,
    // se especifican dentro de arreglos los valores y palos
    // que pueden tomar las distintas cartas
    char palos[4][10] = {" corazon", "diamante", " espada ", " trevol "};
    char valores[13][3] = {" A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K"};

    // Crea la baraja del jugador y de la computadora
    Baraja b_jugador, b_computadora;

    // Define la eleccion del usuario
    char op, repetir;

    // Variables que mantienen el control de que cartas
    // son las que se encuentran en los extremos
    int l, r;

    //Crea las cartas del juego
    int palo_index = 0;
    for (int i = 0; i < 52; i++) {
        // Copia el palo atual al palo de la carta,
        // al igual que el valor de las cartas especificado
        // en el arreglo bidimensional en "valores"
        strcpy(baraja_total[i].palo, palos[palo_index]);
        strcpy(baraja_total[i].valor, valores[i % 13]);

        // asigna un pntaje del 1 al 13 dependiendo del
        // valor de la carta
        baraja_total[i].puntaje = (i % 13) + 1;

        // cada 13 cartas cambia el palo actual de las
        // cartas
        if ((i % 13) + 1 == 13)
            palo_index++;
    }

    //Imprime las cartas del juego
    printf("Cartas ordenadas:\n");
    imprime_cartas(baraja_total, 0, 13);
    imprime_cartas(baraja_total, 13, 26);
    imprime_cartas(baraja_total, 26, 39);
    imprime_cartas(baraja_total, 39, 52);
    printf("\n");

    do {
        l = 0, r = 9;

        b_jugador.index = 0;
        b_computadora.index = 0;

        b_jugador.puntaje_total = 0;
        b_computadora.puntaje_total = 0;

        // Desordena e imprime desordenadas
        shuffle(baraja_total);
        printf("\nCartas desordenadas:\n");
        imprime_cartas(baraja_total, 0, 13);
        imprime_cartas(baraja_total, 13, 26);
        imprime_cartas(baraja_total, 26, 39);
        imprime_cartas(baraja_total, 39, 52);

        // El jugador tiene nada mas 5 intentos
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

            // dentro del arreglo de cartas, recorre 10 unidades
            l += 10;
            r += 10;
        }

        // Imprime los puntajes
        printf("\nPuntajes:\n");
        printf("\tJugador: %d", b_jugador.puntaje_total);
        printf("\tcomputadora: %d\n", b_computadora.puntaje_total);

        // Imprime las cartas del juador
        printf("\nCartas del jugador:\n");
        imprime_cartas(b_jugador.cartas, 0, 5);

        // Imprime las cartas de la computadora
        printf("\nCartas de la computadora:\n");
        imprime_cartas(b_computadora.cartas, 0, 5);

        do {
            printf("\n\nDeseas jugar de nuevo [s, n]? ");
            scanf(" %c", &repetir);
        } while (repetir != 's' && repetir != 'n');

    } while (repetir == 's');

    return 0;
}
