/*
 * Autor: Cristobal Liendo I.
 * Fecha: 18/09/17
 * Descripcion: Imprime una piramide de letras
*/

// Incluir la libreria stdio para poder acceder a funciones basicas
#include <stdio.h>

int main() {
    // Declarar la variable stop para que posteriormente se le pueda asignar el valor
    // que el usuario haya ingresado
    char stop;
    printf("Ingresa una letra mayuscula: ");
    scanf("%c", &stop);

    // Definiciones
    // row: posicion actual de la hilera
    // column: posicion actual de la columna
    // maxrow: cantidad total de hileras que va a haber en la piramide

    int row, column, maxrow;

    // La maxima cantidad de hileras va a ser determinada por el doble de letras
    // que hay entre la A y la letra ingresada por el usuario
    maxrow = ((stop - 'A') * 2) + 1;

    // La cantidad maxima de espacios (es decir, la que va a haber en el principio
    // y el final) va a ser igual a la cantidad de letras que hay entre la leytra
    // ingresada y la letra A
    int whitespaces = (stop - 'A');

    // Variable control para determinar cuanto se le resta a los espacios por
    // hilera y aumentar el valor ascii de la letra inicial por hilera
    int step = -1;

    // La letra con la que se va a iniciar la piramide
    int start = 65;

    // Definicion de la letra actual en la que se encuentra la columna (now)
    // y una variable control para determinar si la letra actual va de forma
    // descente o ascendente 
    int now, sum;

    // Si suma es igual a 0, entonces la letra actual va de forma descendente
    // de lo contrario, va de forma ascendente
    sum = 0;

    // Loop que aumenta la hilera (posicion y)
    for (row = 0; row < maxrow; row++) {
        // Loop que aumenta la columna (posicion x)
        // Este loop es interesante porque va a recorrer desde la posicion
        // column = 0 hasta que sea menor a la cantidad de letras y espacios
        // que va a haber en esta hilera
        // por eso el truco de maxrow - whitespaces
        for (column = 0; column < maxrow - whitespaces; column++) {
            // Si la cantidad de whitespaces es mayor que el valor actual de column
            // entonces imprime un espacio.
            // Se encaraga de imprimir los espacios necesarios por hilera
            if (whitespaces > column)
                printf(" ");

            // En el caso que column sea mayor a whitespaces entonces:
            else {
                // Checa si suma es verdadera, en el caso de serlo entonces
                // aumenta el valor de la letra actual (now) de uno en uno
                // Si es falso entonces la letra actual va ir disminuyendo desde
                // la letra que inicia la hilera (start) de uno en uno.
                // column - whitespaces es la posicion actual sin contar los
                // espacios en blanco
                now = (sum) ? now + 1: start - (column - whitespaces);

                // Si la letra actual es igual al volor numerico de 'A' (65),
                // entonces significa que now se encuentra en medio de la
                // piramide, por lo que debe de ir en forma ascendente a partir
                // de este momento (por ello sum = 1)
                if (now == 'A')
                    sum = 1;

                // Imprime el caracter actual (now) en la posicion x, y (column, row)
                printf("%c", now);
            }
        }

        // Despues de cada hilera, imprime un salto de linea para empezar la
        // siguiente linea
        printf("\n");

        // Ve disminuyendo o aumentando la cantidad de espacios que debe ir en
        // cada hilera
        whitespaces += step;

        // Ve aumentando o disminuyendo el valor numerico de la letra con la que
        // la hilera va a iniciar
        start -= step;

        // Si la variable whitespaces se encuentra en cero, entonces significa que
        // nos encontramos a la mitad de la piramide, por lo que los roles van
        // a invertirse: se va a aumentar la cantidad de espacios que hay por hilera
        // y se va a disminuir (hasta acabar en 65) la cantidad numerica de la
        // letra con la que se va a iniciar la hilera
        if (whitespaces == 0) {
            step = -step;
        }

        // Reinicia la variable num a 0 para que se pueda efectuar el control
        // que se lleva en la linea 36
        sum = 0;
    }

    // El programa es exitoso, asi que regresa un valor de 0
    return 0;
}
