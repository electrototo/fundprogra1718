/*
 * autores: elias cohen y cristobal liendo.
 * fecha: 17/10/17
 * descripcion: cubilete SIN arreglos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// funcion dado> regresa unn valor entre el 0 y 5
char dado();

// funcion menu: pregunta si el usuario quiere jugar o no
int menu();

// funcion menu_jugador: preguntta si el usuario quiere tirar oo no
int menu_jugador();

// funcioon imprimir_dados: imprime los dados actuales
void imprimir_dados(char d1, char d2, char d3, char d4, char d5);

// funcion calcular_puntaje: calcula el puntaje de la juggada actual
int calcular_puntaje(int d1, int d2, int d3, int d4, int d5, int d6);

// funcion preguntar_respuestta: pregunta que dado quiere cambiar el usuario
int preguntar_respuesta(int);

// funciones auxiliares que sirven para incrementar las variables
// j9 [...] ja y c9 [...], dependiendo del valor del dado tirado
void sumar_lados(char);
void restar_lados(char);

// Variables que llevan la cuenta de la cantidad de los mismos dados que han
// salido
static int j9, j10, jj, jq, jk, ja;
static int c9, c10, cj, cq, ck, ca;

// Variables que almacenan las caras actuales del dado
static int jd1, jd2, jd3, jd4, jd5;
static int cd1, cd2, cd3, cd4, cd5;

int main() {
    // inicializar la semilla de manera "aleatoria"
    srand(time(0));

    // pregunta al usuario si quiere jugar o no
    int option = menu();

    // variables que controlan los turnos del jugador y la computadora
    int tira_jugador = 1, tira_computadora = 1;
    char computadora_actual, jugador_actual;

    // variables que almacenan el puntaje actual del jugador y la computadora
    int puntaje_computadora, puntaje_jugador;

    // variable que almacena la respuesta del jugador
    char respuesta;

    if (option) {
        for (int numero_jugada = 0; numero_jugada < 5; numero_jugada++) {
            if (tira_computadora) {
                c9 = c10 = cj = cq = ck = ca = 0;

                // este for obtiene cinco numeros aleatorios de forma de dado
                // dependiendo del valor de i en el for, lo guardo en su variable
                for (int i = 0; i < 5; i++) {
                    computadora_actual = dado();

                    // se compara el valor actual de haber lanzado el dado
                    // esto es para poder llevar un control de cuantas caras
                    // del mismo lado salieron
                    switch (computadora_actual) {
                        case '9':
                            c9++;
                            break;

                        case '1':
                            c10++;
                            break;

                        case 'a':
                            ca++;
                            break;

                        case 'j':
                            cj++;
                            break;

                        case 'q':
                            cq++;
                            break;

                        case 'k':
                            ck++;
                            break;

                        default:
                            break;
                    }
                    // dependiendo del valor de la i, asiga el valor actual del dado
                    // a la cara correspondiente
                    switch (i) {
                        case 0:
                            cd1 = computadora_actual;
                            break;

                        case 1:
                            cd2 = computadora_actual;
                            break;

                        case 2:
                            cd3 = computadora_actual;
                            break;

                        case 3:
                            cd4 = computadora_actual;
                            break;

                        case 4:
                            cd5 = computadora_actual;
                            break;

                        default:
                            break;
                    }
                }

            }

            // a partir de los valores de cuantas veces salieron las caras,
            // calcula un punttaje para la computadora
            puntaje_computadora = calcular_puntaje(c9, c10, cj, cq, ck, ca);

            // si la computadora tuvo un puntaje de 3 o mayor (es decir una tercia o mayor),
            // asigna 0 a tira_computadora para que no vuelva a tirar.
            // se hizo de este modo porque es muy poco probabble que el usuario tenga
            // una mejor jugada
            if (puntaje_computadora >= 3)
                tira_computadora = 0;

            if (tira_jugador) {
                // si es la primera jugada, entonces tira todos los dados
                // y guardalos en sus variables correspondientes
                if (numero_jugada == 0) {
                    j9 = j10 = jj = jq = jk = ja = 0;

                    for (int i = 0; i < 5; i++) {
                        jugador_actual = dado();

                        // suma la cantidad total de cada lado que ha salido
                        sumar_lados(jugador_actual);

                        switch (i) {
                            case 0:
                                jd1 = jugador_actual;
                                break;

                            case 1:
                                jd2 = jugador_actual;
                                break;

                            case 2:
                                jd3 = jugador_actual;
                                break;

                            case 3:
                                jd4 = jugador_actual;
                                break;

                            case 4:
                                jd5 = jugador_actual;
                                break;

                            default:
                                break;
                        }
                    }
                }
                else {
                    // si no es la primera jugada y el usuario decidio volver a tirar,
                    // preguntarle que caras son las que desea cambiar
                    if (tira_jugador == 1) {
                        if (preguntar_respuesta(0)) {
                            restar_lados(jd1);
                            jd1 = dado();
                            sumar_lados(jd1);
                        }

                        if (preguntar_respuesta(1)) {
                            restar_lados(jd2);
                            jd2 = dado();
                            sumar_lados(jd2);
                        }

                        if (preguntar_respuesta(2)) {
                            restar_lados(jd3);
                            jd3 = dado();
                            sumar_lados(jd3);
                        }

                        if (preguntar_respuesta(3)) {
                            restar_lados(jd4);
                            jd4 = dado();
                            sumar_lados(jd4);
                        }

                        if (preguntar_respuesta(4)) {
                            restar_lados(jd5);
                            jd5 = dado();
                            sumar_lados(jd5);
                        }
                    }
                }
            }

            // imprime los dados actuales del usuario
            printf("Tus dados:\n");
            imprimir_dados(jd1, jd2, jd3, jd4, jd5);

            // imprime los dados acttuales de la computadora
            printf("Dados de la computadora:\n");
            imprimir_dados(cd1, cd2, cd3, cd4, cd5);

            // se obtiene el puntaje del jugador
            puntaje_jugador = calcular_puntaje(j9, j10, jj, jq, jk, ja);

            printf("Puntaje de la ronda:\n");
            printf("\tPuntaje del jugador: %d\n", puntaje_jugador);
            printf("\tPuntaje de la computadora: %d\n", puntaje_computadora);
            printf("\n");
            
            printf("\n");

            if (numero_jugada != 4)
                tira_jugador = menu_jugador();
        }

        // determina e imprime el puntaje final de ambos jugadores
        if (puntaje_computadora > puntaje_jugador)
            printf("\nPerdiste\n");

        else if (puntaje_jugador > puntaje_computadora)
            printf("\n¡¡GANASTE!!!\n");

        else
            printf("\nEmpate\n");

    }

    return 0;
}

// simula un dado que regresa un valor de los siguientes:
// 9, 1, j, q, k, a
// siendo 1 el numero 10, debido a que como es de tipo
// char, solo se puede almacenar un solo caracter
char dado() {
    int tiro = rand() % 6;
    char res;

    switch (tiro) {
        case 0:
            res = '9';
            break;

        case 1:
            res = '1';
            break;

        case 2:
            res = 'j';
            break;

        case 3:
            res = 'q';
            break;

        case 4:
            res = 'k';
            break;

        case 5:
            res = 'a';
            break;

    }

    return res;
}

// menu inicial del juego
int menu() {
    printf("[1] Iniciar juego\n");
    printf("[2] Salir\n");

    int n;

    // repite hasta que usuarioo ingrese un valor valido
    do {
        printf("Opcion: ");
        scanf("%d", &n);

    } while (n < 1 || n > 2);

    printf("\n");

    // regresa el valor que el usuario ingreso
    return n;
}

// imprime los dados de forma estilizada
void imprimir_dados(char d1, char d2, char d3, char d4, char d5) {
    // imprime los valores d1...d5 en forma de dados
    printf("----- ----- ----- ----- -----\n");
    printf("| %c | | %c | | %c | | %c | | %c |\n", d1, d2, d3, d4, d5);
    printf("----- ----- ----- ----- -----\n");
    printf("  0     1     2     3     4\n");
    printf("\n");
}

// menu que le pregunta al usuario si quiere tirar sus dados o conservarlos
int menu_jugador() {
    printf("[1] Tirar dados\n");
    printf("[2] No tirar\n");

    int n;

    // repite hasta que ingrese un valor valido
    do {
        printf("Opcion: ");
        scanf("%d", &n);
    } while (n < 1 || n > 2);

    printf("\n");

    return n;
}

// pregunta si el usuario quiere cambiar el dado "numero"
int preguntar_respuesta(int numero) {
    char respuesta;

    // repite hasta que el usuario ingrese un valor valido
    do {
        printf("Quieres cambiar el dado %d [s, n]? ", numero);
        scanf(" %c", &respuesta);
    } while (respuesta != 's' && respuesta != 'n');

    // si la respuesta es s, regresa verdadero
    if (respuesta == 's')
        return 1;
    // si n, regresa falso
    else
        return 0;
}

// calcula el puntaje dependiendo de las variables que almacenan
// la cantidad de veces que han salido las caras
int calcular_puntaje(int d1, int d2, int d3, int d4, int d5, int d6) {
    int puntaje = 0;

    // si al menos una cara salio 5 veces, asigna unn puntaje de 6
    if (d1 == 5 || d2 == 5 || d3 == 5 || d4 == 5 || d5 == 5 || d6 == 5)
        puntaje = 6;

    // si todas las caras salieron igual o menor a 1, el puntaje es de 0
    else if (d1 <= 1 && d2 <= 1 && d3 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
        puntaje = 0;

    else {
        // calcula si hubo solo un par
        if (d1 == 2 && d2 <= 1 && d3 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 1;

        else if (d2 == 2 && d1 <= 1 && d3 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 1;

        else if (d3 == 2 && d1 <= 1 && d2 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 1;

        else if (d4 == 2 && d1 <= 1 && d2 <= 1 && d3 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 1;

        else if (d5 == 2 && d1 <= 1 && d2 <= 1 && d3 <= 1 && d4 <= 1 && d6 <= 1)
            puntaje = 1;

        else if (d6 == 2 && d1 <= 1 && d2 <= 1 && d3 <= 1 && d4 <= 1 && d5 <= 1)
            puntaje = 1;

        // calcula si hubo dos pares
        if (d1 == 2 && (d2 == 2 || d3 == 2 || d4 == 2 || d5 == 2 || d6 == 2))
            puntaje = 2;

        else if (d2 == 2 && (d1 == 2 || d3 == 2 || d4 == 2 || d5 == 2 || d6 == 2))
            puntaje = 2;

        else if (d3 == 2 && (d1 == 2 || d2 == 2 || d4 == 2 || d5 == 2 || d6 == 2))
            puntaje = 2;

        else if (d4 == 2 && (d1 == 2 || d2 == 2 || d3 == 2 || d5 == 2 || d6 == 2))
            puntaje = 2;

        else if (d5 == 2 && (d1 == 2 || d2 == 2 || d3 == 2 || d4 == 2 || d6 == 2))
            puntaje = 2;

        else if (d6 == 2 && (d1 == 2 || d2 == 2 || d3 == 2 || d4 == 2 || d5 == 2))
            puntaje = 2;

        // calcula si hubo una tercia
        if (d1 == 3 && d2 <= 1 && d3 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 3;

        else if (d2 == 3 && d1 <= 1 && d3 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 3;

        else if (d3 == 3 && d1 <= 1 && d2 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 3;

        else if (d4 == 3 && d1 <= 1 && d2 <= 1 && d3 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 3;

        else if (d5 == 3 && d1 <= 1 && d2 <= 1 && d3 <= 1 && d4 <= 1 && d6 <= 1)
            puntaje = 3;

        else if (d6 == 3 && d1 <= 1 && d2 <= 1 && d3 <= 1 && d4 <= 1 && d5 <= 1)
            puntaje = 3;

        // calcula si hubo 1 tercia y 1 par
        if (d1 == 3 && (d2 == 2 || d3 == 2 || d4 == 2 || d5 == 2 || d6 == 2))
            puntaje = 4;

        else if (d2 == 3 && (d1 == 2 || d3 == 2 || d4 == 2 || d5 == 2 || d6 == 2))
            puntaje = 4;

        else if (d3 == 3 && (d1 == 2 || d2 == 2 || d4 == 2 || d5 == 2 || d6 == 2))
            puntaje = 4;

        else if (d4 == 3 && (d1 == 2 || d2 == 2 || d3 == 2 || d5 == 2 || d6 == 2))
            puntaje = 4;

        else if (d5 == 3 && (d1 == 2 || d2 == 2 || d3 == 2 || d4 == 2 || d6 == 2))
            puntaje = 4;

        else if (d6 == 3 && (d1 == 2 || d2 == 2 || d3 == 2 || d4 == 2 || d5 == 2))
            puntaje = 4;


        // calcula si hubo 4 iguales
        if (d1 == 4 && d2 <= 1 && d3 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 5;

        else if (d2 == 4 && d1 <= 1 && d3 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 5;

        else if (d3 == 4 && d1 <= 1 && d2 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 5;

        else if (d4 == 4 && d1 <= 1 && d2 <= 1 && d3 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 5;

        else if (d5 == 4 && d1 <= 1 && d2 <= 1 && d3 <= 1 && d4 <= 1 && d6 <= 1)
            puntaje = 5;

        else if (d6 == 4 && d1 <= 1 && d2 <= 1 && d3 <= 1 && d4 <= 1 && d5 <= 1)
            puntaje = 5;

    }

    return puntaje;
}

// aumenta la cantidad de veces que ha salido la cara "d"
void sumar_lados(char d) {
    // obten el valor de d y aumenta la variable correspondiente
    switch (d) {
        case '9':
            j9++;
            break;

        case '1':
            j10++;
            break;

        case 'a':
            ja++;
            break;

        case 'j':
            jj++;
            break;

        case 'q':
            jq++;
            break;

        case 'k':
            jk++;
            break;

        default:
            break;
    }
}

// resta la cantidad de veces que ha salido la cara "d"
void restar_lados(char d) {
    // obten el valor de d y resta la variable correspondiente
    switch (d) {
        case '9':
            j9--;
            break;

        case '1':
            j10--;
            break;

        case 'a':
            ja--;
            break;

        case 'j':
            jj--;
            break;

        case 'q':
            jq--;
            break;

        case 'k':
            jk--;
            break;

        default:
            break;
    }
}
