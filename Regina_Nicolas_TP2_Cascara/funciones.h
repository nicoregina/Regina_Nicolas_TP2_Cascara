#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
 * Estructura de personas ingresadas
 */
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long dni;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int cant);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int cant, long dni);

/**
 * Ingresa un nuevo elemento en la lista
 * @param lista el array se pasa como parametro, int cant de elementos en el array.
 */
void alta(ePersona[], int);

/**
 * inhabilita un elemento de la lista
 * @param lista el array se pasa como parametro, int cant de elementos en el array.
 */
void baja(ePersona[], int);

/**
 * modifica un elemento de la lista
 * @param lista el array se pasa como parametro, int cant de elementos en el array.
 */
void modificar(ePersona[], int);

/**
 * Lista los elementos en la lista
 * @param lista el array se pasa como parametro, int cant de elementos en el array.
 */
void listar(ePersona[], int);

/**
 * Ordena los elementos de la lista
 * @param lista el array se pasa como parametro, int cant de elementos en el array.
 */
void ordenar(ePersona[], int);

/**
 * inicializa en estado 0(sin datos) todos los elementos de la lista
 * @param lista el array se pasa como parametro, int cant de elementos en el array.
 */
void init(ePersona[], int);

/**
 * crea un grafico con las edades de los elementos de la lista
 * @param lista el array se pasa como parametro, int cant de elementos en el array.
 */
void listarGrafico(ePersona[], int);

/**
 * ingresa datos hardcodeados en cada elemento de la lista para pruebas
 * @param lista el array se pasa como parametro, int cant de elementos en el array.
 */
void hardCode(ePersona per[]);


#endif // FUNCIONES_H_INCLUDED
