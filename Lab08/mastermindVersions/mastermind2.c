#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char ascii_dado() {
    return 'a' + (rand() % 6);
}

int get_input(char *arr) {
    char c;

    int i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i++ < 4 && c >= 'a' && c <= 'f')
        *arr++ = c;

    *arr = '\0';

    if (c != '\n' && c != EOF)
        while ((c = getchar()) != EOF && c != '\n');

    return i;
}

void generate_answer(char *buf) {
    for (int i = 0; i < 4; i++)
        *buf++ = ascii_dado();

    *buf = '\0';
}

int intersection(char *a, char *b, char *dest, char letter) {
    int k = 0;

    for (int i = 0; i < 4; i++)
        if (a[i] == b[i] && a[i] != 'x') {
            a[i] = 'x';
            b[i] = 'x';

            dest[k++] = letter;
        }

    return k;
}

void insertion_sort(char *a, int length) {
    int key, k, tmp;
    for (int i = 1; i < length; i++) {
        key = a[i];
        k = i - 1;
        while (key < a[k] && k >= 0) {
            tmp = a[k + 1];
            a[k + 1] = a[k];
            a[k] = tmp;

            k--;
        }
    }
}

int merge(char *a, char *b, int length) {
    int equal = 0, j = 0, k = 0;

    while (k < length && j < length){
        if (a[j] > b[k])
            k++;
        else if (a[j] < b[k])
            j++;
        else if (a[j] != 'x' && b[k] != 'x') {
            equal++;
            k++;
            j++;
        }
        else {
            k++;
            j++;
        }
    }

    return equal;
}

int main() {
    srand(time(0));

    char respuesta[2][5], user[5], hint[5];

    generate_answer(respuesta[0]);

    printf("MASTERMIND\n\n");
    printf("Instrucciones del juego:\n");
    printf("El objetivo del juego es adivinar la combinacion correcta de letras.\n");
    printf("Para ello tienes que escribir una combinacion de 4 letras entre la a y la f,\n");
    printf("despues de cada tiro te aparece una pista.\n\nLa pista consiste en el signo de ");
    printf("exclamacion (!), significando que tienes una\nletra correcta en la posicion ");
    printf("correcta.\n\nMientras que el simbolo de gato (#) significa que tienes una letra\n");
    printf("correcta pero en la posicion incorrecta.\n");
    printf("\nEn total tienes 10 tiros.\nBuena suerte.\n\n");


    int won = 0, k, returned, times = 0;
    while (times < 10 && !won){
        k = 0;

        memset(hint, '\0', 5);
        strcpy(respuesta[1], respuesta[0]);

        printf("Ingresa respuesta: ");
        returned = get_input(user);

        if (returned == 4) {
            k = intersection(respuesta[1], user, hint, '!');

            if (k == 4)
                won = 1;

            insertion_sort(respuesta[1], 4);
            insertion_sort(user, 4);

            for (int j = 0; j < merge(respuesta[1], user, 4) && k < 4; j++, k++)
                hint[k] = '#';

            printf("Hint: %s\n\n", hint);

            times++;
        }

        else
            printf("\tIngresa una combinacion de 4 letras entre la a y la f\n\n");
    }

    if (!won)
        printf("Perdiste. La respuesta era: %s\n", respuesta[0]);
    else
        printf("Ganaste!\n");
}
