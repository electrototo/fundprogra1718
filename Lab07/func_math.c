/*
 * autor: cristobal liendo i.
 * fecha: 16/10/17
 * descripcion: math.h
*/

#include <stdio.h>
#include <math.h>

void get_root();
void solve_equation();
float degree_radians(float);
void sin_cos_table();

int menu();

int main() {
    int option;

    do {
        option = menu();

        switch (option) {
            case 1:
                get_root();
                break;

            case 2:
                solve_equation();
                break;

            case 3:
                    sin_cos_table();
                break;

            case -1:
                printf("\nOpcion no reconocida\n");
                break;

            default:
                break;
        }

    } while (option != -1 && option != 4);

    return 0;
}

int menu() {
    printf("\nSelecciona una opcion: \n");
    printf("[1] Obtener una raiz de grado n\n");
    printf("[2] Resolver una ecuacion de segundo grado\n");
    printf("[3] Mostrar los senos y cosenos de 30, 45, 60 y 90 grados\n");
    printf("[4] Salir\n");
    printf("Opcion: ");

    int n;
    scanf("%d", &n);

    printf("\n");

    if (n < 0 || n > 4)
        return -1;

    else
        return n;
}

void get_root() {
    int n, power;

    printf("Introduce el numero: ");
    scanf("%d", &n);
    printf("Introduce la raiz: ");
    scanf("%d", &power);
    
    printf("\nLa raiz %d de %d es %.3f\n", power, n, pow(n, (1./power)));
}

void solve_equation() {
    float a, b, c;
    float raiz, x1, x2;

    printf("Introduce a: ");
    scanf("%f", &a);

    printf("Introduce b: ");
    scanf("%f", &b);

    printf("Introduce c: ");
    scanf("%f", &c);

    raiz = pow(b, 2) - (4 * a * c);

    if (raiz < 0){
        printf("El resultado no entra dentro de los reales\n");
        return;
    }
    else {
        x1 = (-b + raiz) / (2. * a);
        x2 = (-b - raiz) / (2. * a);

        printf("x1: %.3f, x2: %.3f\n", x1, x2);
    }
}

float degree_radians(float degree) {
    return (degree * (3.1415926535 / 180));
}

void sin_cos_table() {
    int angles[4] = {30, 45, 60, 90};
    float sind, cosd;

    printf("| x° | sin(x) | cos(x) |\n");
    for (int i = 0; i < 4; i++) {
        sind = sin(degree_radians(angles[i]));
        cosd = cos(degree_radians(angles[i]));

        printf("| %2d |  %1.2f  |  %1.2f  |\n", angles[i], sind, fabs(cosd));
    }
}
