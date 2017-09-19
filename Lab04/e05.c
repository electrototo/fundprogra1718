/*
 * Autor: Cristobal Liendo I
 * Fecha: 18/09/17
 * Descripcion: Calcula el perimetro de tres tipos de triangulos diferentes
*/

#include <stdio.h>

int menu();

int main() {
    float a, b, c;
    int t = menu();

    while (t != 4) {
        switch (t) {
            case 1:
                printf("Ingrese la longitud del lado a: ");
                scanf("%f", &a);

                printf("Ingrese la longitud del lado b: ");
                scanf("%f", &b);

                printf("Ingrese la longitud del lado c: ");
                scanf("%f", &c);

                printf("\nPerimetro: %.2f\n", a + b + c);
                break;

            case 2:
                printf("Ingrese la longitud de un lado: ");
                scanf("%f", &a);

                printf("\nPerimetro: %.2f\n", a * 3);
                break;

            case 3:
                printf("Ingrese la longitud de los lados iguales: ");
                scanf("%f", &a);
                printf("Ingrese la longitud del lado desigual: ");
                scanf("%f", &b);

                printf("\nPerimetro: %.2f\n", (a * 2) + b);
                break;

            default:
                printf("Opcion incorrecta\n");
                break;
        }

        t = menu();
    }

    return 0;
}

int menu() {
    int t;

    printf("\n1: Escaleno\n");
    printf("2: Equilatero\n");
    printf("3: Isoceles\n");
    printf("4: Salir\n");
    printf("Que tipo de triangulo? ");
    scanf("%d", &t);

    if (t < 0 || t > 4)
        t = -1;

    return t;
}
