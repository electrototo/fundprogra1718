/*
 * autor: cristobal liendo i.
 * fecha: 23/10/17
 * descripcion: juego de mastermind
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char ascii_dado();
int menu();
void instrucciones();

int main() {
    char resultado[5];

    int i = 0;

    srand(time(0));

    // genera el resultado aleatorio
    for (i = 0; i < 4; i++)
        resultado[i] = ascii_dado();

    resultado[i] = '\0';

    // debug
    printf("Resultado: %s\n", resultado);

    // opcion escogida
    int op;

    do {
        op = menu();

        if (op == 2)
            instrucciones();

    } while (op != 1 && op != 3);

    if (op == 3)
        return 0;

    else {

    }
}

char ascii_dado() {
    return 'a' + (rand() % 6);
}

int menu() {
    int op;

    printf("MASTERMIND\n");
    printf("[1] Iniciar\n");
    printf("[2] Instrucciones\n");
    printf("[3] Salir\n");

    do {
        printf("Opcion: ");
        scanf("%d", &op);
    } while (op < 1 || op > 3);

    return op;
}

void instrucciones() {
    printf("\nLa computadora ha seleccionado una combinacion de 4 letras entre la a y la f\n");
    printf("y debes adivinar la combinacion en 10 intentos o menos.\n");
    printf("\n");
    printf("Para intentar adivinar debes introducir una combinacion de las 6 letras\n");
    printf("previamente mencionadas.\n\n");
    printf("Por ejemplo: aabf.\n\n");
    printf("El simbolo ! significa que acertaste una letra en la posicion correcta,\n");
    printf("mientras que el simbolo # significa que acertaste el valor de una letra\n");
    printf("pero no su posicion.\n\n");
}
