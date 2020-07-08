#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

void inicializarClientes(eCliente* listaClientes, int tamClientes)
{

    for(int i = 0; i < tamClientes; i++)
    {

        listaClientes[i].isEmpty = 1;

    }


}

int cargarNombreCliente(char* nombre, int idPersona, eCliente* listaClientes, int tamClientes)
{
     int todoOk = 0;

    for(int i = 0; i < tamClientes; i++)
    {

        if(listaClientes[i].id == idPersona)
        {

            strcpy(nombre, listaClientes[i].nombre);
            todoOk = 1;



        }


    }

    return todoOk;


}
