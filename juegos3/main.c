#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "clientes.h"
#include "utn.h"

#define MAX_CLIENTES 27
#define MAX_ALQUILERES 28
#define MAX_JUEGOS 5

int main()
{
    Alquileres alqui[MAX_ALQUILERES];
    Clientes client[MAX_CLIENTES];
    Juegos game[MAX_JUEGOS];

    hardCord3(alqui,MAX_ALQUILERES);
    hardCord2(client,MAX_CLIENTES);
    hardCord(game,MAX_JUEGOS);

    int flagSalida=0;
    char opcion;

    do
    {
        opcion=muestraMenu();

        switch(opcion)
        {
            case 'a':

                system("pause");
                break;

            case 'b':

                system("pause");
                break;

            case 'c':

                system("pause");
                break;

            case 'd':

                system("pause");
                break;

            case 'e':

                system("pause");
                break;

            case 'f':
                printAlquileres(alqui,client,game,MAX_ALQUILERES,MAX_CLIENTES,MAX_JUEGOS);
                system("pause");
                break;

            case 'g':
                MuestraAlquiler(alqui,client,game,MAX_ALQUILERES,MAX_CLIENTES,MAX_JUEGOS);
                break;

            case 's':

                system("pause");
                flagSalida=1;
                break;


        }





    }while (flagSalida==0);







    return 0;
}
