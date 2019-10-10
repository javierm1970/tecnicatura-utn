

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


char getChar2(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    auxiliar=getch();
    return auxiliar;
}
char getChoice(Juegos opc[],char titulo[],int CANT,int LENMENU)
{
    char auxiliar;
    int i;
    int margen;
    int margen2;

    margen=((LENMENU-2)-(strlen(titulo)))/2;

    rellena_Espacio('*',LENMENU,1);
    printf("\n");

    rellena_Espacio('*',margen,1);
    printf(" %s ",titulo);
    rellena_Espacio('*',margen,1);

    printf("\n");
    rellena_Espacio('*',LENMENU,1);
    printf("\n");

        for (i=0; i<CANT; i++)
        {
            margen2=((LENMENU-4)-(strlen(opc[i].descripcion)))/2;
            rellena_Espacio('*',margen2,1);
            printf("   %s  ",opc[i].descripcion);
            rellena_Espacio('*',margen2,1);
            printf("\n");

        }
    rellena_Espacio('*',LENMENU,1);
    printf("\n");
    rellena_Espacio('*',LENMENU,1);
    printf("\n");

    fflush(stdin);
    auxiliar=getChar2("\nIngrese una Opcion / <Esc> Salir ");

    return auxiliar;
}

char getChoiceForm(char titulo[],int CANT,int LENMENU)
{

    int margen;

    margen=((LENMENU-2)-(strlen(titulo)))/2;

    rellena_Espacio('*',LENMENU,1);
    printf("\n");

    rellena_Espacio('*',margen,1);
    printf(" %s ",titulo);
    rellena_Espacio('*',margen,1);

    printf("\n");
    rellena_Espacio('*',LENMENU,1);
    printf("\n");

    return 0;
}

int hardCord(Juegos gam[],int len)
{
    int res=0;
    int i;

            Juegos aux1[5]={{1,"1-pelotero      ",100.50},
                            {2,"2-metegol       ",200.50},
                            {3,"3-pool          ",300.50},
                            {4,"4-flipper       ",400.50},
                            {5,"5-infla Vs.     ",500.50}};

    for (i=0;i<len;i++){

         gam[i]=aux1[i];
    }

    return res;
}

int hardCord2(Clientes clie[],int len)
{
    int res=0;
    int i;

            Clientes aux1[9]={{1,"nom1","ape1","dom1",'f',"1111111111",0},
                              {2,"nom2","ape2","dom2",'f',"2211111111",0},
                              {3,"nom3","ape3","dom3",'m',"3311111111",0},
                              {4,"nom4","ape4","dom4",'m',"4411111111",0},
                              {5,"nom5","ape5","dom5",'m',"5511111111",0},
                              {6,"nom6","ape6","dom6",'f',"6611111111",0},
                              {7,"nom7","ape7","dom7",'f',"7711111111",0},
                              {8,"nom8","ape8","dom8",'m',"8811111111",0},
                              {9,"nom9","ape9","dom9",'f',"1111111111",0}};



    for (i=0;i<9;i++){

         clie[i]=aux1[i];
    }

    return res;
}

int hardCord3(Alquileres alq[],int len)
{
    int res=0;
    int i;

            Alquileres aux1[10]={{1,5,1,{1,1,1900},0},
                                 {2,2,1,{1,1,1920},0},
                                 {3,1,2,{1,1,1930},0},
                                 {4,3,2,{1,1,1930},0},
                                 {5,5,2,{1,1,1930},0},
                                 {6,4,3,{1,1,1940},0},
                                 {7,5,3,{1,1,1940},0},
                                 {8,7,3,{1,1,1950},0},
                                 {9,9,3,{1,1,1950},0},
                                 {10,5,5,{1,1,1950},0}};


    for (i=0;i<10;i++){

         alq[i]=aux1[i];
    }

    return res;
}

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
//*******************************************


void miFgets(char array[], int tamano)
{

    int cant=0;
    fflush(stdin);

    fgets(array, tamano, stdin);

    cant = strlen(array);
    array[cant-1] = '\0';

}

void miLtrim (const char array_entrada[], char array_salida[])
{
    int i,j=0,inicioCadena=0;
    int tamano=strlen(array_entrada);
    char aux[tamano];
    aux[0]='\0';

    for (i=0; array_entrada[i]!='\0' ; i++)
    {

        if (array_entrada[i]!=' ' || inicioCadena !=0)
            {
                aux[j] = array_entrada[i];
                j++;
                inicioCadena = 1;
            }
    }

    aux[j++]='\0';
    strcpy(array_salida,aux);
}

