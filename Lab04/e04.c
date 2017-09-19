/*
 * Autor: Cristobal Liendo I.
 * Fecha: 18/09/17
 * Descripcion: Pide hora e imprime la hora un segundo despues
*/

#include <stdio.h>

int main() {
    int h, m, s;

    printf("Ingrese la hora (0 - 23): ");
    scanf("%d", &h);

    if (h > 23 || h < 0) {
        printf("Hora invalida\n");
        return -1;
    }

    printf("Ingrese los minutos (0 - 59): ");
    scanf("%d", &m);

    if (m > 59 || m < 0) {
        printf("Minutos invalidos\n");
        return -1;
    }

    printf("Ingrese los segundos (0 - 59): ");
    scanf("%d", &s);

    if (s > 59 || s < 0) {
        printf("Segundos invalidos\n");
        return -1;
    }

    s = (s + 1) % 60;

    if (s == 0) {
        m = (m + 1) % 60;

        if (m == 0)
            h = (h + 1) % 24;
    }

    printf("%02d:%02d:%02d\n", h, m, s);

    return 0;
}
