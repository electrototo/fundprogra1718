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

} Cancion;

typedef struct {
    Cancion canciones[20];
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
    char b[4];


    printf("\n");
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

    printf("\n");

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

void delete_song(Biblioteca *bib, int id) {
    Cancion tmp = bib->canciones[id];

    // recalcula la duracion de la biblioteca
    bib->duracion -= tmp.duracion;

    // recalcula el promedio de la biblioteca

    if (bib->index - 1 != 0) {
        bib->promedio = bib->promedio * bib->index;
        bib->promedio -= tmp.duracion;
        bib->promedio /= bib->index - 1;
    }
    else { 
        bib->promedio = 0;
    }

    bib->index--;

    for (int i = id; i < 19; i++) {
        tmp = bib->canciones[i];
        bib->canciones[i] = bib->canciones[i + 1];
        bib->canciones[i + 1] = tmp;
    }

    int max = 0, index;
    // recalcula la cancion mas larga
    if (bib->cancion_mas_larga == id) {

        if (bib->index > 0) {
            for (int i = 0; i < bib->index; i++) {
                if (bib->canciones[i].duracion > max) {
                    max = bib->canciones[i].duracion;
                    index = i;
                }
            }
        }
        else
            index = -1;

        bib->cancion_mas_larga = index;
    }
}

int main() {
    FILE *bib_db;

    bib_db = fopen("biblioteca.dat", "rb");

    Biblioteca bib;

    Cancion c_agregar, tmp;

    if (bib_db == NULL) {
        printf("Creando una nueva base de datos\n");
        bib_db = fopen("biblioteca.dat", "wb");

        bib.index = 0;
        bib.id = 0;

        bib.cancion_mas_larga = -1;
        bib.duracion = 0;
        bib.promedio = 0;
    }
    else {
        fread(&bib, sizeof(bib), 1, bib_db);
        printf("%d canciones en la biblioteca\n", bib.index);
    }

    fclose(bib_db);

    int menu_choice, cancion_index;
    while ((menu_choice = menu()) != 7) {
        switch (menu_choice) {
            case 1:
                c_agregar = agregar_cancion();

                bib.duracion += c_agregar.duracion;
                bib.promedio = (bib.promedio + c_agregar.duracion) / (bib.index + 1);

                if (bib.cancion_mas_larga == -1)
                    bib.cancion_mas_larga = 0;
                else {
                    tmp = bib.canciones[bib.cancion_mas_larga];

                    if (c_agregar.duracion > tmp.duracion)
                        bib.cancion_mas_larga = bib.index;
                }

                bib.canciones[bib.index++] = c_agregar;

                bib_db = fopen("biblioteca.dat", "w");
                fwrite(&bib, sizeof(bib), 1, bib_db);
                fclose(bib_db);

                break;

            case 2:
                if (bib.index > 0) {
                    for (int i = 0; i < bib.index; i++) {
                        printf("\tNombre: %s", bib.canciones[i].nombre);
                        printf("\tArtista: %s", bib.canciones[i].artista);
                        printf("\tGenero: %s", bib.canciones[i].genero);
                        printf("\tDuracion: %d:%02d\n", bib.canciones[i].duracion / 60,
                            bib.canciones[i].duracion % 60);
                        printf("\tid: %d\n", i);
                        printf("\n");
                    }
                }
                else {
                    printf("\tNo se encontraron canciones en la biblioteca\n");
                }

                break;

            case 3:
                printf("\tIngresa el ID: ");
                scanf("%d", &cancion_index);
                getchar();

                delete_song(&bib, cancion_index);

                bib_db = fopen("biblioteca.dat", "w");
                fwrite(&bib, sizeof(bib), 1, bib_db);
                fclose(bib_db);

                break;

            case 4:
                printf("\tLa biblioteca dura %d minutos y %d segundos\n",
                       bib.duracion / 60, bib.duracion % 60);
                break;

            case 5:
                printf("\tEl promedio por cancion es de %d minutos y %d segundos\n",
                       bib.promedio / 60, bib.promedio % 60);
                break;

            case 6:
                cancion_index = bib.cancion_mas_larga;

                if (cancion_index != -1) {
                    printf("\tNombre: %s", bib.canciones[cancion_index].nombre);
                    printf("\tArtista: %s", bib.canciones[cancion_index].artista);
                    printf("\tGenero: %s", bib.canciones[cancion_index].genero);
                    printf("\tDuracion: %d:%02d\n", bib.canciones[cancion_index].duracion / 60,
                            bib.canciones[cancion_index].duracion % 60);
                    printf("\n");
                }
                else
                    printf("\tNo se encontraron canciones en la biblioteca\n");

                break;

            default:
                break;
        }

    }

    return 0;
}
