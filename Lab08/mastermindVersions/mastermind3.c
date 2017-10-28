#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_answer(char *buf) {
    for (int i = 0; i < 5; i++)
        *buf++ = (i < 4) ? 'a' + (rand() % 6) : '\0';
}

int intersection(char *a, char *b, char *dest, char letter) {
    int k = 0;
    for (int i = 0; i < 4; i++)
        if (a[i] == b[i] && a[i] != 'x')
            a[i] = b[i] = dest[k++] = 'x';

    return k;
}

void insertion_sort(char *a, int length) {
    int k, tmp, key;
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
        if (a[j] > b[k]) k++;
        else if (a[j] < b[k])  j++;
        else if (a[j] != 'x' && b[k] != 'x' && a[j] == b[k]) equal++, j++, k++;
        else j++, k++;
    }

    return equal;
}

int main() {
    srand(time(0));

    char respuesta[2][5], user[5], hint[5];
    generate_answer(respuesta[0]);

    int won = 0, k, r;

    printf("Respuesta: %s\n", respuesta[0]);
    for (int times = 0; times < 10 && !won; times++){
        k = 0;

        memset(hint, '\0', 5);
        strcpy(respuesta[1], respuesta[0]);

        printf("Ingresa respuesta: ");
        scanf("%s", user);
        
        if ((k = intersection(respuesta[1], user, hint, '!')) == 4) won = 1;

        insertion_sort(respuesta[1], 4);
        insertion_sort(user, 4);

        r = merge(respuesta[1], user, 4);
        for (int j = 0; j < r && k < 4; j++, k++) hint[k] = '#';
 
        printf("Hint: %s\n\n", hint);
    }

    if (!won)
        printf("Perdiste. La respuesta era: %s\n", respuesta[0]);
    else
        printf("Ganaste!\n");
}
