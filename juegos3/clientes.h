typedef struct
{
    int anio;
    int mes;
    int dia;

}Fecha;

typedef struct
{
int id;
char name[51];
char lastName[51];
char domicilio[51];
char sexo;
char telefono[12];
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



int validaciones(int signed codigo,int codFun);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int NextRegClienteAvailable(Clientes* list, int len);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int NextRegAlquilerAvailable(Alquileres* list, int len);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int findNextId(Alquileres list[], int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int findNextIdClientes(Clientes* list, int len);

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
Clientes findClienteByDesc2 (Clientes* list,int lenC,int idC);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
Juegos findJuegoByDesc (Juegos* list,int lenJ,int idJ);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int MuestraOneCliente (Clientes clie,int id,int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void MuestraAlquiler(Alquileres* list,Clientes* list2,Juegos* list3,
                      int lenA,int lenC,int lenJ);

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
int printOneAlquiler(Alquileres alquil,char nomC[],char apeC[],char descJ[],float preJ);

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

int printOneCliente(Clientes cli);

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
 void bubbleSortAlqFecha (Alquileres* list ,int len);

 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */
  int PromedioJuegos(Alquileres* list,Juegos* list3, int len,int lenJ);

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
 int JuegosMenosAlquilados(Alquileres* list,Juegos* list3, int len,int lenJ);


 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

void bubbleSortCodJuegos (Juegos* list ,int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
 int ClienteMasAlquila(Alquileres* list,Clientes* list3, int lenA,int lenC);

 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int AlquileresPorCliente(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int AlquileresPorJuego(Alquileres* list,Clientes* list2,Juegos* list3,int lenA,int lenC,int lenJ);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
