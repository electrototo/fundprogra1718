/*
 * Autor: cristobal liendo i.
 * Fecha: 09/10/17
 * Descripcion: funcion potencia
*/
#include <stdio.h>

int potencia(int , int);

int main () {
    int num1, num2;

    printf("Introduzca la base: ");
    scanf("%d", &num1);
    printf("Introduzca el exponente: ");
    scanf("%d", &num2);

    printf("%d elevado a %d vale %d\n", num1, num2, potencia(num1, num2));

    return 0;
}

int potencia(int a, int b) {
    int t = 1;

    for (int i = 0; i < b; i++)
        t *= a;

    return t;
}
