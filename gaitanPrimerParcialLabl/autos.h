#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED
#include "marcas.h"
#include "colores.h"
#include "clientes.h"



typedef struct
{
    int id;
    char patente[6];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
    int idCliente;
    int idSuciedad;


}eAuto;


#endif // AUTOS_H_INCLUDED


/** \brief Inicializa al array de autos modificando su campo isEmpty a 1
 *
 * \param lista de autos
 * \param  tamaño del array
 *
 */


void inicializarAutos(eAuto* listaAutos, int tamAutos);


/** \brief Busca el primer lugar del array que tiene isEmpty 1
 *
 * \param lista de autos
 * \param  tamaño del array
 * \return (-1) si no encontro
           (indice) si encontro
 *
 */


int buscarLibreAuto(eAuto* listaAutos, int tamAutos);


/** \brief busca el auto ingresando la patente previamente
 *
 * \param  patente a buscar
 * \param  tamaño del array
 * \return (-1) si no encontro coincidencias
 *          (indice) si encontro coincidencia entre la patente ingresada y alguna del array
 */


int buscarAutoPorPatente(eAuto* listaAutos, char* patente, int tamAutos);

/** \brief da de alta a un nuevo auto
 *
 * \param lista de autos
 * \param id del auto a ingresar
 * \param tamaño del array
 * \param lista de marcas
 * \param tamaño del array de marcas
 * \param lista de colores
 * \param tamaño del array de colores
 * \return (0) si hay error
 *         (1) si fue exitosa el alta
 */


int altaAuto(eAuto* listaAutos, int idAutos, int tamAutos, eMarca* listaMarcas, int tamMarcas, eColor* listaColores, int tamColores,eCliente* listaClientes, int tamClientes);

/** \brief modificar un auto ya cargado
 *
 * \param lista de autos
 * \param id del auto a modificar
 * \param tamaño del array de autos
 * \param lista de marcas
 * \param tamaño del array de marcas
 * \param lista de colores
 * \param tamaño del array de colores
 * \return (0) si hay error
 *         (1) si fue exitosa la modificacion
 */


int modificarAuto(eAuto* listaAutos, int tamAutos, eMarca* listaMarcas, int tamMarcas, eColor* listaColores, int tamColores, eCliente* listaClientes, int tamClientes);

/** \brief elimina un auto ya cargado
 *
 * \param lista de autos
 * \param tamaño del array de autos
 * \param lista de marcas
 * \param tamaño del array de marcas
 * \param lista de colores
 * \param tamaño del array de colores
 *
 */


void bajaAuto(eAuto* listaAutos, int tamAutos, eMarca* listaMarcas, int tamMarcas, eColor* listaColores, int tamColores,eCliente* listaClientes, int tamClientes);



/** \brief muestra a todos los autos
 *
 * \param lista de autos
 * \param tamaño del array de autos
 * \param lista de marcas
 * \param tamaño del array de marcas
 * \param lista de colores
 * \param tamaño del array de colores
 *
 */


void mostrarAutos(eAuto* listaAutos, int tamAutos,  eMarca* listaMarcas, int tamMarcas, eColor* listaColores, int tamColores, eCliente* listaClientes, int tamClientes);

/** \brief muestra a un solo auto
 *
 * \param lista de autos
 * \param lista de marcas
 * \param tamaño del array de marcas
 * \param lista de colores
 * \param tamaño del array de colores
 *
 */

void mostrarAuto(eAuto listaAutos, eMarca* listaMarcas, int tamMarcas, eColor* listaColores, int tamColores, eCliente* listaClientes, int tamClientes);


/** \brief ordena los autos por marca y patente
 *
 * \param lista de autos
 * \param tamaño del array de autos
 * \param lista de marcas
 * \param tamaño del array de marcas
 *
 */


void ordenarAutos(eAuto* listaAutos, int tamAutos, eMarca* listaMarcas, int tamMarcas);


