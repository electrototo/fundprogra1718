/*
 *
 * descripcion: cubilete
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char dado();
int menu();
int menu_juego();
void swap(int *, int *);
void selection_sort(int *, int);
int comparar(int *, int);
void imprimir_dados(int *dados);

int main() {
    int op;
    srand(time(0));

    op = menu();

    int computadora[5], jugador[5];
    int tiro_actual = 0;

    int computadora_tira = 1;
    int jugador_tira = 1;

    int puntaje_computadora = 0;
    int puntaje_jugador = 0;

    char dado1, dado2, dado3, dado4, dado5;

    dado1 = dado2 = dado3 = dado4 = dado5 = 'n';

    if (op == 1) {

        do {
            if (computadora_tira) {
                // Obten los primeros 5 tiros de la computadora
                for (int i = 0; i < 5; i++)
                    computadora[i] = dado();

                selection_sort(computadora, 5);

                puntaje_computadora = comparar(computadora, 5);
            }

            if (puntaje_computadora == 5 || puntaje_computadora == 4)
                computadora_tira = 0;
            else if (puntaje_computadora == 3) {
                // deja a la suerte si la computadora tira o no
                computadora_tira = rand() % 2;
            }

            if (jugador_tira) {
                if (tiro_actual != 0) {
                    printf("\tQuieres cambiar el dado 0 [s,n]? ");
                    scanf(" %c", &dado1);

                    printf("\tQuieres cambiar el dado 1 [s,n]? ");
                    scanf(" %c", &dado2);

                    printf("\tQuieres cambiar el dado 2 [s,n]? ");
                    scanf(" %c", &dado3);

                    printf("\tQuieres cambiar el dado 3 [s,n]? ");
                    scanf(" %c", &dado4);

                    printf("\tQuieres cambiar el dado 4 [s,n]? ");
                    scanf(" %c", &dado5);

                    printf("\n");
                }
                else {
                    // Tira por primera vez

                    for (int i = 0; i < 5; i++)
                        jugador[i] = dado();
                }
                
                if (dado1 == 's')
                    jugador[0] = dado();

                else if (dado2 == 's')
                    jugador[1] = dado();

                else if (dado3 == 's')
                    jugador[2] = dado();

                else if (dado4 == 's')
                    jugador[3] = dado();

                else if (dado5 == 's')
                    jugador[4] = dado();

                dado1 = dado2 = dado3 = dado4 = dado5 = 'n';


                selection_sort(jugador, 5);
                puntaje_jugador = comparar(jugador, 5);

            }
            printf("Tus dados:\n");
            imprimir_dados(jugador);
            
            printf("Dados de la computadora:\n");
            imprimir_dados(computadora);

            printf("Puntaje de la ronda:\n");
            printf("\tPuntaje del jugador: %d\n", puntaje_jugador);
            printf("\tPuntaje de la computadora: %d\n", puntaje_computadora);

            jugador_tira = !menu_juego();

            tiro_actual++;

        } while (tiro_actual < 5);

        if (puntaje_jugador > puntaje_computadora)
            printf("¡¡GANASTE!!\n");
        else if (puntaje_jugador < puntaje_computadora)
            printf("Perdiste\n");
        else
            printf("Empate\n");

    }

    else {
        return 0;
    }
}

int menu() {
    printf("[1] Iniciar juego\n");
    printf("[2] Salir\n");

    int n;

    do {
        printf("Opcion: ");
        scanf("%d", &n);
    } while (n < 1 || n > 2);

    printf("\n");

    return n;
}

int menu_juego() {
    printf("\n[0] Tirar\n");
    printf("[1] No tirar\n");

    int n;

    do {
        printf("Opcion: ");
        scanf("%d", &n);
    } while (n < 0 || n > 1);
    
    printf("\n");

    return n;
}

char dado() {
    return rand() % 6;
}

int comparar(int *jugada, int length) {
    int anterior;
    int cambios = 0, posibilidad = 0;

    anterior = jugada[0];
    for(int i = 1; i < length; i++) {
        if (anterior != jugada[i]) {
            if (i == 2 || i == 3)
                posibilidad = 1;

            cambios++;
        }

        anterior = jugada[i];
    }

    switch (cambios) {
        case 0:
            return 5;
            break;
        case 1:
            if (!posibilidad)
                return 4;
            else
                return 3;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

void selection_sort(int *n, int length) {
    int key, j;

    for (int i = 1; i < length; i++) {
        key = n[i];
        j = i - 1;

        while (key < n[j] && j >= 0) {
            swap(&n[j], &n[j+1]);
            j--;
        }
    }
}

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void imprimir_dados(int *dados) {
    char opciones[6] = {'9', '1', 'J', 'Q', 'K', 'A'};

    for (int i = 0; i < 5; i++) {
        printf("dado %d: %c\n", i, opciones[dados[i]]);
    }

    printf("\n");
}
