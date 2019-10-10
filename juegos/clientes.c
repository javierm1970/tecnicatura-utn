
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "./Clientes.h"
#include "./utn.h"

#define MAX_CLIENTES 1000
#define MAX_JUEGOS 5
#define MAX_ALQUILER 2000

int initAlquileres(Alquileres* list, int len)
{
    int i;
    //int j=0;
    int signed resul=0;

    for (i=0; i<len; i++)
    {
        list[i].isEmpty=1;
        list[i].codAlquiler=0;
    }

    if (i!=len)
    {
        resul=-1;
    }

return resul;
}

int initClientes(Clientes* list, int len)
{
    int i;
    //int j=0;
    int signed resul=0;

    for (i=0; i<len; i++)
    {
        list[i].isEmpty=1;
        list[i].id=0;
    }

    if (i!=len)
    {
        resul=-1;
    }

return resul;
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

        fflush(stdin);
        getInt(&codC,"\nIngrese Codigo de Cliente: ","Error el Cliente NO Existe ",1,5);

        r=findClientById(clien,lenCli,codC);

        if(r!=1){
            printf("Error el Cliente NO Existe, reintente ");
            system("pause");
            continue;
        }

        r=findClienteByDesc(clien,lenCli,codC,nomC,apeC);

        r=validaciones(r,2);
        if (!r){
            continue;
        }
        printf("\nNombre y Apellido: %s %s\n",nomC,apeC);
        valida_sector=1;

     }while(valida_sector!=1);

    do{
        fflush(stdin);
        getInt(&codJ,"\nIngrese Codigo de Juego: ","Error el Codigo NO Existe ",1,5);

        precJ=findJuegoByDesc(gam,lenJue,codJ,descJue);

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

float findJuegoByDesc (Juegos* list,int lenJ,int idJ,char resul[])
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

//************************************************************************

Alquileres llenaAlquileres(Alquileres alqui[],Alquileres alq,int id,int len)
{
    int i;
    //int r;

    for (i=0;i<len;i++){

        if (id==alqui[i].codAlquiler)
        {
            alq.codAlquiler=alqui[i].codAlquiler;
            alq.codCliente=alqui[i].codCliente;
            alq.CodJuego=alqui[i].CodJuego;
            alq.fecAlquiler=alqui[i].fecAlquiler;

            break;

        }

    }

    return alq;
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

int ModificaUnCliente (Clientes* list,int len)
{
    int i;
    int idE;
    char sex;
    char opc;
    char opcion2;
    int r;
    int r2;
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

    getInt(&idE,"Ingrese Id (1-1000): ","Error Numero invalido, verifique el rango",1,1000);

    r=findClientById(list,len,idE);

    if (r<0){

        r=validaciones(r,5); //se refiere a busqueda de Empleados
        return 0;
    }
    i=r;

        cli=llenacliente(list,cli,idE,len);

        r2=MuestraOneCliente(cli,idE,len);

        if (r2<0){
            validaciones(r2,5);
            r=-1;
            flagSalida=1;
        }

    do{

        if (flagPrimeraVez!=0){

            system("cls");
            getChoiceForm("Modifica Empleados",1,78);
            printf("\n");
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
                    getString("ingrese Telefono: ",cli.telefono,10);
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

            list[i]=cli;
            r=1;
        }

     //--------------
     }while(flagSalida==0);

    return r;
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

void Muestra_Alquiler(Alquileres* list,Clientes* list2,Juegos* list3,
                      int lenA,int lenC,int lenJ,int idA)
{
    int i;
    char nomC[51];
    char apeC[51];
    char descJ[61];
    float *precJ;

    //int cod_Sector;

    for (i=0; i<lenC; i++)
    {
        if (list[i].codAlquiler==idA && list[i].isEmpty==0)
        {
            //cod_Sector=list[i].sector;
            break;
        }
    }

    findClienteByDesc(list2,lenC,list[i].codCliente,nomC,apeC);

    findJuegoByDesc(list3,lenJ,list[i].CodJuego,descJ);


    printf("\nCod.Alquiler       : %d",list[i].codAlquiler);
    printf("\nCod.Cliente        : %d",list[i].codCliente);
    printf("\nNombre Cli         : %s",nomC);
    printf("\nApellido cli       : %s",apeC);
    printf("\nCod.Juego          : %d",list[i].CodJuego);
    printf("\nDescr.Juego        : %s",descJ);
    printf("\nFecha              : %d/%d/%d",list[i].fecAlquiler.dia,
                                             list[i].fecAlquiler.mes,
                                             list[i].fecAlquiler.anio);

    printf("\n");
}

void Muestra_Clientes(Clientes* list,int len,int len2,int id,char S[])
{
    int i;

    //int cod_Sector;

    for (i=0; i<len; i++)
    {
        if (list[i].id==id && list[i].isEmpty==0)
        {
            //cod_Sector=list[i].sector;
            break;
        }
    }

    printf("\nId                 : %d",list[i].id);
    printf("\nNombre             : %s",list[i].name);
    printf("\nApellido           : %s",list[i].lastName);
    printf("\nDomicilio          : %s",list[i].domicilio);
    printf("\nSexo               : %c",list[i].sexo);
    printf("\nId                 : %s",list[i].telefono);
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
    int i;
    char opc;
    int r=0;
    int r2=0;
    int flagSalida=0;
    int idE;

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

        r2=getInt(&idE,"Ingrese Id (1-1000): ","Error Numero invalido, verifique el rango",1,1000);

        r=findClientById(list,len,idE);

        if (r<0){

            r=validaciones(r,5); //se refiere a busqueda de Empleados
            continue;
        }
        i=r;

        cli=llenacliente(list,cli,idE,len);

        r2=MuestraOneCliente(cli,idE,len);

        if (r2<0){
            validaciones(r2,5);
            r=-1;
            flagSalida=1;
        }

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
                list[i].isEmpty=1;
                getChar2("\n\nEl Registro ha sido borrado, una tecla para continuar");
                r=0;
                break;
            }
            r=0;
            flagSalida=1;

        }

    }while(flagSalida==0);

 return r;
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


int printOneJuego(int codJ,char descJ[],float preJ)
{
    //int r;
/*
    if (r==-1){
        strcpy(descrip,"sector no encontrado");
    }
*/
    printf("\n\t%d \t%s \t%.2f ",codJ,descJ,preJ);

    return 1;
}

int printJuegos(Juegos* list,int lenJ)
{
    int i;
    //int r;

    printf("\n\tCod J \tDesc J \t\t\tPrecio \n");
    rellena_Espacio('-',78,1);

    for (i=0;i<lenJ;i++)
    {
        printOneJuego(list[i].id,list[i].descripcion,list[i].precio);
    }

 printf("\n\n");
 return 0;
}

int printOneCliente(int codC,char nomC[],char apeC[],char domC[],char sex,char telefC[])
{
    //int r;

    printf("\n\t%d \t%s \t%s \t%s \t%c \t%s ",codC,nomC,apeC,domC,sex,telefC);

    return 1;
}

int printClientes(Clientes* list,int lenC)
{
    int i;
    //int r;

    printf("\n\tCod C \tNomC \tApeC \tDom C \tSexo \tTelef \n");
    rellena_Espacio('-',78,1);

    for (i=0;i<lenC;i++)
    {
        if (list[i].isEmpty!=1 && list[i].id!=0)
        {
            printOneCliente(list[i].id,list[i].name,list[i].lastName,
                            list[i].domicilio,list[i].sexo,list[i].telefono);
        }


    }

 printf("\n\n");
 return 0;
}

int printOneAlquiler(int codA,Fecha fecA,int codC,int codJ,char nomC[],char apeC[],char descJ[],float preJ)
{
    //int r;

    printf("\n%d %d %d  \t%d \t%d \t%s \t%s \t%d \t%s %.2f",fecA.dia,fecA.mes,fecA.anio,
           codA,codC,nomC,apeC,codJ,descJ,preJ);

    return 1;
}

/*
int sortEmployees(Employee* list2,int len, int order)

{
    int i;
    int j;
    int res=-1;

    Employee emp;

    if(order==1)
    {
        for(i=0; i<len-1; i++)
        {
            if (list2[i].isEmpty==1)
            {
                continue;
            }
                for(j=i+1; j<len; j++)
                {

                    if (strcmp(list2[i].lastName,list2[j].lastName)<0)
                    {
                        emp=list2[i];
                        list2[i]=list2[j];
                        list2[j]=emp;
                    }

                    if (strcmp(list2[i].lastName,list2[j].lastName)==0)
                    {
                        if (list2[i].sector<list2[j].sector)
                        {
                        emp=list2[i];
                        list2[i]=list2[j];
                        list2[j]=emp;

                        }


                    }

                }

        }

    }
    else
    {
        for(i=0; i<len-1; i++)
        {
            if (list2[i].isEmpty==1)
            {
                continue;
            }
                for(j=i+1; j<len; j++)
                {

                    if (strcmp(list2[i].lastName,list2[j].lastName)>0)
                    {
                        emp=list2[i];
                        list2[i]=list2[j];
                        list2[j]=emp;
                    }

                    if (strcmp(list2[i].lastName,list2[j].lastName)==0)
                    {
                        if (list2[i].sector>list2[j].sector)
                        {
                        emp=list2[i];
                        list2[i]=list2[j];
                        list2[j]=emp;

                        }
                    }
                }
        }
    }
    return res;
}
*/

int printAlquileresC(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ)
{
    int i;
    int r;
    char nomC[51];
    char apeC[51];
    char descJ[60];
    //float precJ;

    int codJu2;

    //printClientes(list2,lenJ);

    printf("ingrese un cliente");
    scanf("%d",&codJu2);


    printf("\tNom \tApe\n");
    rellena_Espacio('-',78,1);
    printf("\n");


    for (i=0;i<lenA;i++)
    {

        if (list[i].codCliente==codJu2)
        {
            printf("%d    %d   %d",i,list[i].codCliente,codJu2);system("pause");
            //r=findClienteByDesc(list2,lenC,list[i].codAlquiler,nomC,apeC);
            //precJ=findJuegoByDesc(list3,lenJ,list[i].CodJuego,descJ);
            findJuegoByDesc(list3,MAX_JUEGOS,list[i].CodJuego,descJ);
            printf("%s \t%s\n",list[i].CodJuego,descJ);


            //printClientes(list2,lenC);

            //printOneAlquiler(list[i].codAlquiler,list[i].fecAlquiler,
            //                 list[i].codCliente,list[i].CodJuego,nomC,apeC,descJ,precJ);

        }

    }

 printf("\n\n");
 system("pause");
 return 0;
}

int printAlquileresJ(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ)
{
    int i;
    int r;
    char nomC[51];
    char apeC[51];
    char descJ[61];
    float precJ;

    int codJu2;

    printJuegos(list3,lenJ);

    printf("ingrese un juego");
    scanf("%d",&codJu2);


    printf("\tNom \tApe\n");
    rellena_Espacio('-',78,1);
    printf("\n");
    for (i=0;i<lenA;i++)
    {

        if (list[i].CodJuego==codJu2)
        {
            r=findClienteByDesc(list2,lenC,list[i].codAlquiler,nomC,apeC);

            printf("%s \t%s\n",nomC,apeC);

            //precJ=findJuegoByDesc(list3,lenJ,list[i].CodJuego,descJ);
            //printClientes(list2,lenC);
            /*
            printOneAlquiler(list[i].codAlquiler,list[i].fecAlquiler,
                             list[i].codCliente,list[i].CodJuego,nomC,apeC,descJ,precJ);
        */
        }

    }

 printf("\n\n");
 system("pause");
 return 0;
}

int printAlquileres(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ)
{
    int i;
    int r;
    char nomC[51];
    char apeC[51];
    char descJ[61];
    float precJ;

    printf("\nFecha \t\tCod A \tCod C \tNom \tApe \tCod J \tDes J      \tPrecio \n");
    rellena_Espacio('-',78,1);

    for (i=0;i<lenA;i++)
    {

        if (list[i].isEmpty!=1 && list[i].codAlquiler!=0)
        {
            r=findClienteByDesc(list2,lenC,list[i].codAlquiler,nomC,apeC);
            precJ=findJuegoByDesc(list3,lenJ,list[i].CodJuego,descJ);
            printOneAlquiler(list[i].codAlquiler,list[i].fecAlquiler,
                             list[i].codCliente,list[i].CodJuego,nomC,apeC,descJ,precJ);
        }
    }

 printf("\n\n");
 return 0;
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
    float precJ;
    char descJ[61];

    for (i=0;i<=len;i++)
    {
        if(list[i].isEmpty==0)
        {
            precJ=findJuegoByDesc(list3,lenJ,list[i].CodJuego,descJ);

            prom = prom + precJ;
            cantCli++;

        }
    }
    promedio=prom/cantCli;
    printf("\n\n\n");
    printf("\nEl promedio de todos los Juegos Alquilados es: %2.f \n",promedio);
    printf("\nLa suma de todos los Juegos es: %2.f \n",prom);

/*
    for (j=0;j<=len;j++)
    {
        if (list[j].isEmpty==0)
        {
            precJ=findJuegoByDesc(list3,lenJ,list[i].CodJuego,descJ);

            if (precJ<promedio)
            {
                supProm++;
            }
        }
    }

    printf("\nLa cantidad de empleados que supera el salario promedio es: %d \n\n\n",supProm);
    printf("\n\n\n");
    res=0;
*/
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
    float precJ;
    char descJ[61];

     for (i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            precJ=findJuegoByDesc(list3,lenJ,list[i].CodJuego,descJ);

            prom = prom + precJ;
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

void bubbleSort (Juegos* list ,int len)
{
    int j;

    Juegos aux;

    int flagNoEstaOrdenado = 1;

    while (flagNoEstaOrdenado==1)
    {

      flagNoEstaOrdenado = 0;

        for (j = 1; j < len; j++)
	    {
            //if(list[j].precio < list[j-1].precio)
            if(list[j].precio > list[j-1].precio)
	        {

                aux = list[j];
                list[j] = list[j - 1];
                list[j - 1] = aux;

                flagNoEstaOrdenado = 1;
            }
        }
    }





 }
void insertion(int data[],int len)
{
 int i,j;
 int temp;

 for(i=1;i<len;i++)
 {
    temp = data[i];

    j=i-1;

        while(j>0 && temp>data[j]) // temp<data[j] o temp>data[j]
        {
             data[j+1] = data[j];
             j--;
        }
    data[j+1]=temp; // inserci�n
 }
}