/*
 *
 * descripcion: cubilete
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char dado();
int menu();
void swap(int *, int *);
void selection_sort(int *, int);
int comparar(int *, int);
void imprimir_dados(int *dados);

int main() {
    int op;
    srand(time(0));

    op = menu();

    int computadora[5];

    if (op == 1) {
        // Obten los primeros 5 tiros de la computadora
        for (int i = 0; i < 5; i++)
            computadora[i] = dado();

        selection_sort(computadora, 5);
        printf("Puntaje de la computadora: %d\n", comparar(computadora, 5));

        imprimir_dados(computadora);
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
    for (int i = 0; i < 5; i++) {
        printf("cara: %d\n", dados[i]);
    }
}
