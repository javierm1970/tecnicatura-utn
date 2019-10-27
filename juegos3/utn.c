#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "clientes.h"
#include "utn.h"


int hardCord(Juegos gam[],int len)
{
    int res=0;
    int i;

            Juegos aux1[5]={{1,"pelotero      ",100.52},
                            {2,"metegol       ",200.51},
                            {3,"pool          ",300.57},
                            {4,"flipper       ",400.72},
                            {5,"infla Vs.     ",500.83}};

    for (i=0;i<len;i++){

         gam[i]=aux1[i];
    }

    return res;
}

int hardCord2(Clientes client[],int len)
{
    int res=0;
    int i;

            Clientes aux1[29]={{1,"nom1","ape1","dom1",'f',"1111111111",0},
                               {2,"nom2","ape2","dom2",'f',"2211111111",0},
                               {3,"nom3","ape3","dom3",'m',"3311111111",0},
                               {4,"nom3","ape6","dom4",'m',"4411111111",0},
                               {5,"nom3","ape4","dom5",'m',"5511111111",0},
                               {6,"nom3","ape5","dom6",'f',"6611111111",0},
                               {7,"nom7","ape7","dom7",'f',"7711111111",0},
                               {8,"nom8","ape8","dom8",'m',"8811111111",0},
                               {9,"nom9","ape9","dom9",'f',"1111111111",0},
                               {10,"nom10","ape10","dom10",'f',"1111111111",0},
                               {11,"nom11","ape11","dom11",'f',"1111111111",0},
                               {12,"nom12","ape12","dom12",'f',"2211111111",0},
                               {13,"nom13","ape13","dom13",'m',"3311111111",0},
                               {14,"nom14","ape14","dom14",'m',"4411111111",0},
                               {15,"nom15","ape15","dom15",'m',"5511111111",0},
                               {16,"nom16","ape16","dom16",'f',"6611111111",0},
                               {17,"nom17","ape17","dom17",'f',"7711111111",0},
                               {18,"nom18","ape18","dom18",'m',"8811111111",0},
                               {19,"nom19","ape19","dom19",'f',"1111111111",0},
                               {20,"nom20","ape20","dom20",'f',"1111111111",0},
                               {21,"nom21","ape21","dom21",'f',"1111111111",0},
                               {22,"nom22","ape22","dom22",'f',"2211111111",0},
                               {23,"nom23","ape23","dom23",'m',"3311111111",0},
                               {24,"nom24","ape24","dom24",'m',"4411111111",0},
                               {25,"nom25","ape25","dom25",'m',"5511111111",0},
                               {26,"nom26","ape26","dom26",'f',"6611111111",0},
                               {27,"nom27","ape27","dom27",'f',"7711111111",0},
                               {28,"nom28","ape28","dom28",'m',"8811111111",0},
                               {29,"nom29","ape29","dom29",'f',"1111111111",0}};

    for (i=0;i<len;i++){

        if (i < 30){

            client[i]=aux1[i];
        }
        else
        {
            client[i].isEmpty=1;
        }


    }

    return res;
}

int hardCord3(Alquileres alq[],int len)
{
    int res=0;
    int i;

            Alquileres aux1[29]={{1,14,2,{1900,1,1},0},
                                 {2,14,4,{1920,2,1},0},
                                 {3,14,5,{1930,3,1},0},
                                 {4,1,4,{1930,4,1},0},
                                 {5,2,5,{1930,5,1},0},
                                 {6,16,3,{1940,1,1},0},
                                 {7,26,3,{1940,6,1},0},
                                 {8,2,3,{1950,7,2},0},
                                 {9,29,3,{1950,9,3},0},
                                 {10,3,4,{1950,9,24},0},
                                 {11,13,3,{1900,10,7},0},
                                 {12,23,4,{1920,11,13},0},
                                 {13,14,2,{1930,11,9},0},
                                 {14,3,4,{1930,1,1},0},
                                 {15,4,3,{1930,12,24},0},
                                 {16,18,3,{1940,12,31},0},
                                 {17,17,3,{1940,6,15},0},
                                 {18,14,3,{1950,1,21},0},
                                 {19,5,4,{1950,1,21},0},
                                 {20,16,1,{1952,1,21},0},
                                 {21,15,1,{1900,1,21},0},
                                 {22,25,4,{1920,12,8},0},
                                 {23,4,4,{1930,1,30},0},
                                 {24,6,3,{1930,1,21},0},
                                 {25,16,4,{1930,11,1},0},
                                 {26,6,3,{1940,11,11},0},
                                 {27,3,3,{1940,12,28},0},
                                 {28,27,3,{1950,5,3},0},
                                 {29,7,3,{1950,11,1},0}};

    for (i=0;i<len;i++){

        if (i < 30){

            alq[i]=aux1[i];
        }
        else
        {
            alq[i].isEmpty=1;
        }


    }



    return res;
}

