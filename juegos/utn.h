
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

char getChar2(char mensaje[]);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

char getChoiceForm(char titulo[],int CANT,int LENMENU);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

char getChoice(Juegos opc[],char titulo[],int CANT,int LENMENU);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int hardCord(Juegos gam[],int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int hardCord2(Clientes clie[],int len);


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int hardCord3(Alquileres alq[],int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
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


/** \brief a lo que devuelve fgets recorta el salto de carro y lo
 * cambia por '\0'
 * \param se pasa la variable por teclado a fgets
 * \param
 * \return lo que entrega fgets -1 '\0'
 *
 */

void miFgets(char array[], int tamano);

/** \brief recorta los espacios a la izquierda de una cadena de texto
 *
 * \param array_entrada cadena con dato original
 * \param array_salida cadena devuelta sin espacios iniciales
 * \return cadena devuelta sin espacios iniciales
 *
 */


void miLtrim (const char array_entrada[], char array_salida[]);

/** \brief recorta los espacios a la derecha de una cadena de texto
 *
 * \param array_entrada cadena con dato original
 * \param array_salida cadena devuelta sin espacios iniciales
 * \return cadena devuelta sin espacios al final de la cadena
 *
 */

void miRtrim (const char array_entrada[], char array_salida[]);

/** \brief recorta los espacios a la izquierda y
 *         a la derecha de una cadena de texto
 *
 * \param array_entrada cadena con dato original
 * \param array_salida cadena devuelta sin espacios iniciales
 *        ni finales
 * \return cadena devuelta sin espacios iniciales ni finales
 *
 */
void mi_Trim (const char array_entrada[], char array_salida[]);


/** \brief controla el ingreso de numeros float
 *
 * \param char mensaje1 mensaje para orientar al usuario
 * \param char mensajeError en caso de error muestra el mensaje
 * \param int minimo e int maximo validaciones
 * \return un dato float validado
 *
 */

float getFloat(float *numero,char mensaje1[],char mensajeError1[],int minimo,int maximo);


/** \brief despliega un mensaje y al presionar una tecla obtiene
 *         el valor de la misma
 * \param char mensaje a mostrar
 * \param
 * \return el valor de la tecla presionada
 *
 */

char getChar(char mensaje[]);


/** \brief despliega un mensaje y al presionar una tecla obtiene
 *         el valor de la misma
 * \param char mensaje a mostrar
 * \param
 * \return el valor de la tecla presionada
 *
 */

char getChar2(char mensaje[]);

/** \brief despliega un mensaje y espera el ingreso de un numero
 *         controla la validacion
 * \param char mensaje1 leyenda orientativa
 * \param char mensajeError1 guarda el mensaje para mostrar en caso
 *        de error
 * \return el numero solicitado
 *
 */

int getInt(int *numero,char mensaje1[],char mensajeError1[],int minimo,int maximo);


/** \brief ingreso de cadena de caracteres controla el tama�o
 *         ingresado y facilita un mensaje orientado
 * \param char mensaje mensaje a mostrar
 * \param char input variable donde guarda el valor a su salida
 * \param tamano es el tama�o maximo para la cadena
 * \return char input
 *
 */

void getString(char mensaje[],char input[],int tamano);

/** \brief es una herramienta de validacion numerica
 *
 * \param char str[] char a controlar como numerico
 * \param
 * \return -1 si no es numerico 0 si es numerico
 *
 */

int esNumerico(char str[]);

/** \brief validacion de char verifica que se hayan ingresado
 *         datos alfanumericos
 * \param char str[] dato a controlar
 * \param
 * \return -1 si existen valores no alfanumericos 0 si es asi
 *
 */

int esAlfaNumerico(char str[]);

/** \brief recorre el numero ingresado y verifica que sea realmente
 *         un numero pero ademas controla q solo haya un '.'
 * \param cha[] albrega el dato ingresado a controlar
 * \param
 * \return -1 si no es flotante 0 si es asi
 *
 */

int esNumericoFlotante(char str[]);

/** \brief herramienta para imprimir repeticiones de un caracter
 *         ejemplo hacer una linea de 78 asteriscos
 * \param char caracter es el caracter a imprimir,
 * \param can_col la cantidad de columnas
 * \param can_fila la cantidad de filas
 * \return void
 *
 */


void rellena_Espacio (char caracter,int can_col,int can_fila);

/** \brief muestra la vinculacion de dos arrays ej Empleados y
 *   sector para mostrar los empleados y la descrip de sector
 * \param Employee* list array employees
 * \param int len cantidad de elementos en el array empleados
 * \param int len2 cantidad de elementos en el array sector
 * \param int id id de empleado
 * \param char S[] array de sector
 * \return void
 *
 */

