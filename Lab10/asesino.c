/*
 * autor: cristobal liendo i.
 * fecha: 08/11/17
 * descripcion: reto del cuarto "maldito"
*/

#include <stdio.h>

struct posiciones {
    int x;
    int y;
};

struct cama {
    int x1;
    int y1;

    int x2;
    int y2;
};

int main() {
    int l, a, n;

    scanf("%d %d", &l, &a);
    scanf("%d", &n);

    struct posiciones alacran[n];
    int matriz[l][a];

    int x, y;

    for (int i = 0; i < l; i++)
        for (int j = 0; j < a; j++)
            matriz[i][j] = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &alacran[i].x, &alacran[i].y);
        matriz[alacran[i].y - 1][alacran[i].x - 1] = 1;
    }

    int cuenta = 0;

    for (int y = l - 1; y >= 0; y--) {
        for (int x = 0; x < a; x++) {
            if (matriz[y][x] != 1) {
                if (y > 0 && x > 0) {
                    if (matriz[y - 1][x - 1] != 1 && matriz[y - 1][x] != 1 && matriz[y][x - 1] != 1) {
                        //printf("(%d, %d), ", x, y);
                        cuenta++;
                    }
                }
            }
        }

        //printf("\n");
    }

    printf("%d\n", cuenta);


    return 0;
}