void miFgets(char array[], int tamano)
{

    int cant=0;
    fflush(stdin);

    fgets(array, tamano, stdin);

    cant = strlen(array);
    array[cant-1] = '\0';

}

char getChar2(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    auxiliar=getch();
    return auxiliar;
}
void miPausa(char mensaje[])
{
    printf("\n");
    getChar2(mensaje);
    printf("\n");
}

void miCls(void)
{
    system("cls");
}
void miFflush(void)
{
    fflush(stdin);
}

/*
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
*/
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

//*******************************************

void miTrimCamelLowerCase (const char array_entrada[], char array_salida[])
{
    int i;
    int j=0;
    int inicioCadena=0;
    int tamano=strlen(array_entrada);
    char aux[tamano];
    char aux2[tamano];

    strcpy(aux2,array_entrada);
    strlwr(aux2);
    //Empieza Ltrim
    miLtrim(aux2,aux2);
    //Empieza Rtrim
    miRtrim(aux2,aux2);
    //Empieza quitar los espacio en medio

    aux[0]='\0';
    inicioCadena=0;
    j=0;

    for (i=0; aux2[i]!='\0' ; i++)
    {
        if (inicioCadena==0)
        {
            aux[j] = toupper(aux2[i]);
            j++;
            inicioCadena = 1;
        }
        else if (aux2[i]!=' ' && aux2[i-1]== ' ')
        {

            aux[j] = toupper(aux2[i]);
            j++;
        }
        else if (aux2[i]!=' ' || aux2[i-1]!= ' ')
        {
            aux[j] = aux2[i];
            j++;
        }

    }
    aux[j++]='\0';
    strcpy(array_salida,aux);
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

void miTrim (const char array_entrada[], char array_salida[])
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
        printf("%s",mensajeError1);
    }

    *numero=num;
    return resultado;
}

