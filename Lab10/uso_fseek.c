/*
 * autor: cristobal liendo i
 * fecha: 06/11/17
 * descripcion uso del fseek
*/

#include <stdio.h>

int main() {
    FILE* fp;
    long int longitud;

    fp = fopen("archivo.txt", "w+");

    fputs("Fundamentos de Comunicacion y Diseño", fp);

    fseek(fp, 0, SEEK_END);
    longitud = ftell(fp);
    printf("La longitud del arhivo es: %ld\n", longitud);

    fseek(fp, 11, SEEK_SET);
    fputs(" de programacion y laboratorio\n", fp);

    fseek(fp, 0, SEEK_END);
    longitud = ftell(fp);

    printf("La longitud del archivo es %ld\n", longitud);

    fclose(fp);

    return 0;
}
