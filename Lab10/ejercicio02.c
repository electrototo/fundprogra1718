/*
 * autor: cristobal liendo i
 * fecha: 06/11/17
 * descripcion: guarda una persona en un archivo
*/

#include <stdio.h>

typedef struct Persona Persona;
struct Persona {
    char nombre[50];
    int edad;
    char ciudad[100];
};

int main() {
    FILE *archivo;
    char nombre_archivo[50] = "gente.dat";

    archivo = fopen(nombre_archivo, "rb");

    Persona personas[10];

    int i;
    
    if (archivo == NULL) {
        archivo = fopen(nombre_archivo, "wb");

        for (int i = 0; i < 10; i++) {
            printf("Ingresa el nombre de la persona: ");
            gets(personas[i].nombre);

            printf("Ingresa la edad de la persona: ");
            scanf("%d", &personas[i].edad);
            getchar();

            printf("Ingresa la ciudad de residencia: ");
            gets(personas[i].ciudad);

            printf("\n");
        }

        fwrite(personas, sizeof(personas), 1, archivo);

    }
    else {
        fread(personas, sizeof(personas), 1, archivo);

        printf("Que persona quieres consultar [1 - 10]? ");
        scanf("%d", &i);

        i -= 1;

        printf("\tNombre: %s\n", personas[i].nombre);
        printf("\tEdad: %d\n", personas[i].edad);
        printf("\tCiudad de residencia: %s\n\n", personas[i].ciudad);
    }

    fclose(archivo);

    return 0;
}