void miRtrim (const char array_entrada[], char array_salida[])
{
    int i;
    int tamano=strlen(array_entrada);

    for (i=tamano; i>=0 ; i--)
    {
        if (array_entrada[i]!=' ' && array_entrada[i]!='\0' )
            {
                array_salida[i+1] = '\0';
                break;
            }
    }
}

void mi_Trim (const char array_entrada[], char array_salida[])
{
    int i,j=0,inicioCadena=0;
    int tamano=strlen(array_entrada);
    char aux[tamano];

    //Empieza Ltrim
    for (i=tamano; i>=0 ; i--)
    {
        if (array_entrada[i]!=' ' && array_entrada[i]!='\0' )
            {
                array_salida[i+1] = '\0';
                break;
            }
    }
    //Empieza Rtrim

    aux[0]='\0';

    for (i=0; array_entrada[i]!='\0' ; i++)
    {
        if (array_entrada[i]!=' ' || inicioCadena !=0)
            {
                aux[j] = array_entrada[i];
                j++;
                inicioCadena = 1;
            }
    }
    aux[j++]='\0';
    strcpy(array_salida,aux);

    //Empieza quitar los espacio en medio

    aux[0]='\0';
    inicioCadena=0;
    j=0;

    for (i=0; array_entrada[i]!='\0' ; i++)
    {
        if (inicioCadena==0)
        {
            aux[j] = array_entrada[i];
            j++;
            inicioCadena = 1;

        } else if (array_entrada[i]!=' ' || array_entrada[i-1]!= ' ')
            {
                aux[j] = array_entrada[i];
                j++;
            }
    }
    aux[j++]='\0';
    strcpy(array_salida,aux);
}


float getFloat(float *numero,char mensaje1[],char mensajeError1[],int minimo,int maximo)
{
    float num;
    //int cant;
    int flagSalida=0;
    int resultado=0;

    printf("%s",mensaje1);
    while(flagSalida==0)
    {

        fflush(stdin);
        if (scanf("%f",&num)==1)
        {
            if (num >= minimo && num <= maximo)
            {
                    break;
            }
        }
        //fflush(stdin); //EN LINUX UTILIZAR __fpurge(stdin)
        printf("%s",mensajeError1);
    }

    *numero=num;
    return resultado;

}

void rellena_Espacio (char caracter,int can_col,int can_fila)
{
    int i=0;
    int j;

    //printf("\n");

    for (i=0; i<can_fila; i++)
    {
        for (j=0; j<can_col; j++)
        {
            printf("%c",caracter);
        }
    //printf("\n");
    }

}


char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

/*
char getChar2(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    auxiliar=getch();
    return auxiliar;
}
*/
int getInt(int *numero,char mensaje1[],char mensajeError1[],int minimo,int maximo)
{
    int num;
    //int cant;
    int flagSalida=0;
    int resultado=0;

    printf("%s",mensaje1);
    while(flagSalida==0)
    {

        fflush(stdin);
        if (scanf("%d",&num)==1)
        {
            if (num >= minimo && num <= maximo)
            {
                    break;
            }
        }
        printf("%s",mensajeError1);
    }

    *numero=num;
    return resultado;
}

void getString(char mensaje[],char input[],int tamano)
{
    printf("%s",mensaje);
    fflush(stdin);
    miFgets(input,tamano);

    //scanf ("%[^\n]s", input);
}

int esNumerico(char str[])
{
    int i=0;
    int resultado=0;
    int cant = strlen(str);

    for(i=0; i<cant; i++)
        {
            if(!isdigit(str[i]))
            {
                resultado=1;
                break;
            }
        }

return resultado;
}

int esNumericoFlotante(char str[])
{
    int i=0;
    int resultado=1;
    int cant = strlen(str);
    int cantPunto=0;

    for(i=0; i<cant; i++)
        {
            if (str[i]!='.')
            {
                if(!isdigit(str[i]))
                {
                    resultado=0;
                    break;
                }
             }
             else
             {
                 cantPunto++;
                 if (cantPunto>1)
                 {
                    resultado=0;
                    break;
                 }
             }
        }

return resultado;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}
