/*
 * Autor: cristobal liendo i.
 * Fecha: 09/19/17
 * Descripcion: funciones
*/
#include <stdio.h>
#include <math.h>

int print_menu();
int digit_sum(int);
int is_prime(int);
void print_table(int);

int main() {
    int c, num;

    do {
        printf("\nPrograma de funciones. Porfavor seleccione una opcion: \n");
        c = print_menu();

        if (c != 4 && c != -1) {
            printf("Ingrese un numero: ");
            scanf("%d", &num);
        }

        if (c == 1)
            print_table(num);

        else if (c == 2)
            printf("\nEl numero %d %ses primo\n", num, (is_prime(num)) ? "" : "no " );

        else if (c == 3)
            printf("\nLa suma de los digitos de %d es %d\n", num, digit_sum(num));

        else if (c == -1)
            printf("\nOpcion invalida.\n");

    } while (c != 4);

    return 0;
}

int print_menu() {
    int c;

    printf("[1] Imprimir tabla de multiplicaciones\n");
    printf("[2] Saber si un numero es primo o no\n");
    printf("[3] Obtener la suma de los digitos de un numero\n");
    printf("[4] Salir\n");

    printf("Entrada: ");
    scanf("%d", &c);

    if (c <= 0 || c > 4)
        c = -1;

    return c;
}

void print_table(int n) {
    printf("\nTabla del %d del 0 al 10:\n", n);

    for (int i = 0; i <= 10; i++)
        printf("%3d * %2d = %d\n", n, i, n*i);
}

int is_prime(int n) {
    if (n <= 1)
        return 0;

    else if (n == 2)
        return 1;

    else {
        char is_prime = 1;

        for (int i = 2; i <= sqrt(n) + 1; i++) {
            if (n % i == 0) {
                is_prime = 0;
                break;
            }
        }

        return is_prime;
    }
}

int digit_sum(int n) {
    int sum = 0;

    while (n / 10) {
        sum += n % 10;
        n /= 10;
    }

    sum += n;

    return sum;
}
