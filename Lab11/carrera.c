/*
 * autor: cristobal liendo i
 * fecha: 13/11/17
 * descripcion: carrera de la tortuga y la liebre
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void change_pos(int *t, int *l) {
    int tr, lr;

    tr = (rand() % 10) + 1;
    lr = (rand() % 10) + 1;

    if (tr >= 1 && tr <= 5)
        *t += 3;
    else if(tr == 6 || tr == 7)
        *t -= 6;
    else
        *t += 1;

    if (lr == 3 || lr == 4)
        *l += 9;
    else if (lr == 5) {
        *l -= 12;
    }
    else if (lr >= 6 && lr <= 8)
        *l += 1;
    else if (lr == 9 || lr == 10) {
        *l -= 2;
    }

    if (*l <= 0)
        *l = 1;

    if (*t <= 0)
        *t = 1;

    if (*l > 70)
        *l = 70;
    if (*t > 70)
        *t = 70;
}

void print_tablero(int *t, int *l, int start) {
    int stop = 70;
    if (*t == *l && !start) {
        if (*l - 1 >= 1)
            *l--;
        else
            *l = 1;

        printf("OUCH!!!");
    }
    else if (!start){
        for (int i = 0; i < stop; i++) {
            if (*t == i + 1)
                printf("T");
            else if (*l == i + 1)
                printf("L");
            else
                printf(" ");
        }
    }

    if (start)
        printf("BANG!!!");

    printf("\n");

    for (int i = 0; i < 70; i++)
        printf("-");

    printf("\n");
}

int main() {
    srand(time(0));

    int tx = 0, lx = 0, i = 1, countdown = 3;

    while (tx < 70 && lx < 70) {
        system("clear");

        if (countdown == 0){
            print_tablero(&tx, &lx, i);

            if (i == 1) {
                i = 0;
            }

            change_pos(&tx, &lx);
        }
        else {
            printf("%d\n", countdown);

            for (int i = 0; i < 70; i++)
                printf("-");
            printf("\n");
            countdown--;
        }

        sleep(1);
    }

    if (tx >= lx)
        printf("\n\nLa tortuga ha ganado!\n");
    else
        printf("\n\nLa liebre ha ganado!\n");

    return 0;
}

