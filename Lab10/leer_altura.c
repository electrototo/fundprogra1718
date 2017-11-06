/*
 * autor: cristobal liendo i
 * fecha: 06/11/17
 * descripcion: lee el archivo de alturas 
*/

#include <stdio.h>

struct ficha {
    char nombre[50];
    int altura;
};

int main() {
    struct ficha b[5];
    
    FILE* archivo;
    int i;

    archivo = fopen("fichero.txt", "rb");
    fread(b, sizeof(b), 1, archivo);
    for (i = 0; i < 5; i++)
        printf("Nombre: %s\nAltura: %d\n", b[i].nombre, b[i].altura);

    fclose(archivo);

    return 0;
}
