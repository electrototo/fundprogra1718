/*
 * autor: cristobal liendo i
 * fecha: 06/11/17
 * descripcion abrir una fotografia
*/

#include <stdio.h>
#include <string.h>

int main() {
    char nombre[90] = "lena.bmp";

    FILE *archivo;
    int ancho, alto;
    char marca[2];

    printf("Comprobador de imagenes BMP\n");
    archivo = fopen(nombre, "rb");

    if (archivo == NULL)
        printf("El archivo no fue encontrado\n");
    else {
        fread(marca, 1, 2, archivo);

        if (strcmp(marca, "BM") == 0) {
            printf("Marca del archivo: %s\n", marca);

            fseek(archivo, 18, SEEK_SET);
            fread(&ancho, 1, 4, archivo);
            printf("Ancho: %d\n", ancho);
            fread(&alto, 1, 4, archivo);
            printf("Alto: %d\n", alto);
            fclose(archivo);
        }
        else
            printf("No parece un archivo BMP\n");
    }

    return 0;
}
