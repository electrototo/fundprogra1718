/*
 * autor: cristobal liendo i
 * fecha: 11/10/17
 * descripcion: serie de fibonacci
*/

// rutina ordinaria, importa stdio
#include <stdio.h>

int main() {
    // asignacion de variables para el ciclo principal que calcula
    // la serie de fibonacci
    unsigned long fib1 = 0, fib2 = 1, tmp = 0;
    int stop;

    // le pregunto al usuario cuantos numeros de fibonacci quiere
    // calcular
    printf("Cuantos numeros de fibonacci (0 - 94)? ");
    scanf("%d", &stop);

    // verifico que entre dentro del rango por temas de espacio del
    // tipo de varibale que estoy usando (unsigned long)
    if (stop < 0 || stop > 94) {
        printf("No esta dentro del rango.\n");
        return 1;
    }

    // ciclo principal que se encarga de calcular los numeros
    // stop es hasta cuantos numeros de fibonacci va a calcular
    for (int i = 0; i < stop; i++) {
        // imprimo fib1 que es el que va a tener el ultimo numero de
        // fibonacci que se necesita imprimir, porque realmente
        // fib2 es la "cabeza" de la serie.
        // la parte de (i == stop - 1) ? "\n" : ", " es un if else
        // compacto. simplemente estoy verificando si hay un numero
        // que sigue, si lo hay, imprime una coma, de lo contrario
        // una nueva linea
        printf("%lu%s", fib1, (i == stop - 1) ? "\n" : ", ");

        // tmp es una variable que uso para calcular el siguiente
        // numero.
        // hago que fib1 tome el valor de fib2, es decir, un numero antes de
        // la serie y hago que fib2 tome el nuevo valor de tmp, es decir, el
        // nuevo numero de la serie
        tmp = fib1 + fib2;
        fib1 = fib2;
        fib2 = tmp;
    }

    // termina el programa de manera exitosa
    return 0;
}
