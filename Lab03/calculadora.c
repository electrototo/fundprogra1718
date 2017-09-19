/*
 * Autor: Cristobal Liendo I.
 * Fecha: 13/09/17
 * Basica calculadora
*/

#include <stdio.h>

int menu();
float get_num(int);

int main() {
    int op = menu();

    float a, b;

    while (op != 5) {
        switch (op) {
            case 1:
                a = get_num(1);
                b = get_num(2);
                printf("%.2f + %.2f = %.2f\n\n", a, b, a + b);
                break;
            case 2:
                a = get_num(1);
                b = get_num(2);
                printf("%.2f - %.2f = %.2f\n\n", a, b, a - b);
                break;
            case 3:
                a = get_num(1);
                b = get_num(2);
                printf("%.2f * %.2f = %.2f\n\n", a, b, a * b);
                break;
            case 4:
                a = get_num(1);
                b = get_num(2);
                if (b != 0)
                    printf("%.2f / %.2f = %.2f\n\n", a, b, a / b);
                else
                    printf("Numero invalido, division entre cero.\n\n");

                break;
            default:
                printf("La opcion %d no es reconocida.\n\n", op);
                break;
        }

        op = menu();
    }

    return 0;
}

int menu() {
    int op;

    printf("*-------------------*\n");
    printf("|1: Suma            |\n");
    printf("|2: Resta           |\n");
    printf("|3: Multiplicacion  |\n");
    printf("|4: Division        |\n");
    printf("|5: Salir           |\n");
    printf("*-------------------*\n");
    printf("Selecciona una opcion: ");

    if(scanf("%d", &op) != 1){
        op = 0;
    }

    return op;
}

float get_num(int a) {
    if (a == 1)
        printf("Ingrese el primer numero: ");
    else
        printf("Ingrese el segundo numero: ");

    float f;
    scanf("%f", &f);

    return f;
}
