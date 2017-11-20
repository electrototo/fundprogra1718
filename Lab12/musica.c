/*
 * autor: cristobal liendo i
 * fecha: 19/11/17
 * descripcion: simulacion de una biblioteca de musica
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    char artista[50];
    char genero[50];
    // la duracion total se guarda en segundos
    int duracion;
    // para poder almacenarlo dentro de la biblioteca
    int id;

} Cancion;

typedef struct {
    int canciones[20];
    int index;

    int duracion;
    // el promedio por cancion tambien es en segundos
    int promedio;
    // guarda el index
    int cancion_mas_larga;
    // guarda el id actual de las cancioes
    int id;

} Biblioteca;

int average(Biblioteca bib, Cancion *canciones) {
    int duration = 0;

    for (int i = 0; i < bib.index; i++)
        duration += canciones[i].duracion;

    return duration / bib.index;
}

int menu() {
    int choice;

    printf("[1] Agregar una cancion nueva\n");
    printf("[2] Enlistar todas las canciones\n");
    printf("[3] Eliminar una cancion\n");
    printf("[4] Duracion total de la biblioteca\n");
    printf("[5] Promedio de duracion por cancion\n");
    printf("[6] Cancion mas larga de la biblioteca\n");
    printf("[7] Salir\n");

    do {
        printf("Opcion: ");
        scanf("%d", &choice);
        getchar();
    } while (choice < 1 || choice > 8);

    return choice;
}

Cancion agregar_cancion() {
    Cancion song;
    int m, s;

    printf("\tIngresa el titulo: ");
    fgets(song.nombre, 50, stdin);

    printf("\tIngresa el artista: ");
    fgets(song.artista, 50, stdin);

    printf("\tIngresa el genero: ");
    fgets(song.genero, 50, stdin);

    printf("\tIngresa la duracion [mm:ss]: ");
    scanf("%d:%d", &m, &s);
    getchar();

    song.duracion = (m * 60) + s;

    return song;
}

int main() {
    FILE *bib_db, *canciones_db;

    bib_db = fopen("biblioteca.dat", "rb");
    canciones_db = fopen("canciones.dat", "rb");

    Biblioteca bib;
    Cancion canciones[20];

    Cancion c_agregar, tmp;

    if (bib_db == NULL || canciones_db == NULL) {
        printf("Creando una nueva base de datos\n");
        bib_db = fopen("biblioteca.dat", "wb");
        canciones_db = fopen("canciones.dat", "wb");

        bib.index = 0;
        bib.id = 0;

        bib.cancion_mas_larga = -1;
        bib.duracion = 0;
        bib.promedio = 0;
    }
    else {
        fread(&bib, sizeof(bib), 1, bib_db);
        fread(&canciones, sizeof(canciones), 1, canciones_db);

        printf("%d canciones en la biblioteca\n", bib.index);
    }

    bib_db = fopen("biblioteca.dat", "wb");

    int menu_choice;
    while ((menu_choice = menu()) != 7) {
        switch (menu_choice) {
            case 1:
                c_agregar = agregar_cancion();

                bib.duracion += c_agregar.duracion;
                bib.promedio = (bib.promedio + c_agregar.duracion) / (bib.index + 1);

                if (bib.cancion_mas_larga == -1)
                    bib.cancion_mas_larga = 0;
                else {
                    tmp = canciones[bib.cancion_mas_larga];

                    if (c_agregar.duracion > tmp.duracion)
                        bib.cancion_mas_larga = bib.index;
                }

                c_agregar.id = bib.id++;

                canciones[bib.index++] = c_agregar;


                break;

            case 2:
                for (int i = 0; i < bib.index; i++) {
                    printf("\tNombre: %s", canciones[i].nombre);
                    printf("\tArtista: %s", canciones[i].artista);
                    printf("\tGenero: %s", canciones[i].genero);
                    printf("\tDuracion: %d:%02d\n", canciones[i].duracion / 60,
                           canciones[i].duracion % 60);
                    printf("\n");
                }

                break;

            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;

            default:
                break;
        }

    }

    printf("Escribiendo datos...\n");
    fwrite(&bib, sizeof(bib), 1, bib_db);
    fwrite(&canciones, sizeof(canciones), 1, canciones_db);

    fclose(bib_db);
    fclose(canciones_db);

    return 0;
}
