/*
 * autores: elias cohen y cristobal liendo.
 * fecha: 17/10/17
 * descripcion: cubilete SIN arreglos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu();
int menu_jugador();
char dado();
void imprimir_dados(char d1, char d2, char d3, char d4, char d5);
int calcular_puntaje(int d1, int d2, int d3, int d4, int d5, int d6);
int preguntar_respuesta(int);

void sumar_lados(char);
void restar_lados(char);

static int j9, j10, jj, jq, jk, ja;
static int c9, c10, cj, cq, ck, ca;

static int jd1, jd2, jd3, jd4, jd5;
static int cd1, cd2, cd3, cd4, cd5;

int main() {
    srand(time(0));

    int option = menu();

    int numero_jugada = 0;

    int tira_jugador = 1, tira_computadora = 1;
    char computadora_actual, jugador_actual;

    int puntaje_computadora, puntaje_jugador;

    int multiplicador = 5;

    char respuesta;

    if (option) {
        while (numero_jugada < 5) {
            if (tira_computadora) {
                c9 = c10 = cj = cq = ck = ca = 0;

                for (int i = 0; i < 5; i++) {
                    computadora_actual = dado();

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

            puntaje_computadora = calcular_puntaje(c9, c10, cj, cq, ck, ca);

            if (puntaje_computadora >= 3)
                tira_computadora = 0;

            if (tira_jugador) {
                if (numero_jugada == 0) {
                    j9 = j10 = jj = jq = jk = ja = 0;

                    for (int i = 0; i < 5; i++) {
                        jugador_actual = dado();

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

            printf("Tus dados:\n");
            imprimir_dados(jd1, jd2, jd3, jd4, jd5);

            printf("Dados de la computadora:\n");
            imprimir_dados(cd1, cd2, cd3, cd4, cd5);

            puntaje_jugador = calcular_puntaje(j9, j10, jj, jq, jk, ja);

            printf("Puntaje de la ronda:\n");
            printf("\tPuntaje del jugador: %d\n", puntaje_jugador);
            printf("\tPuntaje de la computadora: %d\n", puntaje_computadora);
            printf("\n");
            
            printf("\n");

            if (numero_jugada != 4)
                tira_jugador = menu_jugador();

            numero_jugada++;
        }

        if (puntaje_computadora > puntaje_jugador)
            printf("\nPerdiste\n");

        else if (puntaje_jugador > puntaje_computadora)
            printf("\n¡¡GANASTE!!!\n");

        else
            printf("\nEmpate\n");

    }

    return 0;
}

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

int menu() {
    printf("[1] Iniciar juego\n");
    printf("[2] Salir\n");

    int n;
    
    do {
        printf("Opcion: ");
        scanf("%d", &n);

    } while (n < 0 || n > 2);

    printf("\n");

    return n;
}

void imprimir_dados(char d1, char d2, char d3, char d4, char d5) {
    printf("----- ----- ----- ----- -----\n");
    printf("| %c | | %c | | %c | | %c | | %c |\n", d1, d2, d3, d4, d5);
    printf("----- ----- ----- ----- -----\n");
    printf("  0     1     2     3     4\n");
    printf("\n");
}

int menu_jugador() {
    printf("[1] Tirar dados\n");
    printf("[2] No tirar\n");

    int n;

    do {
        printf("Opcion: ");
        scanf("%d", &n);
    } while (n < 1 || n > 2);

    printf("\n");

    return n;
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

int calcular_puntaje(int d1, int d2, int d3, int d4, int d5, int d6) {
    int puntaje = 0;

    if (d1 == 5 || d2 == 5 || d3 == 5 || d4 == 5 || d5 == 5 || d6 == 5)
        puntaje = 6;

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

        // calcula si hubo dos pares (cuantos ifs? 6C2)
        if (d1 == 2 && d2 == 2 && d3 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 2;

        else if (d1 == 2 && d3 == 2 && d2 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 2;

        else if (d1 == 2 && d4 == 2 && d2 <= 1 && d3 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 2;

        else if (d1 == 2 && d5 == 2 && d2 <= 1 && d3 <= 1 && d4 <= 1 && d6 <= 1)
            puntaje = 2;

        else if (d1 == 2 && d6 == 2 && d2 <= 1 && d3 <= 1 && d4 <= 1 && d5 <= 1)
            puntaje = 2;

        else if (d2 == 2 && d3 == 2 && d1 <= 1 && d4 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 2;

        else if (d2 == 2 && d4 == 2 && d1 <= 1 && d3 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 2;

        else if (d2 == 2 && d5 == 2 && d1 <= 1 && d3 <= 1 && d4 <= 1 && d6 <= 1)
            puntaje = 2;

        else if (d2 == 2 && d6 == 2 && d1 <= 1 && d3 <= 1 && d4 <= 1 && d5 <= 1)
            puntaje = 2;

        else if (d3 == 2 && d4 == 2 && d1 <= 1 && d2 <= 1 && d5 <= 1 && d6 <= 1)
            puntaje = 2;

        else if (d3 == 2 && d5 == 2 && d1 <= 1 && d2 <= 1 && d4 <= 1 && d6 <= 1)
            puntaje = 2;

        else if (d3 == 2 && d6 == 2 && d1 <= 1 && d2 <= 1 && d4 <= 1 && d5 <= 1)
            puntaje = 2;

        else if (d4 == 2 && d5 == 2 && d1 <= 1 && d2 <= 1 && d3 <= 1 && d6 <= 1)
            puntaje = 2;

        else if (d4 == 2 && d6 == 2 && d1 <= 1 && d2 <= 1 && d3 <= 1 && d5 <= 1)
            puntaje = 2;

        else if (d5 == 2 && d6 == 2 && d1 <= 1 && d2 <= 1 && d3 <= 1 && d4 <= 1)
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

void sumar_lados(char d) {
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

void restar_lados(char d) {
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
