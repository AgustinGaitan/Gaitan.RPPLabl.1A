#ifndef SUCIEDAD_H_INCLUDED
#define SUCIEDAD_H_INCLUDED
#include "autos.h"
#include "marcas.h"
#include "colores.h"
#include "clientes.h"


typedef struct
{

    int id;
    char descripcion[20];
    int duracion;

}eSuciedad;


#endif // SUCIEDAD_H_INCLUDED

/** \brief lista de suciedades
 *
 * \param tamaño del array de suciedades
 * \param lista de autos
 * \param  tamaño del array de autos
 * \param lista de colores
 * \param tamaño del array de colores
 * \param lista de marcas
 * \param  tamaño del array de marcas
 * \param lista de clientes
 * \param  tamaño del array de clientes
 * \return  (1) si hubo exito (0) si hubo error
 *
 */



int asignarParteMasSuciaAuto(eSuciedad* suciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos, eColor* listaColores, int tamColores, eMarca* listaMarcas, int tamMarcas, eCliente* listaClientes, int tamClientes);


/** \brief muestra una sola parte mas sucia a limpiar
 *
 */


void mostrarSuciedad(eSuciedad listaSuciedad);

/** \brief muestra todas las partes mas sucias posibles a limpiar
 *
 * \param  lista de partes a limpiar
 * \param  tamaño del array de las partes a limpiar
 *
 */


void mostrarSuciedades(eSuciedad* listaSuciedad, int tamSuciedad);


/** \brief muestra a los autos con sus respectivas partes mas sucias
 *
 * \param  lista de partes mas sucias
 * \param  tamaño del array de partes sucias
 * \param lista de autos
 * \param  tamaño del array de autos
 * \param  lista de clientes
 * \param  tamaño del array de clientes
 * \return
 *
 */



void mostrarAutosConSuciedad(eSuciedad* listaSuciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos, eCliente* listaClientes, int tamClientes);

/** \brief muestra un solo auto sucio
 *
 * \param lista de autos
 * \param lista de partes mas sucias
 * \param tamaño del array de partes mas sucias
 * \param  lista de clientes
 * \param  tamaño del array de clientes
 *
 */

void mostrarAutoSucio(eAuto listaAutos, eSuciedad* listaSuciedad, int tamSuciedad, eCliente* listaClientes, int tamClientes);

/** \brief muestra a los autos separados por partes mas sucia a limpiar
 *
 * \param lista de partes mas sucias
 * \param tamaño del array de partes mas sucias
 * \param lista de autos
 * \param tamaño del array de autos
 * \param  lista de clientes
 * \param  tamaño del array de clientes
 *
 */



void mostrarAutosSeparadosPorSuciedad(eSuciedad* listaSuciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos, eCliente* listaClientes, int tamClientes);

/** \brief muestra las suciedades que conllevan mas horas
 *
 * \param lista de partes mas sucias
 * \param tamaño del array
 *\param lista de autos
 *\param tamaño del array de autos
 *
 */



void mostrarSuciedadesOrdenadasPorHora(eSuciedad* listaSuciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos);


/** \brief muestra el auto al que hay que dedicarle mas horas
 *
 * \param lista de partes mas sucias
 * \param tamaño del array
 *\param lista de autos
 *\param tamaño del array de autos
 *
 */


void mostrarAutoConMasHorasADedicar(eSuciedad* listaSuciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos, eCliente* listaClientes, int tamClientes);
