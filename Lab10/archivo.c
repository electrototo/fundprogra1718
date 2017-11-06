/*
 * autor: cristobal liendo i
 * fecha: 06/11/17
 * descripcion: manipulacion de archivos
*/

#include <stdio.h>

int main() {
    FILE* archivo;

    archivo = fopen("archivo_prueba.txt", "wt");
    fputs("Esto es una linea\n", archivo);
    fputs("Eso es otra", archivo);
    fputs(" y esto es continuacion de la anterior\n", archivo);
    fclose(archivo);

    return 0;
}
