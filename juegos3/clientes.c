#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "clientes.h"
#include "utn.h"


int validaciones(int signed codigo,int codFun)
{

     switch (codFun){

        case 0:
            //ok para cualquier funcion...
            break;

        case 1:
            if (codigo==-1){

                getChar2("\nError de Inicializacion...Comunicarse con IT Support.\n");
            }

            break;

        case 2:
            if (codigo==-1){

                getChar2("\nError...Registro no encontrado, reintente\n");
            }
            break;

        case 3:
            if (codigo==-1){

            getChar2("\nError...Registro lleno o Inconsistencia en los datos\n");
            }
            break;

        case 4:
            if (codigo==-1){

            getChar2("\nError...Fuera de Rango o Numero invalido\n");
            }
            break;

        case 5: //se refiere a Empleado no Encontrado
            if (codigo==-1){

            getChar2("\nRegistro no encontrado...\n");
            }
            break;

        case 6: //se refiere opcion ingresada erronea
            if (codigo==-1){

            getChar2("\nOpcion Incorrecta / Verifique y reintente...\n");
            }
            break;

        case 7: //se refiere Registros de empleados vacio
            if (codigo==1010 || codigo==-1){

            getChar2("\nRegistros esta Vacio...Realice un alta para continuar\n");
            }
            break;

        default:

            getChar2("Error Inesperado... Comunicarse con IT Support.");

            break;
    }

    return codigo;
}

int NextRegClienteAvailable(Clientes* list, int len)
{
    int i;
    int resul=0;
    int flagSalida=0;

    for (i=0; i<len; i++)
    {
        if (list[i].isEmpty==1)
        {
            flagSalida=1;

            break;
        }
    }
    resul=i;

    if (flagSalida==0){

        resul=1010;
    }

    return resul;
}

int NextRegAlquilerAvailable(Alquileres* list, int len)
{
    int i;
    int resul=0;
    int flagSalida=0;

    for (i=0; i<len; i++)
    {
        if (list[i].isEmpty==1)
        {
            flagSalida=1;

            break;
        }
    }
    resul=i;

    if (flagSalida==0){

        resul=1010;
    }

    return resul;
}

int findNextId(Alquileres list[], int len)
{
    int i;
    int maxId=0;

    for (i=0; i<len; i++)
    {

        if (list[i].codAlquiler>maxId)
        {
            maxId=list[i].codAlquiler;
        }
    }
    maxId++;


return maxId;
}

int findNextIdClientes(Clientes* list, int len)
{
    int i;
    int maxId=0;

    for (i=0; i<len; i++)
    {

        if (list[i].id>maxId)
        {
            maxId=list[i].id;
        }
    }
    maxId++;


return maxId;
}

Clientes findClienteByDesc2 (Clientes* list,int lenC,int idC)
{
    int i;
    Clientes clie;
    for (i=0; i<lenC; i++)
    {
        if (idC==list[i].id)
        {
            clie=list[i];
            break;
        }
    }
    return clie;
}


int findClienteByDesc (Clientes* list,int lenC,int idC,char resul[],char resul2[])
{
    int i;
    int r=0-1;

    for (i=0; i<lenC; i++)
    {
        if (idC==list[i].id)
        {
            strcpy(resul,list[i].name);
            strcpy(resul2,list[i].lastName);
            r=1;
            break;
        }
    }
    return r;
}

Juegos findJuegoByDesc (Juegos* list,int lenJ,int idJ)
{
    int i;
    Juegos gam;

    for (i=0; i<lenJ; i++)
    {
        if (idJ==list[i].id)
        {
            gam=list[i];
            //strcpy(resul,list[i].descripcion);
            //preJ=list[i].precio;

            break;
        }
    }
    return gam;
}

