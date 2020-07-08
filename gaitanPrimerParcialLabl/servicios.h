#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

}eServicio;


#endif // SERVICIOS_H_INCLUDED


/** \brief muestra los servicios
 *
 * \param lista de servicios
 * \param  tamaño del array de servicios
 *
 */


void mostrarServicios(eServicio* listaServicios, int tamServicios);




/** \brief carga la descripcion del servicio
 *
 * \param  en donde se cargara la descripcion
 * \param  id del servicio a cargar
 * \param  lista de servicios
 * \param  tamaño del array de servicios
 * \return (0) si hubo error
 *          (1) si salio exitoso
 */


int cargarDescripcionServicio(char* descripcion, int idServicio, eServicio* listaServicios, int tamServicios);






void mostrarServicio(eServicio listaServicio);

