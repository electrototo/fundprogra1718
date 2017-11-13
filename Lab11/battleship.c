/*
 * autor: cristobal liendo i
 * fecha: 10/11/17
 * descripcion: juego de battleship
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// crea la esttructura que va a tener el jugador y la
// computadora.
// aqui se guardan las posiciones de los barcos junto 
// con los respectivos puntajes
struct jugador {
    char tablero[5][5];
    char tiros[5][5];
    int puntaje;

};

// guardo "struct jugador" comoo "jugador"
typedef struct jugador jugador;

// crea una estructura para almacenar las coordenadas
// de las posiciones estilo plano cartesiano para poder
// guardarlas en un arreglo a futuro y evitar que la
// computadora tire mas de una vez en el mismo lugar
struct posicion {
    int x;
    int y;
};

// guardo "struct posicion" unicamente como "posicion"
typedef struct posicion posicion;

// estructura conttrol que va a usar la computadora para
// evitar tirar en la misma posicioon mas de una vez
struct control_computadora {
    int index;
    posicion posible[25];
};

// funcion que imprime el tablero a partir de un arreglo
// bidimensional
void print_tablero(char tablero[5][5]) {
    // recorre el tablero desde el ultimo elemento hasta
    // el primero para poder imprimirlo de una manera mas
    // "humana"
    for (int i = 5; i >= 0; i--) {

        for (int j = 0; j < 6; j++) {
            // imprime el caracter que se esta almacenando
            // en la posicion x, y
            if (j < 5 && i > 0)
                printf("%c ", tablero[i - 1][j]);
            // si es que se encuentra en el extremo del tablero,
            // imprime el numero de hilera en la que se encuentra
            else if (j == 5 && i > 0)
                printf("|%d\n", i);
            // si se encuentra al final del tablero, imprime el
            // separador para imprimir los numeros de columnas
            else if (i == 0 && j < 6)
                printf("-%s", (j == 5) ? "\n" : "-");
        }

    }
    // imprime los numeros de columna actual
    for (int i = 0; i < 5; i++)
        printf("%c%s", 'A' + i, (i == 4) ? "\n" : " ");
}

// funcion auxiliar que sirve para convertir una letra mayuscula a
// minuscula
char to_lowercase(char letter) {
    // si la letra es minuscula, no hay que hacer ningun cambio
    if (letter >= 'a' && letter <= 'z') {
        return letter;
    }
    // si la letra es mayuscula, regresa el valor ascii para la
    // lettra correspondiente en minuscula
    else if(letter >= 'A' && letter <= 'Z')
        return letter + ('a' - 'A');
    // si no es letra, marca error
    else
        return 0;
}

// funcion auxiliar que convierte un caracter a numero
char catoi(char letter) {
    return (letter >= '1' && letter <= '5') ? letter - '0' : -1;
}

// funcion auxiliar que convierte una coordenada como "a1"
// en coordenadas del plano cartesiano, "x" y "y"
int getxy(char *coord, int *x, int *y) {
    char c;
    int py;

    // convierte la primera parte de la coordenada en
    // minuscula
    c = to_lowercase(coord[0]);
    // y obten el valor numerico de la segunda parte
    py = catoi(coord[1]);

    // si hubo algun error, regresa un valor 0
    if (!c || py == -1 || c > 'e')
        return 0;
    // de lo contrario, guarda la coordenada en las variables
    // "x" y "y"
    else {
        *x = c - 'a';
        *y = py - 1;

        return 1;
    }
}

// funcion que pregunta la orientacion del barco
int barco_pos(int n_barco) {
    int p;

    // repite hasta que el usuario haya ingresado una opcion
    // valida
    do {
        printf("Como deseas posicionar el barco %d?\n", n_barco);
        printf("[1] Vertical\n");
        printf("[2] Horizontal\n");
        printf("Opcion: ");
        scanf("%d", &p);
        printf("\n");
    } while (p != 1 && p != 2);

    return p;
}

// funcion auxiliar para verificar si el barco se encuentra
// dentro del tablero o si no hay ningun barco previamente
// posicionado en el rango que se esta especificando
int check_position(char tablero[5][5], int x, int y, int length, int orientation) {
    // orientation: 1 si es vertical, 2 si es horizontal
    int good = 1;

    if (orientation == 1) {
        // checa si el barco se encuentra dentro del tablero
        if ((y < 2 && length == 3) || (y < 1 && length == 2))
            good = 0;

        // checa que no haya algun barco dentro del rango
        for (int i = y; i > y - length; i--) {
            if (tablero[i][x] == '|' || tablero[i][x] == '=') {
                good = 0;
            }
        }
    }
    else {
        // checa si el barco se encuentra dentro del tablero
        if ((x > 2 && length == 3) || (x > 3 && length == 2))
            good = 0;

        // checa que no haya algun barco dentro del rango
        for (int i = x; i < x + length; i++) {
            if (tablero[y][i] == '|' || tablero[y][i] == '=') {
                good = 0;
            }
        }
    }

    return good;
}

// funcion que recorre todos los valores de un arreglo una unidad
// a la derecha.
// sirve para poder evitar que la computadora tire mas de una vez en el mismo lugar
void recorrer(struct control_computadora *c, int from) {
    posicion tmp;

    // recorre todo el arreglo desde "from" hasta el final una
    // unidad a la derecha
    c->index--;
    for (int i = from; i < 24; i++) {
        tmp = c->posible[i];
        c->posible[i] = c->posible[i + 1];
        c->posible[i + 1] = tmp;
    }
}

int main() {
    // imprime las instrucciones del juego
    printf("Instrucciones:\n");
    printf("El objetivo del juego es hundir todos los barcos enemigos.\n");
    printf("Al principio tendras que posicionar todos los barcos\n");
    printf("dentro de la cuadricula.");
    printf("\n\nTienes un barco de 3 unidades de longitud y otros dos barcos de\n");
    printf("dos de 2 unidades. Para poder ingresar las coordenadas\n");
    printf("tienes que poner la hilera (de la letra a hasta la e) y la\n");
    printf("columna (del 1 al 5) como el siguiente formato: a1 o A1.\n\n");
    printf("Se imprimen dos pantallas, la primera son tus barcos y la segunda\n");
    printf("muestra las posiciones en las que has tirado.\n\n");
    printf("Una x significa que le atinastte al barco enemigo, o que el enemigo\n");
    printf("le atino a un barco tuyo, mientras que una O significa que no le atinaste.\n\n");
    printf("El primero en hundir todos los barcos gana.\n\nBuena suerte.\n");
    srand(time(0));

    // establece las variables que se van a utilizar
    jugador jugador1, computadora;

    struct control_computadora c_tiros;
    jugador1.puntaje = 0, computadora.puntaje = 0;

    c_tiros.index = 0;

    // limpia los tableros de cualquier basura que se encuentre dentro
    // de ellos
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            jugador1.tablero[i][j] = ' ';
            jugador1.tiros[i][j] = ' ';

            // control de la computadora
            computadora.tablero[i][j] = ' ';
            c_tiros.posible[c_tiros.index].x = j;
            c_tiros.posible[c_tiros.index++].y = i;
        }
    }

    char coordenadas[2], placeholder;
    int x, y, orientacion, validas = 1, length = 3;

    // posiciona de forma aleatoria los barcos de la computadora
    for (int i = 0; i < 3; i++) {
        // escoge una orientacion al azar
        orientacion = (rand() % 2) + 1;
        length = (i == 0) ? 3 : 2;

        // dependiendo de la orientacion es como se va a imprimir
        // el barco
        if (orientacion == 1)
            placeholder = '|';
        else
            placeholder = '=';

        // encuentra una posicion aleatoria que no interfiera con
        // los otros barcos
        do {
            if (orientacion == 1) {
                x = rand() % 5;
                
                if (length == 3)
                    y = rand() % 3;
                else
                    y = rand() % 4;
            }
            else {
                if (length == 3)
                    x = rand() % 3;
                else
                    x = rand() % 4;

                y = rand() % 5;
            }
        } while(!check_position(computadora.tablero, x, y, length, orientacion));

        // posiciona los barcos en la posicion correspondiente
        if (orientacion == 1) {
            for (int j = 0; j < length; j++)
                computadora.tablero[y--][x] = placeholder;
        }
        else {
            for (int j = 0; j < length; j++)
                computadora.tablero[y][x++] = placeholder;
        }
    }

    // imprime el tablero del jugador
    printf("\nTablero del juego:\n");
    print_tablero(jugador1.tablero);

    // Posiciona los barcos del jugador
    for (int i = 0; i < 3; i++) {
        printf("\n");
        orientacion = barco_pos(i + 1);

        length = (i == 0) ? 3 : 2;

        if (orientacion == 1)
            placeholder = '|';
        else
            placeholder = '=';

        // repite hasta que se ingresen coordenadas correctas
        do {
            validas = 1;

            printf("Ingresa las coordenadas: ");
            scanf("%s", coordenadas);

            // verifica que las coordenadas sean correctas
            if (getxy(coordenadas, &x, &y)) {
                // verifica que no haya ningun barco en el camino
                // del otro barco
                if (check_position(jugador1.tablero, x, y, length, orientacion)) {
                    if (orientacion == 1) {
                        for (int j = 0; j < length; j++)
                            jugador1.tablero[y--][x] = placeholder;
                    }
                    else {
                        for (int j = 0; j < length; j++)
                            jugador1.tablero[y][x++] = placeholder;
                    }
                }
                else
                    validas = 0;
            }
            else
                validas = 0;

            // si hay algun error en la validacion, notifica al usuario
            if (!validas)
                printf("\tCoordenadas no validas\n\n");

        } while (!validas);

        // despues de cada posicionamiento del barco, imprime los barcos actuales
        printf("\nTus barcos:\n");
        print_tablero(jugador1.tablero);
    }

    printf("\nEl juego ha inciado\n");
    int c_tiro = 0;
    // se va a ejecutar hasta que alguno de los dos haya ganado
    while (jugador1.puntaje < 7 && computadora.puntaje < 7) {
        // se vuelve a preguntar las coordenadas hasta que estas esten correctas
        do {
            // el juego ya empezo, pregunta las coordenadas al jugador
            printf("Ingresa las coordenadas: ");
            scanf("%s", coordenadas);

            validas = 1;

            // es la misma verificacion que la linea 292
            if (getxy(coordenadas, &x, &y)) {
                // verifica que no haya tirado en la misma posicion
                if (jugador1.tiros[y][x] != 'x' && jugador1.tiros[y][x] != 'O') {
                    // si le atino a un barco enemigo, marcalo en el mapa y
                    // aumenta su punttaje
                    if (computadora.tablero[y][x] == '|' || computadora.tablero[y][x] == '=') {
                        jugador1.tiros[y][x] = 'x';
                        jugador1.puntaje++;
                    }
                    else
                        jugador1.tiros[y][x] = 'O';
                }
                else {
                    printf("\tYa habias tirado en ese lugar, escoge una nueva coordenada\n");
                    validas = 0;
                }
            }
            else {
                printf("\tCoordenadas no validas.\n");
                validas = 0;
            }
        } while(!validas);


        // escoge una posicion al azar de todas las coordenadas que previamente
        // no se hayan escogido
        c_tiro = rand() % c_tiros.index;
        x = c_tiros.posible[c_tiro].x;
        y = c_tiros.posible[c_tiro].y;

        // si le atina al barco del jugador, marcalo en el mapa del jugador
        // y aumenta el puntaje de la computadora
        if (jugador1.tablero[y][x] == '|' || jugador1.tablero[y][x] == '=') {
            jugador1.tablero[y][x] = 'x';
            computadora.puntaje++;
        }
        // de lo contrario solo marca donde tiraron con una O
        else {
            jugador1.tablero[y][x] = 'O';
        }

        recorrer(&c_tiros, c_tiro);

        // imprimir tableros
        printf("\nTus tiros:\n");
        print_tablero(jugador1.tiros);

        printf("\nTus barcos:\n");
        print_tablero(jugador1.tablero);
        printf("\n");
    }

    // imprime los mensajes, dependiendo del ganador
    if (jugador1.puntaje == 7)
        printf("\nFelcidades, derrotaste a la flota enemiga\n");
    else
        printf("\nPerdiste, todos tus barcos se encuentran en el fondo del mar\n");

    return 0;
}
