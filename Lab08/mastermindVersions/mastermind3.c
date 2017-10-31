/* autor: cristobal liendo i. fecha: 30/10/17. descripcion: mastermind */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int intersection(char *a, char *b, char *dest, char letter) {
    int k = 0;
    for (int i = 0; i < 4; i++) {if (a[i] == b[i] && a[i] != 'x') a[i] = b[i] = dest[k++] = 'x';} return k;
}
void insertion_sort(char *a, int length) {
    for (int i = 1, k, tmp, key; i < length; i++) {
        key = a[i]; k = i - 1;
        while (key < a[k] && k >= 0) {tmp = a[k + 1]; a[k + 1] = a[k]; a[k--] = tmp;}
    }
}
int merge(char *a, char *b, int length) {
    for (int equal = 0, j = 0, k = 0; k < length && j < length;){
        if (a[j] > b[k]) k++;
        else if (a[j] < b[k])  j++;
        else if (a[j] != 'x' && b[k] != 'x' && a[j] == b[k]) equal++, j++, k++;
        else j++, k++;
        if (k >= length || j >= length) return equal;
    }
}
int main() {
    srand(time(0));
    char respuesta[2][5], user[5], hint[5];
    for (int i = 0; i < 5; i++) respuesta[0][i] = (i < 4) ? 'a' + (rand() % 6) : '\0';
    int won = 0, k, r;
    printf("Respuesta: %s\n", respuesta[0]);
    for (int times = 0, k = 0; times < 10 && !won; times++, k = 0){
        memset(hint, '\0', 5); strcpy(respuesta[1], respuesta[0]);
        printf("Ingresa respuesta: "), scanf("%s", user);
        if ((k = intersection(respuesta[1], user, hint, '!')) == 4) won = 1;
        insertion_sort(respuesta[1], 4), insertion_sort(user, 4);
        for (int j = 0; j < merge(respuesta[1], user, 4) && k < 4; j++, k++) hint[k] = '#';
        printf("Hint: %s\n\n", hint);
    }
    if (!won) {printf("Perdiste. La respuesta era: %s\n", respuesta[0]);} else printf("Ganaste!\n");
}
