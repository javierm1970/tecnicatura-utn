#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "clientes.h"
#include "utn.h"

#define MAX_CLIENTES 1000
#define MAX_ALQUILERES 5000
#define MAX_JUEGOS 5

int main()
{
    Alquileres alqui[MAX_ALQUILERES];
    Alquileres alq;
    Clientes client[MAX_CLIENTES];
    Clientes clie;
    Juegos game[MAX_JUEGOS];

    hardCord3(alqui,MAX_ALQUILERES);
    hardCord2(client,MAX_CLIENTES);
    hardCord(game,MAX_JUEGOS);

    int flagSalida=0;
    int idCli;
    int idAlq;
    int r;
    char opcion;

    do
    {
        opcion=muestraMenu();

        switch(opcion)
        {
            case 'a':

                idCli=findNextIdClientes(client,MAX_CLIENTES);

                clie=carga_Clientes(clie,MAX_CLIENTES,idCli);

                r=addCliente(client,MAX_CLIENTES,clie.id,clie.name,clie.lastName,
                             clie.domicilio,clie.sexo,clie.telefono);

                if (!r)
                {
                    printf("\nNo se ha podido dar el alta");
                    system("pause");
                    break;
                }
                break;

            case 'b':

                r=removeCliente(client,MAX_CLIENTES);
                break;

            case 'c':

                r=ModificaUnCliente(client,MAX_CLIENTES);
                printf("Modificacion");

                system("pause");
                break;

            case 'd':

                juegosSortDesc(game,MAX_JUEGOS);
                printJuegos(game,MAX_JUEGOS);
                system("pause");
                break;

            case 'e':
                clienteSortLastName(client,MAX_CLIENTES);
                printClientes(client,MAX_CLIENTES);
                system("pause");
                break;

            case 'f':

                getChoiceForm("Carga Ocurrencias de Alquiler",1,78);

                idAlq=findNextId(alqui,MAX_ALQUILERES);

                alq=carga_Alquileres(client,game,MAX_CLIENTES,MAX_JUEGOS,idAlq);

                r=addAlquileres(alqui,MAX_ALQUILERES,alq.codAlquiler,alq.codCliente,alq.CodJuego,alq.fecAlquiler);
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
                AlquileresPorFechaxJuegos(alqui,client,game,MAX_ALQUILERES,MAX_CLIENTES,MAX_JUEGOS);
                //ClienteMasAlquila(alqui,client,MAX_ALQUILERES,MAX_CLIENTES);
                system("pause");
                break;

            case 'n':
                AlquileresPorFechaxClientes(alqui,client,game,MAX_ALQUILERES,MAX_CLIENTES,MAX_JUEGOS);
                system("pause");
                break;

            case 'o':
                bubbleSortCodJuegos(game,MAX_JUEGOS);
                printJuegos(game,MAX_JUEGOS);
                system("pause");
                break;

            case 'p':

                insertion(client,MAX_CLIENTES);
                printClientes(client,MAX_CLIENTES);
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


