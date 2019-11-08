#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

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
        if (list[i].isEmpty==0)
        {
            if (list[i].codAlquiler>maxId)
            {
                maxId=list[i].codAlquiler;
            }
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
        if (idC==list[i].id && list[i].isEmpty==0)
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
        if (idC==list[i].id && list[i].isEmpty==0)
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

float findJuegoByDesc2(Juegos* list,int lenJ,int idJ,char resul[])
{
    int i;
    float preJ;

    for (i=0; i<lenJ; i++)
    {
        if (idJ==list[i].id)
        {
            strcpy(resul,list[i].descripcion);
            preJ=list[i].precio;
            //*precJ=list[i].precio;
            break;
        }
    }
    return preJ;
}

int findJuegoByID (Juegos* list,int lenJ,int idJ)
{
    int i;
    int resul=-1;

    for (i=0; i<lenJ; i++)
    {
        if (idJ==list[i].id)
        {
            resul=1;
            break;
        }
    }
    return resul;
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

int AlquileresPorFecha(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ)
{
    int i;
    int r;
    int cod;
    int max=lenA; //lenA=maximo alqui //lenC=maximo clientes //lenJ=maximo juegos

    Alquileres alquil;
    Clientes clie;
    Juegos gam;


    //Ordenamiento Alquileres por fecha ascendente
    //bubbleSortAlqFecha(list,lenA);
    bubbleSortAlqFecha(list,lenA);

    do{
        printJuegos(list3,lenJ);

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
        if (list[i].isEmpty!=1 && list[i].codAlquiler!=0 && list[i].CodJuego==cod)
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

int AlquileresPorJuego(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ)
{
    int i;
    int r;
    int r3;
    int cod;
    int max=lenA; //lenA=maximo alqui //lenC=maximo clientes //lenJ=maximo juegos

    Alquileres alquil;
    Clientes clie;
    Juegos gam;

    bubbleSortAlqFecha(list,lenA);

    do{
        printJuegos(list3,lenJ);

        r=getInt(&cod,"\nIngrese Codigo: ","Error, excedido o no existe",1,max);
        if (r!=1) continue;

        r3=findJuegoByID(list3,lenJ,cod);
        if (r3<0)
        {
            printf("\nError, juego no hallado, reintente...\n");
            system("pause");
            r=0;
        }



    }while (r!=1);

     //titulo si se lista Alquileres c/clientes y juegos
    printf("\nFecha \t\tCod A \tCod C \tNom \tApe \tCod J \tDes J      \tPrecio \n");
    rellena_Espacio('-',78,1);

    for (i=0;i<lenA;i++)
    {
         //en el if recorre alquileres mientras codJuego/codAlq/codclie == cod(ing usuario)
        if (list[i].isEmpty!=1 && list[i].codAlquiler!=0 && list[i].CodJuego==cod)
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


int AlquileresPorCliente(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ)
{
    int i;
    int r;
    int r3;
    int cod;
    int max=lenA; //lenA=maximo alqui //lenC=maximo clientes //lenJ=maximo juegos

    Alquileres alquil;
    Clientes clie;
    Juegos gam;

    bubbleSortAlqFecha(list,lenA);

    do{

        clienteSortId(list2,lenC);
        printClientes(list2,lenC);

        r=getInt(&cod,"\nIngrese Codigo: ","Error, excedido o no existe",1,max);
        if (r!=1) continue;
        r3=findClientById(list2,lenC,cod);
        if (r3<1){
            printf("\nError, cliente no encontrado, reintente...\n");
            system("pause");
            r=0;
        }

    }while (r!=1);

     //titulo si se lista Alquileres c/clientes y juegos
    printf("\nFecha \t\tCod A \tCod C \tNom \tApe \tCod J \tDes J      \tPrecio \n");
    rellena_Espacio('-',78,1);

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

        }
    }

 printf("\n\n");
 return 0;
}

int AlquileresPorFechaxClientes(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ)
{
    int i;
    int r;
    //int r3;
    int dia2;
    int mes2;
    int anio2;

    //Alquileres alquil;
    Clientes clie;
    //Juegos gam;

    bubbleSortAlqFecha(list,lenA);

    system("cls");
    getChoiceForm("Clientes que Alquilaron en una fecha",1,78);

    do{

        r=getInt(&dia2,"\nIngrese Dia: ","Error, en el dia",1,31);
        if (r!=1) continue;
        r=getInt(&mes2,"\nIngrese Mes: ","Error, en el mes",1,12);
        if (r!=1) continue;
        r=getInt(&anio2,"\nIngrese Anio: ","Error, en el anio",1900,2019);
        if (r!=1) continue;

    }while (r!=1);

     //titulo si se lista Alquileres c/clientes y juegos
    printf("\n\tCod C \tNom \tApe \tDom  \tSexo  \tTelefono \n");
    rellena_Espacio('-',78,1);

    for (i=0;i<lenA;i++)
    {
         //en el if recorre alquileres mientras codJuego/codAlq/codclie == cod(ing usuario)
        if (list[i].isEmpty==0 && list[i].fecAlquiler.dia==dia2 && list[i].fecAlquiler.mes==mes2 && list[i].fecAlquiler.anio==anio2)
        {
            //busca y trae una structure Clientes con los datos [i]
            clie=findClienteByDesc2(list2,lenC,list[i].codCliente);

            //busca y trae una structure juegos con los datos [i]
            //gam=findJuegoByDesc(list3,lenJ,list[i].CodJuego);

            //crea una estructura Alquileres con los datos de [i]
            //alquil=list[i];

            //imprime un registro alquileres + datos Clientes + datos juegos
            //printOneAlquiler(alquil,clie.name,clie.lastName,gam.descripcion,gam.precio);
            printOneCliente(clie);

        }
    }

 printf("\n\n");
 return 0;
}

int AlquileresPorFechaxJuegos(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ)
{
    int i;
    int r;
    //int r3;
    int dia2;
    int mes2;
    int anio2;

    //Alquileres alquil;
    //Clientes clie;
    Juegos gam;

    bubbleSortAlqFecha(list,lenA);

    system("cls");
    getChoiceForm("Juegos que se Alquilaron en una fecha",1,78);

    do{

        r=getInt(&dia2,"\nIngrese Dia: ","Error, en el dia",1,31);
        if (r!=1) continue;
        r=getInt(&mes2,"\nIngrese Mes: ","Error, en el mes",1,12);
        if (r!=1) continue;
        r=getInt(&anio2,"\nIngrese Anio: ","Error, en el anio",1900,2019);
        if (r!=1) continue;

    }while (r!=1);

     //titulo si se lista Alquileres c/clientes y juegos
    printf("\n\tCod J \tDescripcion \tPrecio \n");
    rellena_Espacio('-',78,1);

    for (i=0;i<lenA;i++)
    {
         //en el if recorre alquileres mientras codJuego/codAlq/codclie == cod(ing usuario)
        if (list[i].isEmpty==0 && list[i].fecAlquiler.dia==dia2 && list[i].fecAlquiler.mes==mes2 && list[i].fecAlquiler.anio==anio2)
        {
            //busca y trae una structure Clientes con los datos [i]
            //clie=findClienteByDesc2(list2,lenC,list[i].codCliente);

            //busca y trae una structure juegos con los datos [i]
            gam=findJuegoByDesc(list3,lenJ,list[i].CodJuego);

            //crea una estructura Alquileres con los datos de [i]
            //alquil=list[i];

            //imprime un registro alquileres + datos Clientes + datos juegos
            //printOneAlquiler(alquil,clie.name,clie.lastName,gam.descripcion,gam.precio);
            //printOneCliente(clie);
            printOneJuego(gam);
        }
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

    bubbleSortCodJuegos(list3,lenJ);

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

    printf("\na- Alta Clientes");
    printf("\nb- Baja Clientes");
    printf("\nc- Modificacion Clientes");
    printf("\nd- Lista juegos x Desc (asc)");
    printf("\ne- Lista clientes x Apellido y Nombre");
    printf("\nf- carga alquileres");
    printf("\ng- Promedio y total de juegos alq.");
    printf("\nh- Cantidad de juegos Alq. debajo de la media");
    printf("\ni- Alquileres x Clientes");
    printf("\nj- Alquileres x juegos");
    printf("\nk- Juegos menos alquilados");
    printf("\nl- Cliente que mas alquilo");
    printf("\nm- Juegos Alquilados x Fecha");
    printf("\nn- Clientes que Alquilaron en una fecha");
    printf("\no- Juegos x importes (desc) B.E.");
    printf("\np- Clientes x Apellido (asc) M.I.");
    printf("\n\ns- Salida");

    printf("\n\n ");
    opcion=getChar2("\nIngrese una Opcion / <s> para Salir ");
    printf("\n ");
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

void bubbleSortCodJuegos (Juegos* list ,int len)
{
    int j;

    Juegos aux;

    int flagNoEstaOrdenado = 1;

    while (flagNoEstaOrdenado==1)
    {

      flagNoEstaOrdenado = 0;

        for (j = 1; j < len; j++)
	    {
            if(list[j].id > list[j-1].id)
	        {
                aux = list[j];
                list[j] = list[j - 1];
                list[j - 1] = aux;

                flagNoEstaOrdenado = 1;
            }
        }
    }
 }

void juegosSortDesc(Juegos* list ,int len)
{
    int j;
    int i;
    int flagNoEstaOrdenado = 1;

    Juegos aux;

    while (flagNoEstaOrdenado==1)
    {


      flagNoEstaOrdenado = 0;

        for (j = 1; j < len; j++)
	    {

            i=strcmp(list[j].descripcion,list[j-1].descripcion);

            if(i<0)
	        {
                aux = list[j];
                list[j] = list[j - 1];
                list[j - 1] = aux;

                flagNoEstaOrdenado = 1;
            }
        }
     }
 }

void clienteSortId(Clientes* list ,int len)
{
    int j;
    //int i;

    int flagNoEstaOrdenado = 1;

    Clientes aux;

    while (flagNoEstaOrdenado==1)
    {

      flagNoEstaOrdenado = 0;

        for (j = 1; j < len; j++)
	    {
            if(list[j].id<list[j-1].id)
	        {
                aux = list[j];
                list[j] = list[j - 1];
                list[j - 1] = aux;

                flagNoEstaOrdenado = 1;
            }
        }
     }
 }

void clienteSortLastName(Clientes* list ,int len)
{
    int j;
    int i;
    int i2;
    int flagNoEstaOrdenado = 1;

    Clientes aux;

    while (flagNoEstaOrdenado==1)
    {

      flagNoEstaOrdenado = 0;

        for (j = 1; j < len; j++)
	    {

            i=strcmp(list[j].lastName,list[j-1].lastName);

            if(i<0)
	        {
                aux = list[j];
                list[j] = list[j - 1];
                list[j - 1] = aux;

                flagNoEstaOrdenado = 1;
            }
            else
            {
                if (i==0)
                {
                    i2=strcmp(list[j].name,list[j-1].name);

                    if (i2<0)
                    {
                        aux = list[j];
                        list[j] = list[j - 1];
                        list[j - 1] = aux;

                        flagNoEstaOrdenado = 1;
                    }
                }
            }
        }
     }
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

 int PromedioJuegos(Alquileres* list,Juegos* list3, int len,int lenJ)
{
    int i;
    int j;
    int res=-1;
    float prom=0;
    float promedio=0;
    int cantCli=0;
    int supProm=0;

    Juegos gam;

     for (i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            gam=findJuegoByDesc(list3,lenJ,list[i].CodJuego);

            prom = prom + gam.precio;
            cantCli++;

        }
    }
    promedio=prom/cantCli;
    printf("\n\n\n");
    printf("\nEl promedio de todos los Juegos Alquilados es: %.2f \n",promedio);
    printf("\nLa suma de todos los Juegos es: %.2f \n",prom);

    for (j=0;j<lenJ;j++)
    {
           //precJ=findJuegoByDesc(list3,lenJ,list[i].CodJuego,descJ);

            if (promedio>list3[j].precio)
            {
                supProm++;
            }
    }

    //printf("\n\n\n");
    //printf("\n\n\n");
    //printf("\nLa cantidad de juegos debajo de la media es: %d \n\n\n",supProm);
    printf("\n\n");
    res=0;

    return res;
}

 int PromedioJuegos2(Alquileres* list,Juegos* list3, int len,int lenJ)
{
    int i;
    int j;
    int res=-1;
    float prom=0;
    float promedio=0;
    int cantCli=0;
    int supProm=0;

    Juegos gam;

     for (i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            gam=findJuegoByDesc(list3,lenJ,list[i].CodJuego);

            prom = prom + gam.precio;
            cantCli++;

        }
    }
    promedio=prom/cantCli;
//    printf("\n\n\n");
//    printf("\nEl promedio de todos los Juegos Alquilados es: %2.f \n",promedio);
//    printf("\nLa suma de todos los Juegos es: %2.f \n",prom);

    for (j=0;j<lenJ;j++)
    {
           //precJ=findJuegoByDesc(list3,lenJ,list[i].CodJuego,descJ);

            if (promedio>list3[j].precio)
            {
                supProm++;
            }
    }

    printf("\n\n\n");
    printf("\n\n\n");
    printf("\nLa cantidad de juegos debajo de la media es: %d \n\n\n",supProm);
    printf("\n\n");
    res=0;

    return res;
}

 int JuegosMenosAlquilados(Alquileres* list,Juegos* list3, int len,int lenJ)
{
    int j;
    int k;
    int res=-1;
    int cantJueAlq=0;
    int cantJue2=0;
    int cantJueMenor=0;
    int flagPrimerJ=0;

    Juegos gam;

    for (j=0;j<lenJ;j++)
    {
        for (k=0;k<len;k++)
        {
            if(list[k].CodJuego==list3[j].id && list[k].isEmpty==0)
            {
                cantJueAlq++;
            }
        }
        if(flagPrimerJ==0)
        {
            cantJueMenor=cantJueAlq;
            flagPrimerJ=1;
        }
        else
        {
            if(cantJueMenor>cantJueAlq)
            {
                cantJueMenor=cantJueAlq;
            }
        }
        cantJueAlq=0;
    }
//***********************************************************************
     for (j=0;j<lenJ;j++)
     {
        for (k=0;k<len;k++)
        {
            if(list[k].CodJuego==list3[j].id && list[k].isEmpty==0)
            {
                cantJue2++;
            }
        }
        //printf("%d   %d",cantJue2,list[k].CodJuego);
        //system("pause");
        if (cantJue2==cantJueMenor)
        {
            gam=findJuegoByDesc(list3,lenJ,list3[j].id);
            //printf("\n  %d",cantJue2);
            printOneJuego(gam);
        }
        cantJue2=0;
     }
    printf("\n");
    return res;
}

 int ClienteMasAlquila(Alquileres* list,Clientes* list3, int lenA,int lenC)
{
    int j;
    int k;
    int res=-1;
    int cantCliAlq=0;
    //int cantCli2=0;
    int cantCliMayor=0;
    int flagPrimerJ=0;

    Clientes clie;

    for (j=0;j<lenC;j++)
    {
        for (k=0;k<lenA;k++)
        {
            if (list3[j].id==list[k].codCliente && list[k].isEmpty==0 && list3[j].isEmpty==0)
            {
                cantCliAlq++;
            }
        }
        if(flagPrimerJ==0)
        {
            cantCliMayor=cantCliAlq;
            flagPrimerJ=1;
        }
        else
        {
            //< mas alquilan || > menos alquilan
            if(cantCliAlq>cantCliMayor)
            {
                cantCliMayor=cantCliAlq;
            }
        }
        cantCliAlq=0;

    }
    //printf("%d",cantCliMayor);system("pause");
//****************************************************************
    cantCliAlq=0;
    for (j=0;j<lenC;j++)
    {
        for (k=0;k<lenA;k++)
        {
            if (list3[j].id==list[k].codCliente && list[k].isEmpty==0 && list3[j].isEmpty==0)
            {
                cantCliAlq++;
            }
        }
        if (cantCliAlq==cantCliMayor)
        {
            clie=findClienteByDesc2(list3,lenC,list3[j].id);
            //printf("\n  %d",cantCliAlq);
            printOneCliente(clie);
        }
        cantCliAlq=0;

     }
    printf("\n");
    return res;
}

Clientes carga_Clientes(Clientes cli3,int len,int id)
{
    //int r;
    char name[51];
    char lastName[51];
    char domicilio[51];
    char sexo;
    char telefono[10];
    int flagSalida4=0;

    int valida_nom;
    int valida_ape;
    int valida_dom;
    int valida_tel;

    system("cls");

    getChoiceForm("Alta de Empleados",1,78);

    printf("\nId de Empleado: %d\n",id);

    do{
        getString("ingrese un nombre(50): ",name,51);
        valida_nom=esAlfaNumerico(name);
        if (valida_nom) break;
        printf("Contiene caracteres no permitidos, reintente... ");
    }while (valida_nom!=1);

    do{
        getString("ingrese un apellido(50): ",lastName,51);
        valida_ape=esAlfaNumerico(name);
        if (valida_ape) break;
        printf("Contiene caracteres no permitidos, reintente... ");
    }while (valida_ape!=1);

    do{
        getString("ingrese domicilio(50): ",domicilio,51);
        valida_dom=esAlfaNumerico(domicilio);
        if (valida_dom) break;
        printf("Contiene caracteres no permitidos, reintente... ");
    }while (valida_dom!=1);

    do
    {
        sexo=getChar("ingrese Sexo del Cliente: ");
        if (sexo!='M' && sexo!='m' && sexo!='f' && sexo!='F')
        {
            printf("Error en el ingreso del sexo...reintente ");
            continue;
        }
        break;
    }while (flagSalida4==0);

    do{
        getString("ingrese numero de Tel(10): ",telefono,10);
        valida_tel=esAlfaNumerico(telefono);
        if (valida_tel) break;
        printf("Contiene caracteres no permitidos, reintente... ");
    }while (valida_tel!=1);

        cli3.id=id;
        strcpy(cli3.name,name);
        strcpy(cli3.lastName,lastName);
        strcpy(cli3.domicilio,domicilio);
        cli3.sexo=sexo;
        strcpy(cli3.telefono,telefono);
        cli3.isEmpty=0;

return cli3;
}


int addCliente(Clientes* list, int len, int id, char name[],char lastName[],
                               char domicilio[],char sexo,char telefono[])
{
    char res_Alta2;
    int id_reg;
    int r=0;
    int i=0;
    int signed resul;

    r=id_reg=NextRegClienteAvailable(list,len);

    i=r;
    if (i>len)
    {
        printf("Error... No hay registros disponibles para dar de Alta");
        resul=-1;
        system("pause");
        return resul;
    }

    res_Alta2=getChar2("\n\nPresione una tecla para Grabar / <Esc> NO GRABA");

    if (res_Alta2!=27)
    {
        list[i].id=id;
        strcpy(list[i].name,name);
        strcpy(list[i].lastName,lastName);
        strcpy(list[i].domicilio,domicilio);
        list[i].sexo=sexo;
        strcpy(list[i].telefono,telefono);
        list[i].isEmpty=0;
        resul=1;
    }
    else
    {
        getChar("\nNo fue posible dar el Alta...");
        resul=-1;
    }

return resul;
}

int removeCliente(Clientes* list,int len)
{
    //int i;
    char opc;
    int r=0;
    int r2=0;
    int flagSalida=0;
    int idE;
    int reg;

    Clientes cli;

    do{
        r2=isAvailable(list,len);

        if (r2>len){
            r2=validaciones(r2,7);//se refiere a Reg Vacio
            flagSalida=1;
            r=-1;
            system("cls");
            break;
        }


        system("cls");
        getChoiceForm("Baja de Clientes",1,78);

        printClientes(list,len);

        r2=getInt(&idE,"Ingrese Id (1-1000): ","Error Numero invalido, verifique el rango",1,1000);

        r=findClientById(list,len,idE);

        if (r<0){

            r=validaciones(r,5); //se refiere a busqueda de Empleados
            continue;
        }
        //i=r;

        cli=llenacliente(list,cli,idE,len);

        r2=MuestraOneCliente(cli,idE,len);



        if (r2<0){
            validaciones(r2,5);
            r=-1;
            flagSalida=1;
        }

        reg=findRegistroClient(list,len,idE);

        rellena_Espacio('*',78,1);
        getChoiceForm("ADVERTENCIA, Verifique los datos antes de proceder",1,78);
        getChoiceForm("Ultime los esfuerzo y Cerciorese antes de continuar",1,78);
        rellena_Espacio('*',78,1);

        opc=getChar2("\n\nTecla <B> Para Borrar / Cualquier Otra Tecla sale sin Borrar");

        if (opc!='B' && opc!='b'){

            getChar2("\n\nRegistro \"NO\" Borrado, una tecla para continuar");
            r=0;
            break;;
        }
        else
        {
            fflush(stdin);
            opc=getChar2("\n\nEsta Seguro? S / Otra Tecla sale sin Borrar");

            if (opc=='s' || opc=='S'){

                list[reg].isEmpty=1;
                getChar2("\n\nEl Registro ha sido borrado, una tecla para continuar");
                r=1;
                break;
            }
            r=0;
            flagSalida=1;

        }

    }while(flagSalida==0);

 return r;
}

Clientes llenacliente(Clientes clie[],Clientes cli,int id,int len)
{
    int i;
    //int r;

    for (i=0;i<len;i++){

        if (id==clie[i].id)
        {
            cli.id=clie[i].id;
            strcpy(cli.name,clie[i].name);
            strcpy(cli.lastName,clie[i].lastName);
            strcpy(cli.domicilio,clie[i].domicilio);
            cli.sexo=clie[i].sexo;
            strcpy(cli.telefono,clie[i].telefono);
            cli.isEmpty=clie[i].isEmpty;

            break;

        }

    }

    return cli;
}

int isAvailable(Clientes* list, int len)
{
    int resul;
    int i;
    int flagFinal=0;

    for (i=0; i<len; i++)
    {
        if (list[i].isEmpty==0)
        {
            flagFinal=1;
            break;
        }
    }
    resul=i+1;
    if (flagFinal==0)
    {
        resul=1010; //Marco errro de excedido...
    }

    return resul;
}


int findClientById(Clientes* list, int len,int id)
{
    int signed resul=-1;
    int i;

    for (i=0; i<len; i++)
    {
        if (id==list[i].id && list[i].isEmpty==0)
        {
            resul=1;
            break;
        }
    }

    return resul;
}

int findRegistroClient(Clientes* list, int len,int id)
{
    int signed resul=-1;
    int i;

    for (i=0; i<len; i++)
    {
        if (id==list[i].id && list[i].isEmpty==0)
        {
            resul=i;
            break;
        }
    }

    return resul;
}

int ModificaUnCliente (Clientes* list,int len)
{
    //int i;
    int idE;
    char sex;
    char opc;
    char opcion2;
    int r;
    int r2;
    int reg;
    int flagSalida=0;
    int flagSalida4=0;
    int flagPrimeraVez=0;
    int valida_Nom;
    int valida_Ape;
    int valida_Dom;
    //int valida_Sex;
    int valida_Tel;

    Clientes cli;

    system("cls");

    r2=isAvailable(list,len);

    if (r2>len){
        r2=validaciones(r2,7);//se refiere a Reg Vacio
        flagSalida=1;
        r=-1;
        system("cls");
        return -1;
    }

    getChoiceForm("Modifica clientes",1,78);

    printClientes(list,len);

    getInt(&idE,"Ingrese Id (1-1000): ","Error Numero invalido, verifique el rango",1,1000);

    r=findClientById(list,len,idE);

    if (r<0){

        r=validaciones(r,5); //se refiere a busqueda de Empleados
        return 0;
    }
    reg=findRegistroClient(list,len,idE);

    //i=r;
    cli=llenacliente(list,cli,idE,len);
    r2=MuestraOneCliente(cli,idE,len);

    do{


        if (r2<0){
            validaciones(r2,5);
            r=-1;
            flagSalida=1;
        }

        if (flagPrimeraVez!=0){
            system("cls");
            getChoiceForm("Modifica Empleados",1,78);
            printf("\n");
            r2=MuestraOneCliente(cli,idE,len);

        }

        flagPrimeraVez=1;

        //r=MuestraUnEmployee(emp,sec,idE,len,lenSector);

        printf("\n");
//------------------------------
        printf("\nQue desea modificar?: \n");
        opc=getChar2("1-Nombre / 2-Apellido /3-Domicilio /4-Sexo /5- Telefono /6-Salir \n");

        if (opc<'1' && opc>'5'){
            continue;
        }

        switch(opc){

            case '1':

                do{
                    getString("ingrese un nombre(50): ",cli.name,51);
                    valida_Nom=esAlfaNumerico(cli.name);
                    if (valida_Nom) break;
                    printf("Contiene caracteres no permitidos, reintente... ");
                }while (valida_Nom!=1);

                continue;

            case '2':

                do{
                    getString("ingrese un apellido(50): ",cli.lastName,51);
                    valida_Ape=esAlfaNumerico(cli.lastName);
                    if (valida_Ape) break;
                    printf("Contiene caracteres no permitidos, reintente... ");
                }while (valida_Ape!=1);

                continue;

            case '3':

                do{
                    getString("ingrese Domicilio(50): ",cli.domicilio,51);
                    valida_Dom=esAlfaNumerico(cli.domicilio);
                    if (valida_Dom) break;
                    printf("Contiene caracteres no permitidos, reintente... ");
                }while (valida_Dom!=1);

                continue;

            case '4':

                do
                {
                    printf("\nIngrese Sexo(f/m): ");
                    fflush(stdin);
                    scanf("%s",&sex);
                    if (sex!='M' && sex!='m' && sex!='f' && sex!='F')
                    {
                        printf("Error en el ingreso del sexo(f/m)...reintente ");
                        continue;
                    }
                    cli.sexo=sex;
                    flagSalida4=1;
                }while (flagSalida4==0);

                continue;

            case '5':

                do{
                    getString("ingrese Telefono: ",cli.telefono,12);
                    valida_Tel=esAlfaNumerico(cli.telefono);
                    if (valida_Tel) break;
                    printf("Contiene caracteres no permitidos, reintente... ");
                }while (valida_Tel!=1);

                continue;

            case '6':
                flagSalida=1;
                break;

            default:

                getChar2("Error, Opcion erronea, vuelva a intentarlo...");
                continue;
        }
        opcion2=getChar2("\n\nDesea Guardar los Cambios? S\n");

        flagSalida=1;

        if (opcion2=='s' || opcion2=='S'){

            list[reg]=cli;
            r=1;
        }

     //--------------
     }while(flagSalida==0);

    return r;
}

Alquileres carga_Alquileres(Clientes clien[],Juegos gam[], int lenCli,int lenJue,int idAlq)
{
    int signed r;
    //int codA;
    int codJ;
    int codC;
    Fecha fecAlq;

    char descJue[60];
    float precJ;
    char nomC[51];
    char apeC[51];
    //char opcion;
    //int valida_nom;
    //int valida_ape;
    int valida_sector;

    Alquileres cargaAlqui;

    do{

        system("cls");
        getChoiceForm("Alta de Alquileres",1,78);
        printf("\nCodigo de Alquiler: %d\n",idAlq);

        printClientes(clien,lenCli);

        fflush(stdin);
        getInt(&codC,"\nIngrese Codigo de Cliente: ","Error el Cliente NO Existe ",1,lenCli);

        r=findClientById(clien,lenCli,codC);

        if(r!=1){
            printf("Error el Cliente NO Existe, reintente... \n");
            system("pause");
            continue;
        }

        r=findClienteByDesc(clien,lenCli,codC,nomC,apeC);

        printf("\nNombre y Apellido: %s %s\n",nomC,apeC);
        valida_sector=1;

     }while(valida_sector!=1);

     printJuegos(gam,lenJue);

    do{
        fflush(stdin);
        getInt(&codJ,"\nIngrese Codigo de Juego: ","Error el Codigo NO Existe ",1,5);

        precJ=findJuegoByDesc2(gam,lenJue,codJ,descJue);

        printf("\n%s %.2f",descJue,precJ);
        valida_sector=1;

     }while(valida_sector!=1);

    do{

        fflush(stdin);
        getInt(&fecAlq.dia,"\nIngrese Dia: ","error en el dia",1,31);
        fflush(stdin);
        getInt(&fecAlq.mes,"Ingrese Mes: ","error en el mes",1,12);
        fflush(stdin);
        getInt(&fecAlq.anio,"Ingrese Anio: ","error en el mes",1900,2019);        //printf("\nIngrese mes: \n");

     }while(valida_sector!=1);

        cargaAlqui.codAlquiler=idAlq;
        cargaAlqui.codCliente=codC;
        cargaAlqui.CodJuego=codJ;
        cargaAlqui.fecAlquiler=fecAlq;

    return cargaAlqui;
}

int addAlquileres(Alquileres* list, int len, int idA,int idC,int idJ,Fecha fecAlq)
{
    char res_Alta2;
    int id_reg;
    //int r=0;
    int i=0;
    int signed resul;

    id_reg=NextRegAlquilerAvailable(list,len);
    i=id_reg;

    if (i>len)
    {
        printf("Error... No hay registros disponibles para dar de Alta");
        resul=-1;
        system("pause");
    }

    res_Alta2=getChar2("\n\nPresione una tecla para Grabar / <Esc> NO GRABA");

    if (res_Alta2!=27)
    {
        list[i].codAlquiler=idA;
        list[i].codCliente=idC;
        list[i].CodJuego=idJ;
        list[i].fecAlquiler=fecAlq;
        list[i].isEmpty=0;
        resul=1;
    }
    else
    {
        getChar("\nNo fue posible dar el Alta...");
        resul=-1;
    }

return resul;
}

void insertion(Clientes data[],int len)
{
 int i,j;

 Clientes temp;

 for(i=1;i<len;i++)
 {
    temp = data[i];

    j=i-1;

        while(j>=0 && strcmp(temp.lastName,data[j].lastName)<0) // temp<data[j] o temp>data[j]
        {
             data[j+1] = data[j];
             j--;
        }
    data[j+1]=temp; // inserción
 }
}
