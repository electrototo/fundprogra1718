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

    int x, y, area;

    area = (l - 1) * (a - 1);

    for (int i = 0; i < a; i++)
        for (int j = 0; j < l; j++)
            matriz[i][j] = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        x--, y--;

        // se encuentra dentro del area efectiva
        if (x >= 1 && y >= 1)
            area--;

        matriz[y][x] = 1;

        if (x < l - 1 && matriz[y][x + 1] != 1 && matriz[y][x + 1] != 2) {
            matriz[y][x + 1] = 2;
            
            if(x >= 1 && y >= 1)
                area--;
        }

        if (y < a - 1 && x >= 1 && matriz[y + 1][x] != 2 && matriz[y + 1][x] != 1) {
            matriz[y + 1][x] = 2;
            area--;
        }

        if (y <= a - 2 && matriz[y + 1][x + 1] != 1 && matriz[y + 1][x + 1] != 2) {
            matriz[y + 1][x + 1] = 2;
            //printf("en: (%d, %d)\n", x, y);
            area--;
        }
    }

    for (int i = a - 1; i >= 0; i--){
        for (int j = 0; j < l; j++) {
            printf("%d", matriz[i][j]);
        }

        printf("\n");
    }

    int cuenta = 0;
    printf("%d\n", area);


    return 0;
}
