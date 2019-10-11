#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "clientes.h"
#include "utn.h"

#define MAX_CLIENTES 19
#define MAX_ALQUILERES 29
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

                system("pause");
                break;

            case 'g':
                PromedioJuegos(alqui,game,MAX_ALQUILERES,MAX_JUEGOS);
                system("pause");
                break;

            case 'h':
                PromedioJuegos2(alqui,game,MAX_ALQUILERES,MAX_JUEGOS);
                system("pause");
                break;

            case 'i':
                AlquileresPorCliente(alqui,client,game,MAX_ALQUILERES,MAX_CLIENTES,MAX_JUEGOS);
                //printClientes(client,MAX_CLIENTES);
                system("pause");
                break;

            case 'j':
                AlquileresPorJuego(alqui,client,game,MAX_ALQUILERES,MAX_CLIENTES,MAX_JUEGOS);
                //JuegosMenosAlquilados(alqui,game,MAX_ALQUILERES,MAX_JUEGOS);
                system("pause");
                break;

            case 'k':
                JuegosMenosAlquilados(alqui,game,MAX_ALQUILERES,MAX_JUEGOS);
                //printAlquileres(alqui,client,game,MAX_ALQUILERES,MAX_CLIENTES,MAX_JUEGOS);
                system("pause");
                break;

            case 'l':
                ClienteMasAlquila(alqui,client,MAX_ALQUILERES,MAX_CLIENTES);
                //MuestraAlquiler(alqui,client,game,MAX_ALQUILERES,MAX_CLIENTES,MAX_JUEGOS);
                system("pause");
                break;

            case 'm':

                //ClienteMasAlquila(alqui,client,MAX_ALQUILERES,MAX_CLIENTES);
                system("pause");
                break;

            case 'n':

                system("pause");
                break;

            case 'o':
                bubbleSortCodJuegos(game,MAX_JUEGOS);
                printJuegos(game,MAX_JUEGOS);
                system("pause");
                break;

            case 'p':

                system("pause");
                break;

            case 's':

                system("pause");
                flagSalida=1;
                break;


        }





    }while (flagSalida==0);







    return 0;
}
