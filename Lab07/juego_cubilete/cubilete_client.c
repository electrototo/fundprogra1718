/*
 * autores: elias cohen y cristobal liendo
 * fecha: 16/10/17
 * descripcion: cubilete
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
 
#define SERVER "127.0.0.1"
#define PORT 8888   //The port on which to send data

char dado();
int menu();
int menu_juego();
void selection_sort(int *, int);
void swap(int *, int *);
int comparar(int *, int);
void imprimir_dados(int *dados);
int preguntar_respuesta(int numero);
int calcular_puntaje(int *baraja);

void send_data(char *msg);

// Client method
void set_client();
struct sockaddr_in si_me, si_other;

int s, i, slen = sizeof(si_other), recv_len;

#define BUFLEN 100
char buffer[BUFLEN];

void dados_to_char(int *, char *);
void char_to_dados(char *asciidados, int *dados);

int main() {
    srand(time(0));

    set_client();

    int op;

    char username[100];
    char remote_username[100];

    // los dados actuales del jugador y la computadora
    int computadora[5], jugador[5];

    // vaiables que controlan los turnos del jugador y la computadora
    int jugador1_tira= 1;
    int jugador2_tira = 1;

    // variables que controlan los puntajes del jugador y la computadora
    int puntaje_computadora = 0;
    int puntaje_jugador = 0;

    char jugador_dados_ascii[6];

    printf("Ingresa tu nombre de usuario: ");
    scanf("%s", username);

    send_data("0");
    send_data(username);

    printf("Esperando a que el segundo jugador se una...\n");

    memset(buffer, '\0', BUFLEN);
    recvfrom(s, buffer, BUFLEN, 0, (struct sockaddr *) &si_other, &slen);

    if (buffer[0] != '0') {
        printf("Invalid data.\n");
        return 1;
    }

    memset(buffer, '\0', BUFLEN);
    recvfrom(s, buffer, BUFLEN, 0, (struct sockaddr *) &si_other, &slen);

    strcpy(remote_username, buffer);
    printf("\nEl usuario [%s] se ha unido\n\n", remote_username);

    op = menu();

    if (op == 1) {
        for (int i = 0; i < 5; i++) {
            if (jugador2_tira) {
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

            // manda los dados al otro jugador
            dados_to_char(jugador, jugador_dados_ascii);
            send_data(jugador_dados_ascii);

            // Obten los primeros 5 tiros de la computadora
            printf("Esperando a que [%s] tire sus dados\n", remote_username);
            recvfrom(s, buffer, BUFLEN, 0, (struct sockaddr *) &si_other, &slen);
            char_to_dados(buffer, computadora);
            memset(buffer, '\0', BUFLEN);

            puntaje_computadora = calcular_puntaje(computadora);
            
            // Imprime los dados y puntajes del jugador y la computadora
            printf("Tus dados:\n");
            imprimir_dados(jugador);
            
            printf("Dados de [%s]:\n", remote_username);
            imprimir_dados(computadora);

            printf("Puntaje de la ronda:\n");
            printf("\tPuntaje de [%s]: %d\n", username, puntaje_jugador);
            printf("\tPuntaje de [%s]: %d\n", remote_username, puntaje_computadora);

            // pregunta si el jugador quiere tirar o no
            if (i != 4)
                jugador2_tira = !menu_juego();
        }

        if (puntaje_jugador > puntaje_computadora)
            printf("%s es un ganador, %s es un perdedor\n", username, remote_username);
        else if (puntaje_jugador < puntaje_computadora)
            printf("%s es un ganador, %s es un perdedor\n", remote_username, username);
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

void dados_to_char(int *dados, char *asciidados) {
    for (int i = 0; i < 5; i++)
        *asciidados++ = '0' + *dados++;

    *asciidados = '\0';
}

void char_to_dados(char *asciidados, int *dados) {
    do {
        *dados++ = *asciidados++ - '0';
    } while (*asciidados);
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

void set_client() {
    s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    memset((char *) &si_other, 0, sizeof(si_other));

    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);

    inet_aton(SERVER, &si_other.sin_addr);
}

void send_data(char *msg) {
    sendto(s, msg, strlen(msg), 0, (struct sockaddr *) &si_other, slen);
}
