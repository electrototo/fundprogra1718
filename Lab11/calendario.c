/*
 * comentado por cristobal liendo
 * fecha: 14/11/17
*/

#include <stdio.h>
#include <string.h>

int main() {
    // crea la estructua para guardar los datos de una persona
    struct {
        char nombre [81];
        char apellido[81];
        char direccion [81];
        char tlfMovil[13];
        char email[51];
        int diaNac, mesNac, anyoNac;
    } ficha [100];
    // y crea un arreglo de 100 elementos de la estructura

    // define la variable "archivo" de tipo archivo
    FILE* archivo;

    // variables que llevan el control de las personas
    int ultimaFicha = -1;
    int opcion;
    int i;

    // buffer en el que se guardan las lineas de texto
    char linea[200];

    // se abre el archivo de agenda en modo lectura
    archivo = fopen("agenda.txt", "rt");

    // verifica si el archivo existe
    if (archivo != NULL) {
        puts("Leyendo datos...");

        // en caso que si exista carga los datos en variables
        while (! feof(archivo)) {
            // guarda los primero 80 caracteres del archivo en la variable "linea"
            fgets(linea, 80, archivo);

            // si el archivo no contiene nada, entonces sal del ciclo
            if (feof(archivo)) 
                break;

            // obten el tamaño de la linea para quitar el caracter nulo
            if (strlen(linea) > 0)
                linea[strlen(linea) -1] ='\0';

            // copia la linea del archivo al elemento "ultimaFicha + 1"
            // del arreglo "ficha" y guardalo en "nombre"
            strcpy(ficha[ultimaFicha+1].nombre, linea);

            // obten los siguientes 80 caracteres del archivo
            fgets(linea, 80, archivo);

            // si se llego al final del archivo, rompe el ciclo
            if (feof(archivo))
                break;

            // si el tamaño de la linea es mayor a 0, quita el caracter nulo
            if (strlen(linea) > 0)
                linea[strlen(linea) -1] ='\0';

            // copia la linea del archivo al elemento "ultimaFicha + 1"
            // del arreglo "ficha" y guardalo en "apellido"
            strcpy(ficha[ultimaFicha+1].apellido, linea);

            // obten los siguientes 80 caracteres del archivo
            fgets(linea, 80, archivo);

            // si se llego al final del archivo, rompe el ciclo
            if (feof(archivo)) break;

            // si el tamaño de la linea es mayor a 0, quita el caracter nulo
            if (strlen(linea) > 0)
                linea[strlen(linea) -1] ='\0';

            // copia la linea del archivo al elemento "ultimaFicha + 1"
            // del arreglo "ficha" y guardalo en "direccion"
            strcpy(ficha[ultimaFicha+1].direccion, linea);

            // obten los siguientes 12 caracteres del archivo
            fgets(linea, 12, archivo);

            // si se llego al final del archivo, rompe el ciclo
            if (feof(archivo)) break;

            // si el tamaño de la linea es mayor a 0, quita el caracter nulo
            if (strlen(linea) > 0)
                linea[strlen(linea) -1] ='\0';

            // copia la linea del archivo al elemento "ultimaFicha + 1"
            // del arreglo "ficha" y guardalo en "tlfMovil"
            strcpy(ficha[ultimaFicha+1].tlfMovil, linea);

            // obten los siguientes 50 caracteres del archivo
            fgets(linea, 50, archivo);

            // si se llego al final del archivo, rompe el ciclo
            if (feof(archivo)) break;

            // si el tamaño de la linea es mayor a 0, quita el caracter nulo
            if (strlen(linea) > 0)
                linea[strlen(linea) -1] ='\0';

            // copia la linea del archivo al elemento "ultimaFicha + 1"
            // del arreglo "ficha" y guardalo en "email"
            strcpy(ficha[ultimaFicha+1].email, linea);

            // obten los siguientes 20 caracteres del archivo
            fgets(linea, 20, archivo);
            
            // imprime en pantalla la fecha de nacimiento
            puts(linea);

            // si se llego al final del archivo, rompe el ciclo
            if (feof(archivo)) break;

            // guarda la linea leida y guardarlas en diferentes variables dentro
            // del arreglo de estructuras, en la posicion "ultimaFicha + 1"
            // y dale formato de entero
            sscanf(linea, "%d %d %d", &ficha[ultimaFicha+1].diaNac,
                   &ficha[ultimaFicha+1].mesNac, &ficha[ultimaFicha+1].anyoNac);

            // aumenta ultimaFicha de uno en uno para poder tener control de la
            // posicion en la que se guarda dentro del arreglo de estrcuturas
            ultimaFicha ++;
        }
        // cierra el archivo
        fclose(archivo);
    }

    // imprime "Ledidos %d datos" donde %d es la cantidad de fichas que 
    // se obtuvieron
    printf("Leidos %d datos", ultimaFicha+1);

    // repite mientras el usuario no haya decidio terminar el programa
    do {
        // imprime en pantalla el menu
        puts("\n\n Agenda, version 0.01\n");
        puts("Elija una opcion");
        puts("1.- Nuevo dato");
        puts("2.- Ver datos existentes");
        puts("3.- Ver detalles de una persona");
        puts("0.- Terminar");

        // obten la eleccion del usuario y limpia el buffer
        scanf("%d", &opcion);
        getchar();

        // checa que opcion es la que escogio el usuario
        switch (opcion) {
            // en el caso que haya escogido la opcion para agregar un nuevo dato...
            case 1:
                // ... imprime añadiendo datos
                puts("Añadiendo datos...");

                // pregunta por el nombre
                printf ("Introduce nombre: ");

                // guardala dentro la variable nombre de la estructura
                // ubicada en ficha en la posicion "ultimaFicha + 1"
                gets(ficha[ultimaFicha+1].nombre);

                // pregunta por el apellido
                printf("Introduce apellido: ");

                // guardala dentro la variable apellido de la estructura
                // ubicada en ficha en la posicion "ultimaFicha + 1"
                gets(ficha[ultimaFicha+1].apellido);


                // pregunta por la direccion
                printf ("Introduce direccion: ");

                // guardala dentro la variable direccion de la estructura
                // ubicada en ficha en la posicion "ultimaFicha + 1"
                gets(ficha[ultimaFicha+1].direccion);

                // pregunta por el celular
                printf ("Introduce movil: ");

                // guardala dentro la variable nombre de la estructura
                // ubicada en ficha en la posicion "ultimaFicha + 1"
                gets(ficha[ultimaFicha+1].tlfMovil);

                // pregunta por el correo
                printf ("Introduce correo electronico: ");

                // guardala dentro la variable email de la estructura
                // ubicada en ficha en la posicion "ultimaFicha + 1"
                gets(ficha[ultimaFicha+1].email);

                // pregunta por el dia de nacimiento
                printf ("Introduce dia de nacimiento: ");

                // obten lo que haya ingresado el usuario y guardalo
                // en linea
                gets (linea);

                // dale formato a "linea" y guardalo como un entero en
                // la variable diaNac dentro de la estructura ubicada
                // en la posicion "ultimaFicha + 1"
                sscanf(linea, "%d", &ficha[ultimaFicha+1].diaNac);

                // pregunta por el mes de nacimiento
                printf ("Introduce mes de nacimiento: ");

                // obten lo que haya ingresado el usuario y guardalo
                // en linea
                gets (linea);

                // dale formato a "linea" y guardalo como un entero en
                // la variable mesNac dentro de la estructura ubicada
                // en la posicion "ultimaFicha + 1"
                sscanf(linea, "%d", &ficha[ultimaFicha+1].mesNac);

                // pregunta por el año de nacimiento
                printf ("Introduce año de nacimiento: ");
                
                // obten lo que haya ingresado el usuarion y guardalo
                // en linea
                gets(linea);

                // dale formato a "linea" y guardalo como un entero en
                // la variable anyoNac dentro de la estructura ubicada
                // en la posicion "ultimaFicha + 1"
                sscanf(linea, "%d", &ficha[ultimaFicha+1].anyoNac);

                // aumenta la variable ultimaFicha de uno en uno porque
                // se agrego una nueva persona al registro
                ultimaFicha ++;
                break;

            case 2:
                // imprime Fichas existentes:
                puts ("Fichas existentes:");
                // recorre todas las fichas que se encuentren en el arreglo
                // "ficha" e imprime sus nombre
                for (i=0; i<=ultimaFicha; i++)
                    puts(ficha[i].nombre);
                break;

            case 3:
                // pregunta que nombre quiere buscar
                printf ("Nombre a buscar? ");
                // obten el nombre y guardalo en linea
                gets (linea);

                // recorre todo el arreglo en busca del nombre
                // ingresado
                for (i=0; i<=ultimaFicha; i++) {
                    // compara si la ficha actual contiene el nombre
                    // ingresado
                    if (strcmp (linea, ficha[i].nombre) == 0) {
                        // imprime el nombre
                        puts (ficha[i].nombre);
                        // imprime el apellido
                        puts (ficha[i].apellido);
                        // imprime la direccion
                        puts (ficha[i].direccion);
                        // imprime el telefono movil
                        puts (ficha[i].tlfMovil);
                        // immprime el email
                        puts (ficha[i].email);
                        // immpre en una sola linea el dia de nacimiento,
                        // el mes y el año
                        printf("%d %d %d\n", ficha[i].diaNac,
                        ficha[i].mesNac, ficha[i].anyoNac);
                    }
                }
                break;
        }

    } while (opcion != 0);

    // abre el archivo agenda en modo de escritura
    archivo = fopen("agenda.txt", "wt");

    // imprime en pantalla Guardando datos...
    puts("Guardando datos...");

    // recorre todos los elementos del arreglo que contiene las estructuras
    for (i = 0; i <= ultimaFicha; i++)
    {
        // imprime en el archivo el nombre del elemento i del arreglo
        // junto con una nueva linea
        fprintf (archivo, "%s\n", ficha[i].nombre);
        // imprime en el archivo el apellido del elemento i del arreglo
        // junto con una nueva linea
        fprintf (archivo, "%s\n", ficha[i].apellido);
        // imprime en el archivo la direccion del elemento i del arreglo
        // junto con una nueva linea
        fprintf (archivo, "%s\n", ficha[i].direccion);
        // imprime en el archivo el telefono movil del elemento i del arreglo
        // junto con una nueva linea
        fprintf (archivo, "%s\n", ficha[i].tlfMovil);
        // imprime en el archivo el email del elemento i del arreglo
        // junto con una nueva linea
        fprintf (archivo, "%s\n", ficha[i].email);
        // imprime en el archivo el dia, el mes y el año de nacimiento 
        // del elemento i del arreglo, junto con una nueva linea
        fprintf (archivo, "%d %d %d\n",
                 ficha[i].diaNac, ficha[i].mesNac, ficha[i].anyoNac);
    }

    // cierra el archivo
    fclose(archivo);

    // imprime "Terminado"
    printf("Terminado.");

    // termmina la funcion main() con un valor de 0
    return 0;
}
