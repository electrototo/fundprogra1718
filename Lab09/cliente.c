/*
 * autor: cristobal liendo i
 * fecha: 01/11/17
 * descripcion: estructuras y clientes
*/

#include <stdio.h>
#include <string.h>

#define MAX_CLIENTS 10

struct cliente {
    char nombres[100];
    char apellidos[100];
    char genero[20];
    char zip_code[20];
    int edad;
};

int menu() {
    int op;

    printf("\n");
    printf("[1] Agregar cliente\n");
    printf("[2] Listar clientes\n");
    printf("[3] Buscar cliente\n");
    printf("[4] Salir\n");

    do {
        printf("Ingresa una opcion: ");
        scanf("%d", &op);
        printf("\n");
        getchar();
    } while (op < 1 || op > 4);

    return op;
}

struct cliente registrar_cliente() {
    struct cliente tmp;

    printf("\tNombres: ");
    gets(tmp.nombres);

    printf("\tApellidos: ");
    gets(tmp.apellidos);

    printf("\tEdad: ");
    scanf("%d", &tmp.edad);
    getchar();

    printf("\tGenero: ");
    gets(tmp.genero);

    printf("\tCodigo postal: ");
    gets(tmp.zip_code);

    return tmp;
}

void imprimir_detalle(struct cliente data) {
    printf("\tNombre(s): %s\n", data.nombres);
    printf("\tApellido: %s\n", data.apellidos);
    printf("\tEdad: %d\n", data.edad);
    printf("\tGenero: %s\n", data.genero);
    printf("\tCodigo postal: %s\n", data.zip_code);
}

int main() {
    struct cliente clientes[MAX_CLIENTS];
    int op, c_index = 0, i;

    char buscar_nombre[100];

    do {
        op = menu();

        switch (op) {
            case 1:
                if (c_index < MAX_CLIENTS) {
                    clientes[c_index++] = registrar_cliente();
                }
                else
                    printf("\tYa no se puede agregar mas clientes\n");

                break;

            case 2:

                if (c_index > 0) {
                    printf("Lista de clientes:\n");

                    for (int i = 0; i < c_index; i++) {
                        printf("\tNombre(s): %s\n", clientes[i].nombres);
                        printf("\tApellidos: %s\n", clientes[i].apellidos);

                        if (i < c_index - 1)
                            printf("\n");
                    }
                }
                else
                    printf("\tNo hay clientes registrados\n");

                break;

            case 3:
                printf("Introduce el nombre a buscar: ");
                gets(buscar_nombre);

                for (i = 0; i < c_index; i++) {
                    if (strcmp(buscar_nombre, clientes[i].nombres) == 0) {
                        imprimir_detalle(clientes[i]);
                        i = MAX_CLIENTS + 1;
                    }
                }

                if (i == c_index)
                    printf("\tNo se encontro ningun cliente\n");

                break;

            default:
                break;
        }

    } while(op != 4);

    return 0;
}
