/*
 * autor: cristobal liendo i.
 * fecha: 08/11/17
 * descripcion: reto del cuarto "maldito"
*/

#include <stdio.h>

int main() {
    int l, a, n;

    scanf("%d %d", &l, &a);
    scanf("%d", &n);

    int matriz[a][l];

    int x, y;

    for (int i = 0; i < a; i++)
        for (int j = 0; j < l; j++)
            matriz[i][j] = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        x--, y--;

        matriz[y][x] = 1;
    }

    int cuenta = 0;

    for (int y = a - 1; y >= 0; y--) {
        for (int x = 0; x < l; x++) {
            if (matriz[y][x] != 1) {
                if (y > 0 && x > 0) {
                    if (matriz[y - 1][x - 1] != 1 && matriz[y - 1][x] != 1 && matriz[y][x - 1] != 1) {
                        cuenta++;
                    }
                }
            }
        }
    }

    printf("%d\n", cuenta);


    return 0;
}
