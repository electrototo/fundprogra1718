/*
 * Autor: Cristobal Liendo I.
 * Fecha: 18/09/17
 * Pide tres numeros y los imprime de mayor a menor
 * en el caso que sean iguales, imprimir en la misma linea
*/

#include <stdio.h>

int main() {
    int a, b, c;

    printf("Ingrese tres numeros, separados por un espacio: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a == b && a == c)
        printf("%d %d %d\n", a, b, c);

    else if(a == b && a > c)
        printf("%d %d\n%d\n", a, b, c);

    else if(a == b && a < c)
        printf("%d\n%d %d\n", c, a, b);

    else if(a == c && a > b)
        printf("%d %d\n%d\n", a, c, b);

    else if(a == c && a < b)
        printf("%d\n%d %d\n", b, a, c);

    else if(b == c && a > b)
        printf("%d\n%d %d\n", a, b, c);

    else if(b == c && a < b)
        printf("%d %d\n%d\n", b, c, a);
 
    else {
        if (a > b && a > c && b > c)
            printf("%d\n%d\n%d\n", a, b, c);

        else if (a > b && a > c && b < c)
            printf("%d\n%d\n%d\n", a, c, b);

        else if (b > a && b > c && a > c)
            printf("%d\n%d\n%d\n", b, a, c);

        else if (b > a && b > c && a < c)
            printf("%d\n%d\n%d\n", b, c, a);

        else if (c > a && c > b && a > b)
            printf("%d\n%d\n%d\n", c, a, b);

        else if (c > a && c > b && a < b)
            printf("%d\n%d\n%d\n", c, b, a);
    }

    return 0;
}
