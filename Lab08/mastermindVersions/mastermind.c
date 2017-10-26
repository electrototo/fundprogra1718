/*
 * autor: cristobal liendo i.
 * fecha: 23/10/17
 * descripcion: juego de mastermind
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

    getchar();

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

int get_input(char *arr) {
    // regresa la cantidad de bytes que copio
    char c;

    int i = 0;
    // obtiene solo 4 letras y las almacena en arr
    while ((c = getchar()) != EOF && c != '\n' && i++ < 4 && c >= 'a' && c <= 'f')
        *arr++ = c;

    *arr = '\0';

    // clear buffer
    if (c != '\n' && c != EOF)
        while ((c = getchar()) != EOF && c != '\n');

    return i;
}

void generate_answer(char *buf, int *count) {
    char c;

    for (int i = 0; i < 4; i++) {
        c = ascii_dado();

        *buf++ = c;
        count[c - 'a']++;
    }

    *buf = '\0';
}

int check_in(char *buf, char letter) {
    for (int i = 0; i < 4; i++) {
        if (buf[i] == letter) {
            buf[i] = 'x';

            return -1;
        }
    }

    return 0;
}

int intersection(char *a, char *b, char *dest) {
    int j = 0, i = 0;

    while (i < 4) {
        if (a[i] == b[i]) {
            a[i] = 'x';
            dest[j++] = '!';
        }

        i++;
    }

    return j;
}

int main() {
    srand(time(0));

    char resultado[5], resultado_copy[5], intento[5];
    int cuenta[6], cuenta_copy[6];

    // limpia cuenta
    for (int i = 0; i < 6; i++)
        cuenta[i] = 0;

    generate_answer(resultado, cuenta);

    int intentos = 0, won = 0;

    // opcion escogida
    int op;

    // resultado actual
    int res;

    // caracteres que se van a imprimir
    char hint[5];
    int k = 0, index;

    do {
        op = menu();

        if (op == 2)
            instrucciones();

    } while (op != 1 && op != 3);

    if (op == 3)
        return 0;

    else {
        while (intentos < 10 && !won) {
            printf("\nIngresa intento: ");

            if(get_input(intento) == 4) {
                memset(hint, '\0', 5);

                for (int j = 0; j < 6; j++)
                    cuenta_copy[j] = cuenta[j];

                strcpy(resultado_copy, resultado);

                k = intersection(resultado_copy, intento, hint);

                for (int i = 0; i < 4; i++) {
                    index = intento[i] - 'a';

                    res = check_in(resultado_copy, intento[i]);

                    // obtiene los que estan pero en posiciones diferentes
                    if (res == -1 && cuenta_copy[index] > 0) {
                        hint[k++] = '#';
                        cuenta_copy[index]--;
                    }
                }

                printf("Hint: %s\n", hint);

                if (strcmp(intento, resultado) == 0)
                    won = 1;

                intentos++;
            }

            else
                printf("\nPor favor ingresa una combinacion de cuatro letras entre la a y la f.\n");
        }

        if (won)
            printf("\nFelicidades, ganaste\n");
        else
            printf("\nLo lamento, perdiste\n\nEl resultado era: %s\n", resultado);
    }
}
