#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eColor;





#endif // COLORES_H_INCLUDED


/** \brief carga la descripcion de un color al campo descripcionColor de un auto
 *
 * \param en donde se cargara la descripcion
 * \param id del color a cargar
 * \param lista de colores
 * \param tamaño del array de colores
 * \return (0) si hubo error
 *          (1) si salio exitosamente
 */



int cargarDescripcionColor(char* descripcion, int idColor, eColor* listaColores, int tamColores);



/** \brief muestra los colores
 *
 * \param lista de colores
 * \param  tamaño del array de colores
 *
 */


void mostrarColores(eColor* listaColores, int tamColores);




/** \brief muestra un solo color
 *
 * \param lista de colores
 */



 void mostrarColor(eColor listaColores);

