/*
 * Autor: Cristobal Liendo I.
 * Fecha: 25/09/17
 * Descripcion do...while
*/

#include <stdio.h>

void password(void);

int main() {
    password();
    return 0;
}

void password() {
    int clave_usuario, clave_secreta = 246;
    int oportunidades = 0;

    do {
        printf("Para ingresar al sistema, \n");
        printf("por favor ingresa la clave secreta: ");
        scanf("%d", &clave_usuario);
        
        oportunidades++;
    } while (oportunidades < 3 && clave_usuario != clave_secreta);

    if (clave_usuario != clave_secreta)
        printf("Tus oportunidades se agotaron.\n");
    else
        printf("Has accedido..\n");
}
