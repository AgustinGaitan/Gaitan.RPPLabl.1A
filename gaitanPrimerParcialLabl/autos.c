#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"
#include "menus.h"
#include "utn.h"


void inicializarAutos(eAuto* listaAutos, int tamAutos)
{
    for(int i = 0 ; i < tamAutos; i ++)
    {

        listaAutos[i].isEmpty = 1;

    }

}

int buscarLibreAuto(eAuto* listaAutos, int tamAutos)
{
    int indice  = -1;

    for(int i = 0 ; i < tamAutos ; i++)
    {
        if(listaAutos[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;

}

int buscarAutoPorPatente(eAuto* listaAutos, char* patente, int tamAutos)
{
    int indice = -1;

    for(int i = 0; i < tamAutos; i++)
    {
        if(strcmp(listaAutos[i].patente, patente) == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;

}





int altaAuto(eAuto* listaAutos, int idAutos, int tamAutos, eMarca* listaMarcas, int tamMarcas, eColor* listaColores, int tamColores,eCliente* listaClientes, int tamClientes, int idClientes)
{
    system("cls");
    //eAuto auxAuto;
    int todoOk = 0;
    int indice = buscarLibreAuto(listaAutos,tamAutos);

    if(indice == -1)
    {
        printf("No hay espacio en el sistema.\n\n");
    }
    else
    {
            printf("**** Menu de alta ****\n\n");
            printf("El ID se asigna automaticamente.\n");




             utn_getCadena(listaAutos[indice].patente, 6, 4 , "Ingrese la patente del auto (sin espacios): ", "Error. Ingreso una patente invalida\n");
            system("cls");

            printf("Las marcas disponibles son las siguientes: \n");
            mostrarMarcas(listaMarcas,tamMarcas);


            utn_getEntero(&listaAutos[indice].idMarca, 4, "Ingrese el ID de la marca que desea: ", "Error. Ingrese un id valido.\n", 1000, 1004);
            system("cls");

            printf("Los colores disponibles son los siguientes: \n");
            mostrarColores(listaColores, tamColores);


            utn_getEntero(&listaAutos[indice].idColor, 4, "Ingrese el ID del color que desea: ", "Error. Ingrese un id valido.\n", 5000,5004);
            system("cls");


            utn_getEntero(&listaAutos[indice].modelo, 4, "Ingrese el modelo del vehiculo (1950-2020): ", "Error. Ingrese un modelo valido (1950-2020)\n", 1950, 2020);

            system("cls");
            utn_getCadena(listaClientes[indice].nombre, 20 , 4, "Ingrese el nombre del cliente:  ", "Error. Ingreso un nombre valido\n");
            system("cls");

            printf("Ingrese el sexo 'm' // 'f': ");
            fflush(stdin);
            scanf("%c", &listaClientes[indice].sexo);

            listaAutos[indice].isEmpty = 0;
            listaAutos[indice].id = idAutos;
            listaClientes[indice].id = idClientes;
            listaClientes[indice].isEmpty = 0;
            listaAutos[indice].idCliente = idClientes;
            todoOk = 1;

    }


    return todoOk;


}

int modificarAuto(eAuto* listaAutos, int tamAutos, eMarca* listaMarcas, int tamMarcas, eColor* listaColores, int tamColores, eCliente* listaClientes, int tamClientes)
{


    system("cls");
    int todoOk = 0;
    eAuto auxAuto;
    int indice = -1;
    char confirmar;

    printf("Los autos disponibles son: \n");
    mostrarAutos(listaAutos,tamAutos,listaMarcas,tamMarcas,listaColores,tamColores,listaClientes,tamClientes);
    utn_getCadena(auxAuto.patente, 6, 4, "Ingrese la patente del auto que desea modificar: ", "Error. Ingrese una patente\n");

   indice = buscarAutoPorPatente(listaAutos,auxAuto.patente,tamAutos);

   if(indice == -1)
   {
       printf("La patente que deseo buscar no existe\n\n");
   }
   else
   {

        do
        {
            switch(menuModificar())
            {
            case 1:
                mostrarColores(listaColores,tamColores);
                utn_getEntero(&auxAuto.idColor, 4, "Ingrese el ID del color que desea al que desea cambiar: ", "Error. Ingrese un id valido.\n", 5000,5004);
                listaAutos[indice].idColor = auxAuto.idColor;
                break;
            case 2:
                printf("Modelo actual: %d\n", listaAutos[indice].modelo);
                utn_getEntero(&auxAuto.modelo, 4,"Ingrese el nuevo modelo del vehiculo: ","Error. Ingrese un modelo valido (1950-2020)",1950,2020);
                listaAutos[indice].modelo = auxAuto.modelo;
                break;
            case 3:
                printf("Si ya termino de modificar, o no quiere modificar, ingrese 's' para salir o 'n' para quedarse: ");
                fflush(stdin);
                scanf("%c", &confirmar);

                break;

            }
            system("cls");
        }while(confirmar != 's');
        auxAuto.isEmpty = 0;
        listaAutos[indice].isEmpty = auxAuto.isEmpty;

        todoOk = 1;
   }

    return todoOk;
}

void bajaAuto(eAuto* listaAutos, int tamAutos, eMarca* listaMarcas, int tamMarcas, eColor* listaColores, int tamColores,eCliente* listaClientes, int tamClientes)
{
    eAuto auxAuto;
    int indice;

    printf("Ingrese estos son los autos disponibles: \n");
    mostrarAutos(listaAutos,tamAutos,listaMarcas,tamMarcas,listaColores,tamColores,listaClientes,tamClientes);
    utn_getCadena(auxAuto.patente, 6, 4, "Ingrese la patente del auto que desea dar de baja: ", "Error. Ingrese una patente\n");

    indice = buscarAutoPorPatente(listaAutos,auxAuto.patente,tamAutos);

    if(indice == -1)
    {
        printf("No se encontro la patente del auto que desea borrar.\n\n");
    }
    else
    {
         for(int i = 0; i < tamAutos; i++)
        {
            if(strcmp(listaAutos[indice].patente, auxAuto.patente) == 0)
            {
                listaAutos[indice].isEmpty = 1;
                listaClientes[indice].isEmpty = 1;
                break;
            }
        }
        printf("Dada de baja exitosa.\n\n");

    }


}

void mostrarAutos(eAuto* listaAutos, int tamAutos,  eMarca* listaMarcas, int tamMarcas, eColor* listaColores, int tamColores, eCliente* listaClientes, int tamClientes)
{
    system("cls");
    printf("**** Listado de autos ****\n\n");
    printf("Patente        Marca      Color          Modelo     Cliente\n\n");

    for(int i = 0; i < tamAutos; i++)
    {
        if(!(listaAutos[i].isEmpty)&& listaAutos[i].id > 0)
        {
           mostrarAuto(listaAutos[i],listaMarcas,tamMarcas,listaColores,tamColores,listaClientes,tamClientes);
        }
    }

}

void mostrarAuto(eAuto listaAutos, eMarca* listaMarcas, int tamMarcas, eColor* listaColores, int tamColores, eCliente* listaClientes, int tamClientes)
{

    char descripcionMarca[20];
    char descripcionColor[20];
    char nombreCliente[20];

	cargarDescripcionMarca (descripcionMarca, listaAutos.idMarca, listaMarcas, tamMarcas);
	cargarDescripcionColor(descripcionColor, listaAutos.idColor, listaColores, tamColores);
	cargarNombreCliente(nombreCliente, listaAutos.idCliente , listaClientes,tamClientes);

	printf("%-10s    %-10s     %-10s     %d     %-10s\n", listaAutos.patente, descripcionMarca , descripcionColor, listaAutos.modelo, nombreCliente);


}


void ordenarAutos(eAuto* listaAutos, int tamAutos, eMarca* listaMarcas, int tamMarcas)
{
    eAuto aux;

        for(int i = 0; i < tamAutos -1 ; i++)
        {


            for(int j = i+1; j < tamAutos; j++)
            {


                      if( listaAutos[i].idMarca >  listaAutos[j].idMarca)
                        {
                            aux = listaAutos[i];
                            listaAutos[i] = listaAutos[j];
                            listaAutos[j] = aux;
                        }
                        else if( listaAutos[i].idMarca == listaAutos[j].idMarca && strcmp(listaAutos[i].patente, listaAutos[j].patente) > 0)
                        {

                                    aux = listaAutos[i];
                                    listaAutos[i] = listaAutos[j];
                                    listaAutos[j] = aux;


                        }



            }


        }


}








