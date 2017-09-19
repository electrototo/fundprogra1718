/*
 * Autor: Cristobal Liendo I.
 * Fecha: 11/09/17
 * Pide al usuario una letra e imprime si es vocal o consonante
*/

#include <stdio.h>

int is_letter(char s);
int is_consonant(char s);

int main() {
    char l;
    printf("Ingrese una letra: ");
    scanf("%c", &l);

    if (is_letter(l)) {
        if (is_consonant(l))
            printf("Es consonante\n");
        else
            printf("Es vocal\n");
    }
    else
        printf("No es letra\n");

    return 0;
}

int is_letter(char s) {
    return (s >= 'a' && s <= 'z' || s >= 'A' && s <= 'Z');
}

int is_consonant(char s) {
    return !(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U');
}
