/*
 * autores: elias cohen y cristobal liendo
 * fecha: 16/10/17
 * descripcion: cubilete
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// funcion dado: regresa un valor entre el 0 y 5
char dado();

// funcion menu: pregunta si el usuario quiere jugar o no
int menu();

// funcion menu_juego: pregunta si el usuario quiere tirar o no
int menu_juego();

// funcion selection_sort: ordena los contenidos de un arreglo de menor a mayor
void selection_sort(int *, int);

// funcion swap: funcion auxiliar del que hace uso selection sort para cambiar
//               de posicion dos numeros en un arreglo
void swap(int *, int *);

// funcion comparar: obtiene el puntaje de cada jugada
int comparar(int *, int);

// funcion imprimir dados: imprime los dados actuales
void imprimir_dados(int *dados);

// funcion preguntar_respuesta: pregunta si quiere cambiar el dado "numero",
//                              donde "numero" corresponde al numero del dado
int preguntar_respuesta(int numero);

// funcion calcular_puntaje: obtiene el puntaje total de la jugada
int calcular_puntaje(int *baraja);

int main() {
    int op;
    srand(time(0));

    op = menu();

    // los dados actuales del jugador y la computadora
    int computadora[5], jugador[5];

    // vaiables que controlan los turnos del jugador y la computadora
    int computadora_tira = 1;
    int jugador_tira = 1;

    // variables que controlan los puntajes del jugador y la computadora
    int puntaje_computadora = 0;
    int puntaje_jugador = 0;

    if (op == 1) {
        for (int i = 0; i < 5; i++) {
            if (computadora_tira) {
                // Obten los primeros 5 tiros de la computadora
                for (int i = 0; i < 5; i++)
                    computadora[i] = dado();

                // calcula el puntaje de la computadora
                puntaje_computadora = calcular_puntaje(computadora);

                // si el puntaje es mayor a 3, no vuelva a tirar
                if (puntaje_computadora > 3)
                    computadora_tira = 0;

                // de lo contrario, deja a la suerte si la computadora tira o no
                else if (puntaje_computadora == 3)
                    computadora_tira = rand() % 2;
            }

            if (jugador_tira) {
                // si no es el primer tiro que hace, pregunta que dados quiere
                // volver a tirar
                if (i != 0) {
                    for (int i = 0; i < 5; i++) {
                        if (preguntar_respuesta(i))
                            jugador[i] = dado();
                    }
                }
                // de lo contrario, tira todos los dados por primera vez
                else {
                    for (int i = 0; i < 5; i++)
                        jugador[i] = dado();
                }

                // calcula el puntaje del jugador
                puntaje_jugador = calcular_puntaje(jugador);
            }
            
            // Imprime los dados y puntajes del jugador y la computadora
            printf("Tus dados:\n");
            imprimir_dados(jugador);
            
            printf("Dados de la computadora:\n");
            imprimir_dados(computadora);

            printf("Puntaje de la ronda:\n");
            printf("\tPuntaje del jugador: %d\n", puntaje_jugador);
            printf("\tPuntaje de la computadora: %d\n", puntaje_computadora);

            // pregunta si el jugador quiere tirar o no
            if (i != 4)
                jugador_tira = !menu_juego();
        }

        // imprime los resultados de la partida
        if (puntaje_jugador > puntaje_computadora)
            printf("¡¡GANASTE!!\n");
        else if (puntaje_jugador < puntaje_computadora)
            printf("Perdiste\n");
        else
            printf("Empate\n");
    }

    return 0;
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
    int max = 0, actual = 1;

    for(int i = 1; i < length; i++) {
        if (jugada[i - 1] != jugada[i]) {
            cambios++;

            if (actual > max)
                max = actual;

            actual = 1;
        }
        else {
            actual++;
        }
    }

    if (actual > max)
        max = actual;

    switch (cambios) {
        // 5 iguales
        case 0:
            return 6;
            break;
        case 1:
            // 4 iguales
            if (max == 4)
                return 5;

            // 1 tercia y 1 par
            else if (max == 3)
                return 4;

            break;
        case 2:
            // 1 tercia
            if (max == 3)
                return 3;

            // 2 pares
            else if (max == 2)
                return 2;

            break;
        // 1 par
        case 3:
            return 1;
            break;
        // 0 iguales
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

    char d1, d2, d3, d4, d5;

    d1 = opciones[dados[0]];
    d2 = opciones[dados[1]];
    d3 = opciones[dados[2]];
    d4 = opciones[dados[3]];
    d5 = opciones[dados[4]];

    printf("----- ----- ----- ----- -----\n");
    printf("| %c | | %c | | %c | | %c | | %c |\n", d1, d2, d3, d4, d5);
    printf("----- ----- ----- ----- -----\n");
    printf("  0     1     2     3     4\n");
    printf("\n");
}

int preguntar_respuesta(int numero) {
    char respuesta;

    do {
        printf("Quieres cambiar el dado %d [s, n]? ", numero);
        scanf(" %c", &respuesta);
    } while (respuesta != 's' && respuesta != 'n');

    if (respuesta == 's')
        return 1;

    else
        return 0;
}

int calcular_puntaje(int *baraja) {
    int p;
    selection_sort(baraja, 5);
    p = comparar(baraja, 5);

    return p;
}
