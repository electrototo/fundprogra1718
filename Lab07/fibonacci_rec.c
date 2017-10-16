/*
 * autor: cristobal liendo i
 * fecha: 16/10/17
 * descripcion: fibonacci recursivo
*/
#include <stdio.h>

unsigned long fibonacci(unsigned long);

int main() {
    int s;
    printf("Cuantos numeros de fibonacci? ");
    scanf("%d", &s);

    for (int i = 0; i < s; i++)
        printf("%lu%s", fibonacci(i), (i == s - 1) ? "\n" : ", ");

    return 0;
}

unsigned long fibonacci(unsigned long n) {
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}
