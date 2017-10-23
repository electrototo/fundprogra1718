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

// funcion insertion_sort: ordena los contenidos de un arreglo de menor a mayor
void insertion_sort(int *, int);

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
                for (int j = 0; j < 5; j++)
                    computadora[j] = dado();

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
                    for (int j = 0; j < 5; j++) {
                        if (preguntar_respuesta(j))
                            jugador[j] = dado();
                    }
                }
                // de lo contrario, tira todos los dados por primera vez
                else {
                    for (int j = 0; j < 5; j++)
                        jugador[j] = dado();
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

// imprime el menu inicial del juego
int menu() {
    printf("[1] Iniciar juego\n");
    printf("[2] Salir\n");

    int n;

    // repite hasta que el usuario ingrese una respuesta valida
    do {
        printf("Opcion: ");
        scanf("%d", &n);
    } while (n < 1 || n > 2);

    printf("\n");

    // regresa el valor ingresado por el usuario
    return n;
}

// menu que pregunta al usuario si quiere tirar sus dados
int menu_juego() {
    printf("\n[0] Tirar\n");
    printf("[1] No tirar\n");

    int n;

    // repite hasta que el usuario ingrese una respuesta valida
    do {
        printf("Opcion: ");
        scanf("%d", &n);
    } while (n < 0 || n > 1);
    
    printf("\n");

    // regresa el valor ingresado por el usuario
    return n;
}

// simula un dado que regresa 6 valores: 0 - 5
char dado() {
    return rand() % 6;
}

// calcula el puntaje de una baraja ordenada
int comparar(int *jugada, int length) {
    int anterior;

    // variables que almacenan la cuenta de numero unicos que
    // hay en el arreglo y el maximo de numeros iguales
    int cambios = 0;
    int max = 0, actual = 1;

    // recorre todo el contenido de los dados 
    for(int i = 1; i < length; i++) {
        // si el numero en el que se encuentra i no es igual al anterior
        if (jugada[i - 1] != jugada[i]) {
            // aumenta la variable cambios
            cambios++;

            // actualiza el maximo de numeros iguales si actual es mayor
            // al maximo previo
            if (actual > max)
                max = actual;

            // reinicia el conntador de actual a 1
            actual = 1;
        }
        // aumenta la variable actual si son iguales los numeros
        else {
            actual++;
        }
    }

    // compara por ultima vez si actual es mayor al maximo previo
    if (actual > max)
        max = actual;

    // cambia al numero de cambios que hubo dentro del arreglo
    // para poder determinar el puntaje
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

// algoritmo que ordena un arreglo de mayor a menor o de menor a mayor
// esta implementacion ordena los numeros del arreglo de menor a mayor

// para mayor informacion acerca este algoritmo, connsultar:
// Introduction to Algorithms, de Thomas H. Cormen, Charles E. Leeiserson,
// Ronald L. Rivest y Clifford Stein. Paginas 15 - 20.
void insertion_sort(int *n, int length) {
    int key, j;

    // recorre todo el arreglo
    for (int i = 1; i < length; i++) {
        // guarda el elemento actual en una variable
        key = n[i];
        // inicia una nueva variable un numero antes que la posicion actual
        // de i
        j = i - 1;

        // mientras que key (el elemento actual) sea menor al elemento previo,
        // intercambia ambos elementos y recorre una posicion a la izquierda
        while (key < n[j] && j >= 0) {
            swap(&n[j], &n[j+1]);
            j--;
        }
    }
}

// funcion auxiliar que sirve para intercambiar de posicion ambos elementos
// dentro de un arreglo
void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// imprime los dados de forma estilizada
void imprimir_dados(int *dados) {
    // debido a que los dados de los jugadores se guardan con numeros,
    // se debe hacer una relacion entre el numero y la cara de dado
    // adecuada
    char opciones[6] = {'9', '1', 'J', 'Q', 'K', 'A'};

    char d1, d2, d3, d4, d5;

    // guarda los dados en forma de caracteres
    d1 = opciones[dados[0]];
    d2 = opciones[dados[1]];
    d3 = opciones[dados[2]];
    d4 = opciones[dados[3]];
    d5 = opciones[dados[4]];

    // imprime los valores de los dados del jugador en forma de dados
    printf("----- ----- ----- ----- -----\n");
    printf("| %c | | %c | | %c | | %c | | %c |\n", d1, d2, d3, d4, d5);
    printf("----- ----- ----- ----- -----\n");
    printf("  0     1     2     3     4\n");
    printf("\n");
}

// pregunta si el usuario quiere cambiar su dado "numero"
int preguntar_respuesta(int numero) {
    char respuesta;

    // repite hasta que tenga una respuesta valida
    do {
        printf("Quieres cambiar el dado %d [s, n]? ", numero);
        scanf(" %c", &respuesta);
    } while (respuesta != 's' && respuesta != 'n');

    // si es s la respuesta, regesa verdadero
    if (respuesta == 's')
        return 1;

    // si no, regresa falso
    else
        return 0;
}

// calcula y regresa el puntaje de los dados del jugador
int calcular_puntaje(int *baraja) {
    int p;

    // combina los resultados de ambas funciones para obtener el puntaje
    // total
    insertion_sort(baraja, 5);
    p = comparar(baraja, 5);

    return p;
}
