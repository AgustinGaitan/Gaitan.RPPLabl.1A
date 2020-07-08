#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colores.h"



int cargarDescripcionColor(char* descripcion, int idColor, eColor* listaColores, int tamColores)
{
    int todoOk = 0;

    for(int i = 0; i < tamColores; i++)
    {

        if(listaColores[i].id == idColor)
        {

            strcpy(descripcion, listaColores[i].descripcion);
            todoOk = 1;



        }


    }

    return todoOk;

}

void mostrarColores(eColor* listaColores, int tamColores)
{

    printf("**** Listado de Colores ****\n\n");
    printf(" ID     Color\n\n");
    for(int i = 0 ; i < tamColores; i++)
    {
        mostrarColor(listaColores[i]);
    }
    printf("\n\n");



}


void mostrarColor(eColor listaColores)
{



	printf(" %d   %-10s\n", listaColores.id, listaColores.descripcion);


}
