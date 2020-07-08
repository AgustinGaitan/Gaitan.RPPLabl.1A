#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "autos.h"
#include "colores.h"
#include "marcas.h"
#include "trabajos.h"


typedef struct
{

    int idMarca;
    int cantidad;
    int isEmpty;


}eMarcaMasElegida;


#endif // INFORMES_H_INCLUDED




int inicializarMarcaMasElegida(eMarcaMasElegida* marcas, int tamMarcaMasElegida);


/** \brief lista los autos con un color seleccionado
 *
 * \param lista de autos
 * \param tamaño del array de autos
 * \param lista de colores
 * \param tamaño del array de colores
 * \param lista de marcas
 * \param tamaño del array de marcas
 * \param lista de clientes
 * \param tamaño del array de clientes
 *
 */


void informarAutosColor(eAuto* listaAutos,int tamAutos,eColor* listaColores,int tamColores,eMarca* listaMarcas,int tamMarcas,eCliente* listaClientes,int tamClientes);


/** \brief lista los autos con la marca seleccionada
 *
 * \param lista de autos
 * \param tamaño del array de autos
 * \param lista de colores
 * \param tamaño del array de colores
 * \param lista de marcas
 * \param tamaño del array de marcas
 * \param lista de clientes
 * \param tamaño del array de clientes
 *
 */


void informarAutosMarca(eAuto* listaAutos,int tamAutos,eColor* listaColores,int tamColores,eMarca* listaMarcas,int tamMarcas,eCliente* listaClientes,int tamClientes);



/** \brief lista los autos que tienen modelo menores al 2000
 *
 * \param lista de autos
 * \param tamaño del array de autos
 * \param lista de colores
 * \param tamaño del array de colores
 * \param lista de marcas
 * \param tamaño del array de marcas
 * \param lista de clientes
 * \param tamaño del array de clientes
 *
 */


void informarAutosViejos(eAuto* listaAutos,int tamAutos,eColor* listaColores,int tamColores,eMarca* listaMarcas,int tamMarcas,eCliente* listaClientes,int tamClientes);


/** \brief lista los autos separados por marcas
 *
 * \param lista de autos
 * \param tamaño del array de autos
 * \param lista de colores
 * \param tamaño del array de colores
 * \param lista de marcas
 * \param tamaño del array de marcas
 * \param lista de clientes
 * \param tamaño del array de clientes
 *
 */

void informarAutosSeparadosMarca(eAuto* listaAutos,int tamAutos,eColor* listaColores,int tamColores,eMarca* listaMarcas,int tamMarcas,eCliente* listaClientes,int tamClientes);

/** \brief contabiliza los autos depende la marca y color seleccionado
 *
 * \param lista de autos
 * \param tamaño del array de autos
 * \param lista de colores
 * \param tamaño del array de colores
 * \param lista de marcas
 * \param tamaño del array de marcas
 * \param lista de clientes
 * \param tamaño del array de clientes
 *
 */

void informarContadorColorMarca(eAuto* listaAutos,int tamAutos,eColor* listaColores,int tamColores,eMarca* listaMarcas,int tamMarcas,eCliente* listaClientes,int tamClientes);

/** \brief informa la marca mas elegida
 *
 * \param lista de autos
 * \param tamaño del array de autos
 * \param lista de marcas
 * \param tamaño del array de marcas
 * \param marcaElegida
 *
 */



void informarMarcaMasElegida(eAuto* listaAutos,int tamAutos,eMarca* listaMarcas,int tamMarcas, eMarcaMasElegida* marcaElegida);


/** \brief informa cada trabajo asignado a un auto a igresar
 *
 * \param lista de autos
 * \param tamaño del array de autos
 * \param lista de servicios
 * \param tamaño del array de servicios
 *
 *
 */

void informarTrabajosAuto(eAuto* listaAutos,int tamAutos, eTrabajo* listaTrabajos, int tamTrabajos, eServicio* listaServicios, int tamServicios);

/** \brief Informa el importe total de un auto a seleccionar
 *
 * \param lista de autos
 * \param  tamaño del array de autos
 * \param lista de trabajos
 * \param  tamaño del array de trabajos
 * \param lista de servicios
 * \param  tamaño del array de servicios
 *
 */

void informarImporteAuto(eAuto* listaAutos, int tamAuto,eTrabajo* listaTrabajos, int tamTrabajos,eServicio* listaServicios, int tamServicios);


/** \brief Informa la cantidad de autos con un servicio a seleccionar
 *
 * \param lista de autos
 * \param tamaño del array de autos
 * \param lista de trabajos
 * \param tamaño del array de trabajos
 * \param lista de servicios
 * \param tamaño del array de servicios
 *
 *
 */


void informarServicioRealizadoAuto(eAuto* listaAutos, int tamAuto,eTrabajo* listaTrabajos, int tamTrabajos,eServicio* listaServicios, int tamServicios);

/** \brief informa los servicios en una fecha a ingresar
 *
 * \param lista de trabajos
 * \param tamaño del array de trabajos
 * \param lista de servicios
 * \param tamaño del array de servicios
 *
 */


void informarFechaServicios(eTrabajo* listaTrabajos, int tamTrabajos,eServicio* listaServicios, int tamServicios);











