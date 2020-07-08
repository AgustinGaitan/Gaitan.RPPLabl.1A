#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"
#include <ctype.h>




void mostrarServicios(eServicio* listaServicios, int tamServicios)
{

    printf("**** Listado de Servicios ****\n\n");
    printf(" ID         Servicio           Precio\n\n");
    for(int i = 0 ; i < tamServicios; i++)
    {
        if(listaServicios[i].id != 0)
        {
            //printf(" %d   %-10s    $%.2f\n", listaServicios[i].id, listaServicios[i].descripcion, listaServicios[i].precio);
            mostrarServicio(listaServicios[i]);
        }

    }
    printf("\n\n");
}


int cargarDescripcionServicio(char* descripcion, int idServicio, eServicio* listaServicios, int tamServicios)
{
    int todoOk = 0;

    for(int i = 0; i < tamServicios; i++)
    {

        if(listaServicios[i].id == idServicio)
        {

            strcpy(descripcion, listaServicios[i].descripcion);
            todoOk = 1;

        }


    }

    return todoOk;

}




void mostrarServicio(eServicio listaServicio)
{



	printf("%-3d      %-10s       $%.2f \n", listaServicio.id, listaServicio.descripcion, listaServicio.precio);


}
