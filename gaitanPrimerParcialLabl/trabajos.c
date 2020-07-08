#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajos.h"
#include "utn.h"



void inicializarTrabajos(eTrabajo* listaTrabajos, int tamTrabajos)
{
    for(int i = 0 ; i < tamTrabajos ; i++)
    {
        listaTrabajos[i].isEmpty = 1;
    }
}

int buscarLibreTrabajo(eTrabajo* listaTrabajos, int tamTrabajos)
{
    int indice = -1;

        for(int i = 0 ; i < tamTrabajos ; i++)
        {
            if(listaTrabajos[i].isEmpty)
            {
                indice = i;
                break;
            }
        }

    return indice;
}



int altaTrabajo(eTrabajo* listaTrabajos, int idTrabajo, int tamTrabajos, eServicio* listaServicios, int tamServicios, eAuto* listaAutos, int tamAutos, eMarca* listaMarcas, int tamMarcas, eColor* listaColores, int tamColores,  eCliente* listaClientes, int tamClientes)
{
    int todoOk = 0;
    int indice = buscarLibreTrabajo(listaTrabajos, tamTrabajos);
    eTrabajo auxTrabajo;




    if(indice == -1)
    {
        printf("No hay lugar en el sistema para asignar trabajos\n\n");
        system("pause");
    }
    else
    {
            system("cls");
            printf("**** Alta trabajo ****\n\n");

            printf("El id se asigna automaticamente.\n\n");
            printf("Ingrese la fecha actual: \n\n");
            if(!(utn_getEntero(&auxTrabajo.fecha.dia,2,"Dia: ","Error. Ingrese un dia correcto.",1,31)) &&
               !(utn_getEntero(&auxTrabajo.fecha.mes,2,"Mes: ","Error. Ingrese un mes correcto.",1,12)) &&
               !(utn_getEntero(&auxTrabajo.fecha.anio,2,"Anio: ","Error. Ingrese un anio correcto.",2015,2020)))
            {
                 system("cls");

                    printf("Elija un auto: \n\n");
                mostrarAutos(listaAutos,tamAutos,listaMarcas,tamMarcas,listaColores,tamColores,listaClientes,tamClientes);


                printf("Ingrese la patente del auto al que desea agregarle un servicio: ");
                fflush(stdin);
                gets(auxTrabajo.patente);
                if(buscarAutoPorPatente(listaAutos,auxTrabajo.patente, tamAutos) == -1)
                {
                    printf("La patente no existe.\n\n");
                }

                system("cls");

                printf("Elija un servicio: \n\n");
                mostrarServicios(listaServicios, tamServicios);

                printf("Ingrese el ID del servicio que desea: ");
                scanf("%d", &auxTrabajo.idServicio);

                auxTrabajo.id = idTrabajo;
                auxTrabajo.isEmpty = 0;

                listaTrabajos[indice] = auxTrabajo;
                printf("Dada de alta exitosa.\n\n");

                todoOk = 1;



            }

            //scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);



    }
    system("cls");


    return todoOk;
}

void mostrarTrabajos(eTrabajo* listaTrabajos, int tamTrabajos, eServicio* listaServicios, int tamServicios)
{
    system("cls");
    printf("**** Lista de Trabajos****\n\n");
    printf("Fecha      Patente      Descripcion\n\n");

    for(int i = 0; i < tamTrabajos; i++)
    {
        if(listaTrabajos[i].isEmpty == 0 && listaTrabajos[i].id > 0)
        {
            mostrarTrabajo(listaTrabajos[i],listaServicios,tamServicios);


        }
    }
}

void mostrarTrabajo(eTrabajo listaTrabajo,  eServicio* listaServicios, int tamServicios)
{

    char descripcionServicio[25];

	cargarDescripcionServicio(descripcionServicio,listaTrabajo.idServicio, listaServicios, tamServicios);

	printf("%d/%.2d/%d     %-10s      %-10s\n", listaTrabajo.fecha.dia,listaTrabajo.fecha.mes,listaTrabajo.fecha.anio, listaTrabajo.patente, descripcionServicio);


}



int buscarTrabajoPorPatente(eTrabajo* listaTrabajos, char* patente, int tamTrabajos)
{
    int indice = -1;

    for(int i = 0; i < tamTrabajos; i++)
    {
        if(strcmp(listaTrabajos[i].patente, patente) == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;

}
