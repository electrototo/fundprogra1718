/*
 * autor: cristobal liendo i
 * fecha: 30/10/17
 * descripcion: guardar nombres
*/

#include <stdio.h>
#include <string.h>

void insertion_sort(char nombres[10][100]) {
    for (int i = 1; i < 10; i++) {
        char key[100];
        char temp[100];

        strcpy(key, nombres[i]);

        int j = i - 1;

        while (strcmp(key, nombres[j]) < 0 && j >= 0) {
            strcpy(temp, nombres[j]);
            strcpy(nombres[j], nombres[j + 1]);
            strcpy(nombres[j + 1], temp);

            j--;
        }
    }
}

int main() {
    char nombres[10][100];

    for (int i = 0; i < 10; i++) {
        printf("Ingresa el %d nombre: ", i + 1);
        gets(nombres[i]);
    }

    insertion_sort(nombres);

    printf("\nNombres ordenados:\n");
    for (int i = 0; i < 10; i++)
        printf("%s\n", nombres[i]);

    return 0;
}
