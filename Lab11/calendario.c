/*
 * comentado por cristobal liendo
 * fecha: 14/11/17
*/

#include <stdio.h>
#include <string.h>

int main() {
    // crea la estructua para guardar los datos de una persona
    struct {
        char nombre [81];
        char apellido[81];
        char direccion [81];
        char tlfMovil[13];
        char email[51];
        int diaNac, mesNac, anyoNac;
    } ficha [100];
    // y crea un arreglo de 100 elementos de la estructura

    FILE* archivo;
    int ultimaFicha = -1;
    char linea[200];
    int opcion;
    int i;
    archivo = fopen("agenda.txt", "rt");

    if (archivo != NULL) {
        puts("Leyendo datos...");

        while (! feof(archivo)) {
            fgets(linea, 80, archivo);
            
            if (feof(archivo)) break;
            if (strlen(linea) > 0)
                linea[strlen(linea) -1] ='\0';

            strcpy(ficha[ultimaFicha+1].nombre, linea);

            fgets(linea, 80, archivo);

            if (feof(archivo)) break;

            if (strlen(linea) > 0)
                linea[strlen(linea) -1] ='\0';
            strcpy(ficha[ultimaFicha+1].apellido, linea);

            fgets(linea, 80, archivo);
            if (feof(archivo)) break;
            if (strlen(linea) > 0)
            linea[strlen(linea) -1] ='\0';
            strcpy(ficha[ultimaFicha+1].direccion, linea);

            fgets(linea, 12, archivo);
            if (feof(archivo)) break;
            if (strlen(linea) > 0)
                linea[strlen(linea) -1] ='\0';
            strcpy(ficha[ultimaFicha+1].tlfMovil, linea);

            fgets(linea, 50, archivo);
            if (feof(archivo)) break;
            if (strlen(linea) > 0)
                linea[strlen(linea) -1] ='\0';
            strcpy(ficha[ultimaFicha+1].email, linea);

            fgets(linea, 20, archivo);
            puts(linea);
            if (feof(archivo)) break;
            sscanf(linea, "%d %d %d", &ficha[ultimaFicha+1].diaNac,

            &ficha[ultimaFicha+1].mesNac,
            &ficha[ultimaFicha+1].anyoNac);

            ultimaFicha ++;
        }
        fclose(archivo);
    }

    printf("Leidos %d datos", ultimaFicha+1);

    do {
        puts("\n\n Agenda, version 0.01\n");
        puts("Elija una opcion");
        puts("1.- Nuevo dato");
        puts("2.- Ver datos existentes");
        puts("3.- Ver detalles de una persona");
        puts("0.- Terminar");

        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                puts("Añadiendo datos...");
                printf ("Introduce nombre: ");
                gets(ficha[ultimaFicha+1].nombre);
                printf("Introduce apellido: ");
                gets(ficha[ultimaFicha+1].apellido);

                printf ("Introduce direccion: ");
                gets(ficha[ultimaFicha+1].direccion);

                printf ("Introduce movil: ");
                gets(ficha[ultimaFicha+1].tlfMovil);

                printf ("Introduce correo electronico: ");
                gets(ficha[ultimaFicha+1].email);

                printf ("Introduce dia de nacimiento: ");
                gets (linea);
                sscanf(linea, "%d", &ficha[ultimaFicha+1].diaNac);

                printf ("Introduce mes de nacimiento: ");
                gets (linea);
                sscanf(linea, "%d", &ficha[ultimaFicha+1].mesNac);

                printf ("Introduce año de nacimiento: ");
                gets(linea);
                sscanf(linea, "%d", &ficha[ultimaFicha+1].anyoNac);

                ultimaFicha ++;
                break;

            case 2:
                puts ("Fichas existentes:");
                for (i=0; i<=ultimaFicha; i++)
                    puts(ficha[i].nombre);
                break;

            case 3:
                printf ("Nombre a buscar? ");
                gets (linea);

                for (i=0; i<=ultimaFicha; i++) {
                    if (strcmp (linea, ficha[i].nombre) == 0) {
                        puts (ficha[i].nombre);
                        puts (ficha[i].apellido);
                        puts (ficha[i].direccion);
                        puts (ficha[i].tlfMovil);
                        puts (ficha[i].email);
                        printf("%d %d %d\n", ficha[i].diaNac,
                        ficha[i].mesNac, ficha[i].anyoNac);
                    }
                }
                break;
        }

    } while (opcion != 0);

    archivo = fopen("agenda.txt", "wt");
    puts("Guardando datos...");

    for (i = 0; i <= ultimaFicha; i++)
    {
        fprintf (archivo, "%s\n", ficha[i].nombre);
        fprintf (archivo, "%s\n", ficha[i].apellido);
        fprintf (archivo, "%s\n", ficha[i].direccion);
        fprintf (archivo, "%s\n", ficha[i].tlfMovil);
        fprintf (archivo, "%s\n", ficha[i].email);
        fprintf (archivo, "%d %d %d\n",
        ficha[i].diaNac, ficha[i].mesNac, ficha[i].anyoNac);
    }

    fclose(archivo);

    printf("Terminado.");

    return 0;
}