int MuestraOneCliente (Clientes clie,int id,int len)
{
    int r=-1;

            printf("\nId: %d",clie.id);
            printf("\nNombre   : %s",clie.name);
            printf("\nApellido : %s",clie.lastName);
            printf("\nDomicilio: %s",clie.domicilio);
            printf("\nSexo     : %c",clie.sexo);
            printf("\ntelefono : %s",clie.telefono);

            printf("\n");
            printf("\nSexo     : %c",clie.sexo);



            r=1;

    return r;
}

void MuestraAlquiler(Alquileres* list,Clientes* list2,Juegos* list3,
                     int lenA,int lenC,int lenJ)
{
    int i;
    int r;
    char opcion;
    char nomC[51];
    char apeC[51];
    int flagSalida=0;
    int signed flagFinal=1;
    int idA;

    Juegos gam;

    do
    {

    printf("\n\n");

    fflush(stdin);
    r=getInt(&idA,"Ingrese Id Alquiler","Error, Id fuera de rango o Inexistente",1,lenA);

    if (r!=1)continue;

        for (i=0; i<lenA; i++)
        {
            if (list[i].isEmpty==0 && list[i].codAlquiler==idA)
            {
                flagFinal=-1;
                break;
            }
        }

        if (flagFinal==1)
        {
            printf("\nCodigo de Alquiler inexistente... reingrese");
        }
        else
        {
            flagFinal=1;
            findClienteByDesc(list2,lenC,list[i].codCliente,nomC,apeC);

            gam=findJuegoByDesc(list3,lenJ,list[i].CodJuego);

            printf("\nCod.Alquiler       : %d",list[i].codAlquiler);
            printf("\nCod.Cliente        : %d",list[i].codCliente);
            printf("\nNombre Cli         : %s",nomC);
            printf("\nApellido cli       : %s",apeC);
            printf("\nCod.Juego          : %d",list[i].CodJuego);
            printf("\nDescr.Juego        : %s",gam.descripcion);
            printf("\nPrecio.Juego       : %.2f",gam.precio);
            printf("\nFecha              : %d/%d/%d",list[i].fecAlquiler.dia,
                                                     list[i].fecAlquiler.mes,
                                                     list[i].fecAlquiler.anio);
            printf("\n");

        }
    opcion=getChar2("Una tecla continua / <Esc> Salida");
    if (opcion==27)flagSalida=1;

    }while (flagSalida==0);

}

int printOneJuego(Juegos gam)
{
    printf("\n\t%d \t%s \t%.2f ",gam.id,gam.descripcion,gam.precio);

    return 1;
}

int printJuegos(Juegos* list,int lenJ)
{
    int i;
    Juegos gam;
    //int r;

    printf("\n\tCod J \tDesc J \t\t\tPrecio \n");
    rellena_Espacio('-',78,1);

    for (i=0;i<lenJ;i++)
    {
        gam=findJuegoByDesc(list,lenJ,list[i].id),
        printOneJuego(gam);
    }

 printf("\n\n");
 return 0;
}

int printAlquileres(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ)
{
    int i;
    int r;
    int cod;
    int max=lenA; //lenA=maximo alqui //lenC=maximo clientes //lenJ=maximo juegos

    Alquileres alquil;
    Clientes clie;
    Juegos gam;


    //Ordenamiento Alquileres por fecha ascendente
    bubbleSortAlqFecha(list,lenA);

    do{
        printClientes(list2,lenC);

        r=getInt(&cod,"\nIngrese Codigo: ","Error, excedido o no existe",1,max);
        if (r!=1) continue;
    }while (r!=1);

     //titulo si se lista Alquileres c/clientes y juegos
    printf("\nFecha \t\tCod A \tCod C \tNom \tApe \tCod J \tDes J      \tPrecio \n");
    rellena_Espacio('-',78,1);


    /*  //titulo si se lista clientes
    printf("\n\tCod Cli \tApe \tNom \tDomicilio \tSexo \tTelefono\n");
    rellena_Espacio('-',78,1);
    */

    /*  //titulo si se lista juegos
    printf("\n\tCod Jue \tDescr \tPrecio\n");
    rellena_Espacio('-',78,1);
    */

    for (i=0;i<lenA;i++)
    {
         //en el if recorre alquileres mientras codJuego/codAlq/codclie == cod(ing usuario)
        if (list[i].isEmpty!=1 && list[i].codAlquiler!=0 && list[i].codCliente==cod)
        {
            //busca y trae una structure Clientes con los datos [i]
            clie=findClienteByDesc2(list2,lenC,list[i].codCliente);

            //busca y trae una structure juegos con los datos [i]
            gam=findJuegoByDesc(list3,lenJ,list[i].CodJuego);

            //crea una estructura Alquileres con los datos de [i]
            alquil=list[i];

            //imprime un registro alquileres + datos Clientes + datos juegos
            printOneAlquiler(alquil,clie.name,clie.lastName,gam.descripcion,gam.precio);

            //imprime datos de clientes sacados de alquileres [i]
            //printOneCliente(clie);

            //imprime datos de juegos sacados de alquileres [i]
            //printOneJuego(gam);

        }
    }

 printf("\n\n");
 return 0;
}

