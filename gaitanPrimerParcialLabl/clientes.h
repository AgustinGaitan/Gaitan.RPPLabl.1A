#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;

}eCliente;

#endif // CLIENTES_H_INCLUDED


void inicializarClientes(eCliente* listaClientes, int tamClientes);

int cargarNombreCliente(char* nombre, int idPersona, eCliente* listaClientes, int tamClientes);
