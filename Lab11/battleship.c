/*
 * autor: cristobal liendo i
 * fecha: 10/11/17
 * descripcion: juego de battleship
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct jugador {
    char tablero[5][5];
    char tiros[5][5];
    int puntaje;

};

typedef struct jugador jugador;

struct posicion {
    int x;
    int y;
};

typedef struct posicion posicion;

struct control_computadora {
    int index;
    posicion posible[25];
};


void print_tablero(char tablero[5][5]) {
    for (int i = 5; i >= 0; i--) {

        for (int j = 0; j < 6; j++) {
            if (j < 5 && i > 0)
                printf("%c ", tablero[i - 1][j]);
            else if (j == 5 && i > 0)
                printf("|%d\n", i);
            else if (i == 0 && j < 6)
                printf("-%s", (j == 5) ? "\n" : "-");
        }

    }
    
    for (int i = 0; i < 5; i++)
        printf("%c%s", 'A' + i, (i == 4) ? "\n" : " ");
}

char to_lowercase(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        return letter;
    }
    else if(letter >= 'A' && letter <= 'Z')
        return letter + ('a' - 'A');
    else
        return 0;
}

char catoi(char letter) {
    return (letter >= '1' && letter <= '5') ? letter - '0' : -1;
}

int getxy(char *coord, int *x, int *y) {
    char c;
    int py;

    c = to_lowercase(coord[0]);
    py = catoi(coord[1]);

    if (!c || py == -1 || c > 'e')
        return 0;
    else {
        *x = c - 'a';
        *y = py - 1;

        return 1;
    }
}

int barco_pos(int n_barco) {
    int p;

    do {
        printf("Como deseas posicionar el barco %d?\n", n_barco);
        printf("[1] Vertical\n");
        printf("[2] Horizontal\n");
        printf("Opcion: ");
        scanf("%d", &p);
        printf("\n");
    } while (p != 1 && p != 2);

    return p;
}

int check_position(char tablero[5][5], int x, int y, int length, int orientation) {
    // orientation: 1 si es vertical, 2 si es horizontal
    int good = 1;

    if (orientation == 1) {
        // checa si el barco se encuentra dentro del tablero
        if ((y < 2 && length == 3) || (y < 1 && length == 2))
            good = 0;

        // checa que no haya algun barco dentro del rang
        for (int i = y; i > y - length; i--) {
            if (tablero[i][x] == '|' || tablero[i][x] == '=') {
                good = 0;
            }
        }
    }
    else {
        // checa si el barco se encuentra dentro del tablero
        if ((x > 2 && length == 3) || (x > 3 && length == 2))
            good = 0;

        // checa que no haya algun barco dentro del rang
        for (int i = x; i < x + length; i++) {
            if (tablero[y][i] == '|' || tablero[y][i] == '=') {
                good = 0;
            }
        }
    }

    return good;
}

void recorrer(struct control_computadora *c, int from) {
    posicion tmp;

    c->index--;
    for (int i = from; i < 24; i++) {
        tmp = c->posible[i];
        c->posible[i] = c->posible[i + 1];
        c->posible[i + 1] = tmp;
    }
}

int main() {
    printf("Instrucciones:\n");
    printf("El objetivo del juego es hundir todos los barcos enemigos.\n");
    printf("Al principio tendras que posicionar todos los barcos\n");
    printf("dentro de la cuadricula.");
    printf("\n\nTienes un barco de 3 unidades de longitud y otros dos barcos de\n");
    printf("dos de 2 unidades. Para poder ingresar las coordenadas\n");
    printf("tienes que poner la hilera (de la letra a hasta la e) y la\n");
    printf("columna (del 1 al 5) como el siguiente formato: a1 o A1.\n\n");
    printf("Se imprimen dos pantallas, la primera son tus barcos y la segunda\n");
    printf("muestra las posiciones en las que has tirado.\n\n");
    printf("Una x significa que le atinastte al barco enemigo, o que el enemigo\n");
    printf("le atino a un barco tuyo, mientras que una O significa que no le atinaste.\n\n");
    printf("El primero en hundir todos los barcos gana.\n\nBuena suerte.\n");
    srand(time(0));

    jugador jugador1, computadora;

    struct control_computadora c_tiros;
    c_tiros.index = 0;

    jugador1.puntaje = 0, computadora.puntaje = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            jugador1.tablero[i][j] = ' ';
            jugador1.tiros[i][j] = ' ';

            // control de la computadora
            computadora.tablero[i][j] = ' ';
            c_tiros.posible[c_tiros.index].x = j;
            c_tiros.posible[c_tiros.index++].y = i;
        }
    }

    char coordenadas[2], placeholder;
    int x, y, orientacion, validas = 1, length = 3;

    // Llena de forma aleatoria los barcos de la computadora
    for (int i = 0; i < 3; i++) {
        orientacion = (rand() % 2) + 1;
        length = (i == 0) ? 3 : 2;

        if (orientacion == 1)
            placeholder = '|';
        else
            placeholder = '=';

        // esto podria ser mejorado
        do {
            if (orientacion == 1) {
                x = rand() % 5;
                
                if (length == 3)
                    y = rand() % 3;
                else
                    y = rand() % 4;
            }
            else {
                if (length == 3)
                    x = rand() % 3;
                else
                    x = rand() % 4;

                y = rand() % 5;
            }
        } while(!check_position(computadora.tablero, x, y, length, orientacion));

        if (orientacion == 1) {
            for (int j = 0; j < length; j++)
                computadora.tablero[y--][x] = placeholder;
        }
        else {
            for (int j = 0; j < length; j++)
                computadora.tablero[y][x++] = placeholder;
        }
    }

    printf("\nTablero de la computadora:\n");
    print_tablero(computadora.tablero);

    // Posiciona los barcos del jugador
    for (int i = 0; i < 3; i++) {
        printf("\n");
        orientacion = barco_pos(i + 1);

        length = (i == 0) ? 3 : 2;

        if (orientacion == 1)
            placeholder = '|';
        else
            placeholder = '=';

        do {
            validas = 1;

            printf("Ingresa las coordenadas: ");
            scanf("%s", coordenadas);

            if (getxy(coordenadas, &x, &y)) {
                // verificar si entra dentro del rango del tablero
                printf("Coordenadas: (%d, %d)\n", x, y);

                if (check_position(jugador1.tablero, x, y, length, orientacion)) {
                    if (orientacion == 1) {
                        for (int j = 0; j < length; j++)
                            jugador1.tablero[y--][x] = placeholder;
                    }
                    else {
                        for (int j = 0; j < length; j++)
                            jugador1.tablero[y][x++] = placeholder;
                    }
                }
                else
                    validas = 0;
            }
            else
                validas = 0;

            if (!validas)
                printf("\tCoordenadas no validas\n\n");

        } while (!validas);

        printf("\nTus barcos:\n");
        print_tablero(jugador1.tablero);
    }

    printf("\nEl juego ha inciado\n");
    int c_tiro = 0;
    while (jugador1.puntaje < 7 && computadora.puntaje < 7) {
        do {
            // Turno del jugador
            printf("Ingresa las coordenadas: ");
            scanf("%s", coordenadas);

            validas = 1;

            if (getxy(coordenadas, &x, &y)) {
                if (jugador1.tiros[y][x] != 'x' && jugador1.tiros[y][x] != 'O') {
                    if (computadora.tablero[y][x] == '|' || computadora.tablero[y][x] == '=') {
                        jugador1.tiros[y][x] = 'x';
                        jugador1.puntaje++;
                    }
                    else
                        jugador1.tiros[y][x] = 'O';
                }
                else {
                    printf("\tYa habias tirado en ese lugar, escoge una nueva coordenada\n");
                    validas = 0;
                }
            }
            else {
                printf("\tCoordenadas no validas.\n");
                validas = 0;
            }
        } while(!validas);


        // turno de la computadora
        c_tiro = rand() % c_tiros.index;
        x = c_tiros.posible[c_tiro].x;
        y = c_tiros.posible[c_tiro].y;

        if (jugador1.tablero[y][x] == '|' || jugador1.tablero[y][x] == '=') {
            jugador1.tablero[y][x] = 'x';
            computadora.puntaje++;
        }
        else {
            jugador1.tablero[y][x] = 'O';
        }

        recorrer(&c_tiros, c_tiro);

        // imprimir tableros
        printf("\nTus tiros:\n");
        print_tablero(jugador1.tiros);

        printf("\nTus barcos:\n");
        print_tablero(jugador1.tablero);
        printf("\n");
    }

    if (jugador1.puntaje == 7)
        printf("\nFelcidades, derrotaste a la flota enemiga\n");
    else
        printf("\nPerdiste, todos tus barcos se encuentran en el fondo del mar\n");

    return 0;
}
