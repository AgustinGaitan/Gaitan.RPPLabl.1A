#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;

}eCliente;

#endif // CLIENTES_H_INCLUDED

/** \brief carga el nombre de los clientes a los autos
 *
 * \param id de la persona
 * \param  lista de los clientes
 * \param  tamaño del array de los clientes
 * \return (0) si hubo error (1) si todo fue correcto
 *
 */


int cargarNombreCliente(char* nombre, int idPersona, eCliente* listaClientes, int tamClientes);


/** \brief muestra a los clientes
 *
 * \param lista de clientes
 * \param tamaño del array de clientes
 *
 */


void mostrarClientes(eCliente* listaClientes, int tamClientes);

/** \brief muestra un solo cliente
 *
 * \param lista de clientes
 *
 */


void mostrarCliente(eCliente listaClientes);
