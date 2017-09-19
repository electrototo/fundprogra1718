/*
 * Autor: Cristobal Liendo I.
 * Fecha: 18/09/17
 * Pide numero del 1 al 7 y dice que dia de la semana es
*/

#include <stdio.h>

int main() {
    int dia;
    printf("Ingrese un numero entre el 1 y el 7: ");
    scanf("%d", &dia);

    switch (dia) {
        case 1:
            printf("Es lunes\n");
            break;
        case 2:
            printf("Es martes\n");
            break;
        case 3:
            printf("Es miercoles\n");
            break;
        case 4:
            printf("Es jueves\n");
            break;
        case 5:
            printf("Es viernes\n");
            break;
        case 6:
            printf("Es sabado\n");
            break;
        case 7:
            printf("Es domingo\n");
            break;
        default:
            printf("El numero ingresado no esta dentro del rango\n");
            break;
    }

    return 0;
}
