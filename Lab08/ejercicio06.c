/*
 * autor: cristobal liendo i.
 * fecha: 23/10/17
 * descripcion: pide 8 numeros y los imprime de forma inversa
*/

#include <stdio.h>

int main() {
    float arr[8];
    float num; 

    for (int i = 0; i < 8; i++) {
        printf("Ingresa el numero %d: ", i + 1);
        scanf("%f", &num);

        arr[i] = num;
    }

    printf("\nLos numeros en orden inverso son: \n\t");
    for (int i = 7; i >= 0; i--)
        printf("%.2f%s", arr[i], (i == 0) ? "\n" : ", ");

    return 0;
}
