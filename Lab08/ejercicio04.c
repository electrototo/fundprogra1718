/*
 * autor: cristobal liendo i.
 * fecha: 23/10/17
 * descripcion: pide nombres
*/

#include <stdio.h>
#include <string.h>

int main() {
    char n1[40], n2[40], n3[40], n4[40], n5[40];
    char n6[40];

    int found = 0;

    printf("Ingresa el primer nombre: ");
    gets(n1);

    printf("Ingresa el segundo nombre: ");
    gets(n2);

    printf("Ingresa el tercer nombre: ");
    gets(n3);

    printf("Ingresa el cuarto nombre: ");
    gets(n4);

    printf("Ingresa el quinto nombre: ");
    gets(n5);

    do {
        printf("Ingresa el nombre a buscar: ");
        gets(n6);

        if (strcmp(n1, n6) == 0) {
            printf("\n\tEl nombre %s esta ubicado en el primer nombre.\n\n", n6);
            found = 1;
        }

        if (strcmp(n2, n6) == 0) {
            printf("\n\tEl nombre %s esta ubicado en el segundo nombre.\n\n", n6);
            found = 1;
        }

        if (strcmp(n3, n6) == 0) {
            printf("\n\tEl nombre %s esta ubicado en el tercero nombre.\n\n", n6);
            found = 1;
        }

        if (strcmp(n4, n6) == 0) {
            printf("\n\tEl nombre %s esta ubicado en el cuarto nombre.\n\n", n6);
            found = 1;
        }

        if (strcmp(n5, n6) == 0) {
            printf("\n\tEl nombre %s esta ubicado en el quinto nombre.\n\n", n6);
            found = 1;
        }

        if (!found && strcmp(n6, "fin"))
            printf("\n\tNo se encontro el nombre especificado\n\n");

        found = 0;

    } while (strcmp(n6, "fin") != 0);
}
