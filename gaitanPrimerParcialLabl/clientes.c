#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"


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

void mostrarClientes(eCliente* listaClientes, int tamClientes)
{
    system("cls");
    printf("**** Lista de Clientes****\n\n");
    printf("Id       Nombre       Sexo\n\n");

    for(int i = 0; i < tamClientes; i++)
    {
        if(listaClientes[i].id > 0)
        {
            mostrarCliente(listaClientes[i]);


        }
    }
}

void mostrarCliente(eCliente listaClientes)
{



	printf("%d       %-10s        %c\n", listaClientes.id, listaClientes.nombre, listaClientes.sexo);


}