void rellena_Espacio (char caracter,int can_col,int can_fila)
{
    int i=0;
    int j;

    for (i=0; i<can_fila; i++)
    {
        for (j=0; j<can_col; j++)
        {
            printf("%c",caracter);
        }
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

int getInt(int *numero,char mensaje1[],char mensajeError1[],int minimo,int maximo)
{
    int num;
    //int cant;
    int flagSalida=0;
    int signed resultado=-1;

    printf("%s",mensaje1);
    while(flagSalida==0)
    {

        fflush(stdin);
        if (scanf("%d",&num)==1)
        {
            if (num >= minimo && num <= maximo)
            {
                    resultado=1;
                    break;
            }
        }
        printf("\n%s\n",mensajeError1);
        system("pause");
        break;
    }

    *numero=num;
    return resultado;
}

void getString(char mensaje[],char input[],int tamano)
{
    int r;
    int flagSalida=0;

    do{

        printf("%s",mensaje);
        fflush(stdin);
        miFgets(input,tamano);

        if (strlen(input)<0 ||strlen(input)>tamano){
            printf("Tamano excedigo... reintente\n");
            continue;
        }
        r=esAlfaNumerico(input);
        if (r!=1){
            printf("Ingreso Caracteres no Validos... reintente\n");
            continue;
        }

        flagSalida=1;

    }while (flagSalida==0);

    //scanf ("%[^\n]s", input);
}

int esNumerico(char str[])
{
    int i=0;
    int resultado=1;
    int cant = strlen(str);

    for(i=0; i<cant; i++)
        {
            if(!isdigit(str[i]))
            {
                resultado=-1;
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
/*
int initData(Clientes list[], int lenData)
{
    int i;
    int resul=1;

    for (i=0; i<lenData; i++)
    {
        list[i].isEmpty=1;
    }

    if (i!=lenData)
    {
        resul=-1;
    }
    return resul;
}


*/

int fechaParaOrdenar(int anio,int mes,int dia)
{
    int fechaO;

    fechaO=(anio*10000)+(mes*100)+dia;

  return fechaO;
}

int FechasParaSort(char fechasV[],int lenF)
{
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    int r=-1;
    char diaV[3]={'0','0','\0'};
    char mesV[3]={'0','0','\0'};
    char anioV[5]={'0','0','0','0','\0'};
    int fechaO;

    if (strlen(fechasV)>lenF)
    {
        r=-1;
    }
    else
    {
        for (i=0; i<10; i++)
            {
                if (!isdigit(fechasV[i]))
                {
                    r=-1;
                    break;
                }
                if (i>=0 && i<2)
                {
                    diaV[j]=fechasV[i];
                    j++;
                }
                if (i>=2 && i<4)
                {
                    mesV[k]=fechasV[i];
                    k++;
                }
                if (i>=4 && i<8)
                {
                    anioV[l]=fechasV[i];
                    l++;
                }
            }
    }
    //printf("%s/%s/%s",diaV,mesV,anioV);system("pause");
    if (atoi(diaV)>29 && atoi(mesV)!=2){
        return -1;
    }
    if (!(atoi(diaV)>0 && atoi(diaV)<=31)){
        return -1;
    }
    if (atoi(diaV)==30 && (atoi(mesV)!=4 && atoi(mesV)!=6 && atoi(mesV)!=9 && atoi(mesV)!=11)){
        return -1;
    }
    if (!(atoi(mesV)>0 && atoi(mesV)<=12)){
        return -1;
    }
    /*
    if (!(atoi(anioV)>=minAnio && atoi(anioV)<=maxAnio)){
        return -1;
    }
    */

    fechaO=((atoi(anioV)*10000)+(atoi(mesV)*100)+(atoi(diaV)));
    r=fechaO;

return r;

}

int validaFechas(char fechasV[],int lenF,int minAnio, int maxAnio)
{
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    int r=-1;

    char diaV[3]={'0','0','\0'};
    char mesV[3]={'0','0','\0'};
    char anioV[5]={'0','0','0','0','\0'};

    if (strlen(fechasV)>lenF)
    {
        r=-1;
    }
    else
    {
        for (i=0; i<10; i++)
            {
                if (!isdigit(fechasV[i]))
                {
                    r=-1;
                    break;
                }
                if (i>=0 && i<2)
                {
                    diaV[j]=fechasV[i];
                    j++;
                }
                if (i>=2 && i<4)
                {
                    mesV[k]=fechasV[i];
                    k++;
                }
                if (i>=4 && i<8)
                {
                    anioV[l]=fechasV[i];
                    l++;
                }
            }
    }
    //printf("%s/%s/%s",diaV,mesV,anioV);system("pause");
    if (atoi(diaV)>29 && atoi(mesV)!=2){
        return -1;
    }
    if (!(atoi(diaV)>0 && atoi(diaV)<=31)){
        return -1;
    }
    if (atoi(diaV)==30 && (atoi(mesV)!=4 && atoi(mesV)!=6 && atoi(mesV)!=9 && atoi(mesV)!=11)){
        return -1;
    }
    if (!(atoi(mesV)>0 && atoi(mesV)<=12)){
        return -1;
    }
    if (!(atoi(anioV)>=minAnio && atoi(anioV)<=maxAnio)){
        return -1;
    }
    r=1;

return r;

}

