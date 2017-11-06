/*
 * autor: cristobal liendo i
 * fehca: 06/11/17
 * descripcion: atrapar errores
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* archivo;
    char nombre[80] = "chivo_prueba.txt";
    char linea[81];

    archivo = fopen(nombre, "rt");

    if (archivo == NULL) {
        printf("No existe el archivo\n");
        exit(1);
    }

    fgets(linea, 80, archivo);
    puts(linea);
    fclose(archivo);

    return 0;
}
