#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eMarca;


#endif // MARCAS_H_INCLUDED


/** \brief carga la descripcion de la marca
 *
 * \param  en donde se cargara la descripcion
 * \param  id de la marca a cargar
 * \param  lista de marcas
 * \param  tamaño del array de marcas
 * \return (0) si hubo error
 *          (1) si salio exitoso
 */




int cargarDescripcionMarca(char* descripcion, int idMarca, eMarca* listaMarcas, int tamMarcas);



/** \brief muestra las marcas en un listado
 *
 * \param lista de marcas
 * \param  tamaño del array de marcas
 *
 */


void mostrarMarcas(eMarca* listaMarcas, int tamMarcas);


void mostrarMarca(eMarca listaMarcas);

int buscarMarcasId(eMarca* listaMarcas, int tamMarcas, int id);




