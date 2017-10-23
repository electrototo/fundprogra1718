/*
 * autor: cristobal liendo i
 * fecha: 23/10/17
 * descripcion: pide 4 numeros, los almacena en
 *              un arreglo e imprime la medi
*/

#include <stdio.h>

int main() {
    float nums[4];
    float num, sum;

    for (int i = 0; i < 4; i++) {
        printf("Ingresa el numero %d: ", i + 1);
        scanf("%f", &num);

        nums[i] = num;
        sum += num;
    }

    printf("\nLa media es: %.2f y los numeros son:\n\t", sum / 4);

    for (int i = 0; i < 4; i++)
        printf("%.2f%s", nums[i], (i == 3) ? "\n" : ", ");

    return 0;
}
