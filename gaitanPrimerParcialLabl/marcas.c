#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marcas.h"


int cargarDescripcionMarca(char* descripcion, int idMarca, eMarca* listaMarcas, int tamMarcas)
{
    int todoOk = 0;

    for(int i = 0; i < tamMarcas; i++)
    {

        if(listaMarcas[i].id == idMarca)
        {

            strcpy(descripcion, listaMarcas[i].descripcion);
            todoOk = 1;



        }


    }

    return todoOk;
}

void mostrarMarcas(eMarca* listaMarcas, int tamMarcas)
{

    printf("**** Listado de Marcas ****\n\n");
    printf(" ID     Marca\n\n");
    for(int i = 0 ; i < tamMarcas; i++)
    {

        if(listaMarcas[i].id != 0)
        {
             mostrarMarca(listaMarcas[i]);

        }

    }
    printf("\n\n");


}


void mostrarMarca(eMarca listaMarcas)
{


	printf(" %d   %-10s\n", listaMarcas.id, listaMarcas.descripcion);


}



int buscarMarcasId(eMarca* listaMarcas, int tamMarcas, int id)
{
     int indice = -1;

    for(int i = 0; i < tamMarcas; i++)
    {
        if( listaMarcas[i].id == id)
        {
            indice = i;
            break;
        }
    }

    return indice;

}
