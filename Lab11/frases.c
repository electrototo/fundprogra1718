/*
 * autor: cristobal liendo i
 * fecha: 15/11/17
 * descripcion: guarda frases en un archivo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("registro.txt", "a+");

    char buffer[250];
    int i = 1;

    while (i) {
        fgets(buffer, 250, stdin);
        
        if (strcmp(buffer, "fin\n") != 0 && strcmp(buffer, "FIN\n") != 0) {
            fprintf(file, "%s", buffer);
        }
        else
            i = 0;
    }

    fclose(file);

    return 0;
}

