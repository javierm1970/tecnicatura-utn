#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "./Clientes.h"
#include "./utn.h"

#define MAX_CLIENTES 9
#define MAX_JUEGOS 5
#define MAX_ALQUILER 10

int main()
{

    Clientes client[MAX_CLIENTES];
    Juegos game[MAX_JUEGOS];
    Alquileres alqui[MAX_ALQUILER];
    Alquileres alq;
    Clientes clie;

    hardCord(game,5);
    hardCord2(client,9);
    hardCord3(alqui,10);


    char opcion;
    char opcion2;
    char opcion5;

    //char opcion3;

    int r=0;
    int idAlq;
    int idCli;
    int flagSalida=0;

    fflush(stdin);
    //r=initClientes(client,MAX_CLIENTES);

    r=validaciones(r,1);
    if (r==-1){
        return -1;
    }
    //r=initAlquileres(alqui,MAX_ALQUILER);

    r=validaciones(r,1);
    if (r==-1){
        return -1;
    }

    while(flagSalida==0)
    {

        system("cls");



        printf("\n1- Alta");
        printf("\n2- Baja");
        printf("\n3- Modificacion");
        printf("\n4- lista juegos");
        printf("\n5- lista clientes");
        printf("\n6- carga alquileres");

        printf("\n7- Prom.y Totales de juego");
        printf("\n8- Juegos bajo la media");
        printf("\n9- Clientes x juegos");
        printf("\n10- clientes x juego");
        printf("\n11- Juegos Menos Alq");
        printf("\n12- cliente mas alquiler");
        printf("\n13- Juegos x fecha");
        printf("\n14- al menos un alq en fecha");
        printf("\n15- juegos x importe (desc)");
        printf("\n16- clientes x apell(asc.)");


        scanf("%d",&opcion5);



        system("pause");



/*
        if (opcion<1 || opcion>16)
        {
            printf("Error, Opcion Incorrecta... reintente ");
            continue;
        }
*/
        switch (opcion5)
        {
            case  1:

                idCli=findNextIdClientes(client,MAX_CLIENTES);

                clie=carga_Clientes(clie,MAX_CLIENTES,idCli);

                r=addCliente(client,MAX_CLIENTES,clie.id,clie.name,clie.lastName,
                             clie.domicilio,clie.sexo,clie.telefono);

                break;

            case 2:

                r=removeCliente(client,MAX_CLIENTES);
                printf("Baja");
                break;
            case 3:

                r=ModificaUnCliente(client,MAX_CLIENTES);
                printf("Modificacion");
                break;
            case 4:
                printJuegos(game,MAX_JUEGOS);
                system("pause");
                break;

            case 5:

                printClientes(client,MAX_CLIENTES);
                //printAlquileresJ(alqui,client,game,MAX_ALQUILER,MAX_CLIENTES,MAX_JUEGOS);
                //printJuegos(game,MAX_JUEGOS);
                system("pause");

                //printf("Reportes de juegos");
                continue;

            case 6:

                getChoiceForm("Carga Ocurrencias de Alquiler",1,78);
                //opcion3=getChar2("\n1- Alta\n2- Baja\n3- Modificacion\n4- Salida\n");

                idAlq=findNextId(alqui,MAX_ALQUILER);

                alq=carga_Alquileres(client,game,MAX_CLIENTES,MAX_JUEGOS,idAlq);

                r=addAlquileres(alqui,MAX_ALQUILER,alq.codAlquiler,alq.codCliente,alq.CodJuego,alq.fecAlquiler);

                //Muestra_Alquiler(alqui,client,game,MAX_ALQUILER,MAX_CLIENTES,MAX_JUEGOS,idAlq);
                printAlquileres(alqui,client,game,MAX_ALQUILER,MAX_CLIENTES,MAX_JUEGOS);

                system("pause");
                continue;

                    case 7:

                        PromedioJuegos(alqui,game,MAX_ALQUILER,MAX_JUEGOS);
                        system("pause");

                        continue;

                    case 8:

                        PromedioJuegos2(alqui,game,MAX_ALQUILER,MAX_JUEGOS);
                        system("pause");

                        continue;
                    case 9:

                        printAlquileresJ(alqui,client,game,MAX_ALQUILER,MAX_CLIENTES,MAX_JUEGOS);
                        system("pause");

                        break;

                    case 10:

                        printAlquileresC(alqui,client,game,MAX_ALQUILER,MAX_CLIENTES,MAX_JUEGOS);
                        system("pause");
                        break;

                    case 11:


                        break;

                    case 12:


                        break;

                    case 13:


                        break;

                    case 14:


                        break;

                    case 15:

                        bubbleSort(game,MAX_JUEGOS);
                        system("pause");
                        printJuegos(game,MAX_JUEGOS);
                        system("pause");

                        break;

                    case 16:
                        insertion(client,MAX_CLIENTES);
                        printClientes(client,MAX_CLIENTES);
                        system("pause");

                        break;

                    defalt:


                        break;



                }



/*

             case '4':

                printAlquileres(alqui,client,game,MAX_ALQUILER,MAX_CLIENTES,MAX_JUEGOS);

                system("pause");
                continue;

            case '5':
                getChoiceForm("Carga Ocurrencias de Alquiler",1,78);
                //opcion3=getChar2("\n1- Alta\n2- Baja\n3- Modificacion\n4- Salida\n");

                idAlq=findNextId(alqui,MAX_ALQUILER);

                alq=carga_Alquileres(client,game,MAX_CLIENTES,MAX_JUEGOS,idAlq);

                r=addAlquileres(alqui,MAX_ALQUILER,alq.codAlquiler,alq.codCliente,alq.CodJuego,alq.fecAlquiler);

                //Muestra_Alquiler(alqui,client,game,MAX_ALQUILER,MAX_CLIENTES,MAX_JUEGOS,idAlq);
                printAlquileres(alqui,client,game,MAX_ALQUILER,MAX_CLIENTES,MAX_JUEGOS);

                system("pause");
                continue;

            case '6':
                flagSalida=1;
                printf("Salida");
                break;

            default:
                continue;
*/
        //}

    }

    return 0;
}


