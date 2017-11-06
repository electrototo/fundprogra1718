/*
 * autor: cristobal liendo i
 * fecha: 06/11/17
 * descripcion: combinacion de todo
*/

#include <stdio.h>

struct ficha {
    char nombre[50];
    int altura;
};

int main() {
    struct ficha a[5], b[5];
    
    FILE* archivo;
    int i;

    archivo = fopen("fichero.txt", "wb");

    for (i = 0; i < 5; i++) {
        printf("Ingresa nombre: ");
        gets(a[i].nombre);
        printf(" Ingresa altura: ");
        scanf("%d", &a[i].altura);
        getchar();
    }

    fwrite(a, sizeof(a), 1, archivo);
    fclose(archivo);

    archivo = fopen("fichero.txt", "rb");
    fread(b, sizeof(b), 1, archivo);
    for (i = 0; i < 5; i++)
        printf("Nombre: %s\nAltura: %d\n", b[i].nombre, b[i].altura);

    fclose(archivo);

    return 0;
}