int printOneAlquiler(Alquileres alquil,char nomC[],char apeC[],char descJ[],float preJ)
{
    //int r;

    printf("\n%d %d %d  \t%d \t%d \t%s \t%s \t%d \t%s %.2f",alquil.fecAlquiler.anio,
           alquil.fecAlquiler.mes,alquil.fecAlquiler.dia,alquil.codAlquiler,
           alquil.codCliente,nomC,apeC,alquil.CodJuego,descJ,preJ);

    return 1;
}
char muestraMenu(void)
{
    char opcion;
    system("cls");
    getChoiceForm(" Menu Principal ",1,78);

    printf("\na- ");
    printf("\nb- ");
    printf("\nc- ");
    printf("\nd- ");
    printf("\ne- ");
    printf("\nf- Alquileres x Fecha");
    printf("\ng- Muestra Alquileres");
    printf("\n\ns- Salida");

    printf("\n\n ");
    opcion=getChar2("Ingrese una Opcion / <s> para Salir");

    return opcion;

}

int printOneCliente(Clientes cli)
{
    //int r;

    printf("\n\t%d \t%s \t%s \t%s \t%c \t%s ",cli.id,cli.name,cli.lastName
                                             ,cli.domicilio,cli.sexo,cli.telefono);

    return 1;
}

int printClientes(Clientes* list,int lenC)
{
    int i;
    Clientes aux;
    //int r;

    printf("\n\tCod C \tNomC \tApeC \tDom C \tSexo \tTelef \n");
    rellena_Espacio('-',78,1);

    for (i=0;i<lenC;i++)
    {
        if (list[i].isEmpty!=1 && list[i].id!=0)
        {

            aux=findClienteByDesc2(list,lenC,list[i].id);
            printOneCliente(aux);
        }


    }

 printf("\n\n");
 return 0;
}


void bubbleSortAlqFecha (Alquileres* list ,int len)
{
    int j;
    int f1;
    int f2;

    Alquileres aux;

    int flagNoEstaOrdenado = 1;

    while (flagNoEstaOrdenado==1)
    {

      flagNoEstaOrdenado = 0;

        for (j = 1; j < len; j++)
	    {
            f1=(list[j].fecAlquiler.anio*10000)+(list[j].fecAlquiler.mes*100)+list[j].fecAlquiler.dia;
            f2=(list[j-1].fecAlquiler.anio*10000)+(list[j-1].fecAlquiler.mes*100)+list[j-1].fecAlquiler.dia;
            //printf("%d      %d       %d    %d",list[j].fecAlquiler,list[j-1].fecAlquiler,f1,f2);system("pause");
            //if(list[j].precio < list[j-1].precio)
            if(f1 > f2)
	        {
                aux = list[j];
                list[j] = list[j - 1];
                list[j - 1] = aux;

                flagNoEstaOrdenado = 1;
            }
        }
    }
 }