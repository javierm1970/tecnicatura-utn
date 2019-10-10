
typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;



typedef struct
{
int id;
char name[51];
char lastName[51];
char domicilio[51];
char sexo;
char telefono[10];
int isEmpty;

}Clientes;

typedef struct
{
int id;
char descripcion[60];
float precio;

}Juegos;

typedef struct
{
int codAlquiler;
int codCliente;
int CodJuego;
Fecha fecAlquiler;
int isEmpty;

}Alquileres;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


 int initAlquileres(Alquileres* list, int len);

 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */


int initClientes(Clientes* list, int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

Clientes carga_Clientes(Clientes cli3,int len,int id);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

Alquileres carga_Alquileres(Clientes clie[],Juegos gam[], int lenCli,int lenJue,int idAlq);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int findClienteByDesc (Clientes* list,int lenC,int idC,char resul[],char resul2[]);




/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

float findJuegoByDesc (Juegos* list,int lenC,int idJ,char resul[]);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int ModificaUnCliente (Clientes* list,int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int findClientById (Clientes* list, int len,int id);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void Muestra_Clientes(Clientes* list,int len,int len2,int id,char S[]);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int addCliente(Clientes* list, int len, int id, char name[],char lastName[],
                               char domicilio[],char sexo,char telefono[]);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int addAlquileres(Alquileres* list, int len, int idA,int idC,int idJ,Fecha fecAlq);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void Muestra_Alquiler(Alquileres* list,Clientes* list2,Juegos* list3,
                      int lenA,int lenC,int lenJ,int idA);


/** \brief
*
* \param
* \param
* \return
*
*/
int removeCliente(Clientes* list,int len);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

Clientes llenacliente(Clientes clie[],Clientes cli,int id,int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int MuestraOneCliente (Clientes clie,int id,int len);

/** \brief verifica si hay registros disponibles o si el registro esta vacio
 *
 * \param
 * \param
 * \return
 *
 */

int isAvailable(Clientes* list, int len);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int printOneAlquiler(int codA,Fecha fecA,int codC,int codJ,char nomC[],char apeC[],char descJ[],float preJ);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int printAlquileres(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int printOneJuego(int codJ,char descJ[],float preJ);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int printJuegos(Juegos* list,int lenJ);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int printOneCliente(int codC,char nomC[],char apeC[],char domC[],char sex,char telefC[]);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int printClientes(Clientes* list,int lenC);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int PromedioJuegos(Alquileres* list,Juegos* list3, int len,int len2);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int PromedioJuegos2(Alquileres* list,Juegos* list3, int len,int lenJ);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void bubbleSort (Juegos* list ,int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void insertion(int data[],int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int printAlquileresJ(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int printAlquileresC(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ);
