#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ncurses.h>

char ascii_dado() {
    return 'a' + (rand() % 6);
}

int get_input(char *arr) {
    char c;

    int i = 0;
    while ((c = getch()) != EOF && c != '\n' && i++ < 4 && c >= 'a' && c <= 'f')
        *arr++ = c;

    *arr = '\0';

    if (c != '\n' && c != EOF)
        while ((c = getch()) != EOF && c != '\n');

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
        }
        else
            k++;
    }

    return equal;
}

void splash_screen() {
    int row, col;
    getmaxyx(stdscr, row, col);

    char msg[] = "Mastermind";
    char msg2[] = "Programado por cristobal liendo";

    mvprintw(row/2, (col - strlen(msg))/2, msg);
    mvprintw(row/2 + 1, (col - strlen(msg2))/2, msg2);

    mvprintw(row - 1, 0, "Presiona cualquier tecla para iniciar...");

    getch();
}

int main() {
    initscr();
    nocbreak();

    splash_screen();
    refresh();

    clear();

    srand(time(0));

    char respuesta[2][5], user[5], hint[5];

    generate_answer(respuesta[0]);

    // print the window borders
    mvprintw(0, 20, "|------|------|");
    move(1,0);

    refresh();

    int won = 0, k, times;
    for (times = 0; times < 10 && !won; times++){
        k = 0;

        memset(hint, '\0', 5);
        strcpy(respuesta[1], respuesta[0]);

        mvprintw(times + 1, 0, "Intento: ");
        get_input(user);

        mvprintw(times + 1, 20, "| ");
        mvprintw(times + 1, 22, user);
        mvprintw(times + 1, 26, " | ");

        k = intersection(respuesta[1], user, hint, '!');

        if (k == 4)
            won = 1;

        insertion_sort(respuesta[1], 4);
        insertion_sort(user, 4);

        for (int j = 0; j < merge(respuesta[1], user, 4) && k < 4; j++, k++)
            hint[k] = '#';

        mvprintw(times + 1, 29, "%s", hint);
        mvprintw(times + 1, 33, " |");

        refresh();
    }

    if (!won)
        mvprintw(times + 1, 0, "\nPerdiste. La respuesta era: %s\n", respuesta[0]);
    else
        mvprintw(times + 1, 0, "\nGanaste!\n");

    getch();
    endwin();

    return 0;
}
