#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "servicios.h"
#include "marcas.h"
#include "colores.h"
#include "autos.h"
#include "clientes.h"


typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;



typedef struct
{
    int id;
    char patente[6];
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;




#endif // TRABAJOS_H_INCLUDED


/** \brief inicializa los trabajos poniendo su campo isEmpty en 1
 *
 * \param lista de trabajos
 * \param tamaño del array de trabajos
 *
 */


void inicializarTrabajos(eTrabajo* listaTrabajos, int tamTrabajos);


/** \brief Busca el primer lugar del array que tiene isEmpty 1
 *
 * \param lista de trabajos
 * \param  tamaño del array
 * \return (-1) si no encontro
           (indice) si encontro
 *
 */



int buscarLibreTrabajo(eTrabajo* listaTrabajos, int tamTrabajos);

/** \brief da de alta a un nuevo trabajo
 *
 * \param  lista de trabajos
 * \param id del trabajo previamente ingresado
 * \param tamaño del array de trabajos
 * \param lista de servicios
 * \param tamaño del array de servicios
 * \param lista de autos
 * \param tamaño del array de autos
 * \param lista de marcas
 * \param tamaño del array de marcas
 * \param lista de colores
 * \param tamaño del array de colores
 *
 * \return (0) si hubo error
 *          (1) si salio exitoso
 */



int altaTrabajo(eTrabajo* listaTrabajos, int idTrabajo, int tamTrabajos, eServicio* listaServicios, int tamServicios, eAuto* listaAutos, int tamAutos, eMarca* listaMarcas, int tamMarcas, eColor* listaColores, int tamColores, eCliente* listaClientes, int tamClientes);


/** \brief muestra todos los trabajos en forma de lista
 *
 * \param lista de trabajos
 * \param  tamaño del array de trabajos
 * \param lista de servicios
 * \param tamaño del array de servicios
 *
 */


void mostrarTrabajos(eTrabajo* listaTrabajos, int tamTrabajos, eServicio* listaServicios, int tamServicios);


/** \brief  muestra un solo trabajo
 *
 * \param lista de trabajos
 * \param lista de servicios
 * \param tamaño del array de servicios
 *
 */

void mostrarTrabajo(eTrabajo listaTrabajo,  eServicio* listaServicios, int tamServicios);


/** \brief Busca un trabajo mediante la patente del auto asignado.
 *
 * \param lista de trabajos
 * \param  patente ingresada
 * \param  tamaño del array de trabajos
 * \return (-1) Si hay error.  (indice) Del trabajo
 *
 *
 */


int buscarTrabajoPorPatente(eTrabajo* listaTrabajos, char* patente, int tamTrabajos);
