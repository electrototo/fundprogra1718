/*
 * autor: cristobal liendo i.
 * fecha: 1/11/17
 * descripcion: estrcuturas
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    struct datos_persona {
        char inicial;
        int edad;
        float nota;
    };

    struct datos_persona persona;

    persona.inicial = 'J';
    persona.edad = 20;
    persona.nota = 7.5;

    printf("La edad es %d\n", persona.edad);

    return 0;
}
