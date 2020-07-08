#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "utn.h"
#include "suciedad.h"


int inicializarMarcaMasElegida(eMarcaMasElegida* marcas, int tamMarcaMasElegida)
{
    int todoOk = 1;

    for(int i = 0; i < tamMarcaMasElegida; i++)
    {


        marcas[i].isEmpty = 1;
        todoOk = 0;

    }



    return todoOk;
}

void informarAutosColor(eAuto* listaAutos,int tamAutos,eColor* listaColores,int tamColores,eMarca* listaMarcas,int tamMarcas,eCliente* listaClientes,int tamClientes)
{
    system("cls");
    char descripcion[20];
    int idColorElegido;
    int encontrado = 0;
    mostrarColores(listaColores,tamColores);
    if(!(utn_getEntero(&idColorElegido,4,"Ingrese el id del color que desea: ", "Error. Elija un numero valido.\n",5000,5004)))
    {

        system("cls");
        cargarDescripcionColor(descripcion,idColorElegido,listaColores,tamColores);

        printf("Autos registrados con el color %s : \n",descripcion);
        printf("\nPatente        Marca      Color          Modelo     Cliente\n");
        for(int i = 0; i < tamAutos; i++)
        {

          if( listaAutos[i].isEmpty == 0 && listaAutos[i].idColor == idColorElegido)
          {
               mostrarAuto(listaAutos[i], listaMarcas,tamMarcas,listaColores,tamColores,listaClientes,tamClientes);
               encontrado = 1;
          }



        }
    }

    if(!encontrado)
    {

        system("cls");
        printf("No hay autos del color seleccionado.\n");
    }
}



void informarAutosMarca(eAuto* listaAutos,int tamAutos,eColor* listaColores,int tamColores,eMarca* listaMarcas,int tamMarcas,eCliente* listaClientes,int tamClientes)
{
    system("cls");
    char descripcion[20];
    int idMarcaElegida;
    int encontrado = 0;
    mostrarMarcas(listaMarcas,tamMarcas);
    if(!(utn_getEntero(&idMarcaElegida,4,"Ingrese el id de la marca que desea:  ", "Error. Elija un numero valido.\n",1000,1004)))
    {
        system("cls");
        cargarDescripcionMarca(descripcion, idMarcaElegida, listaMarcas,tamMarcas);

        printf("Autos registrados con la marca %s : \n",descripcion);
        printf("\nPatente        Marca      Color          Modelo     Cliente\n");
        for(int i = 0; i < tamAutos; i++)
        {

          if( listaAutos[i].isEmpty == 0 && listaAutos[i].idMarca == idMarcaElegida)
          {
               mostrarAuto(listaAutos[i], listaMarcas,tamMarcas,listaColores,tamColores,listaClientes,tamClientes);
               encontrado = 1;
          }



        }
    }

    if(!encontrado)
    {

        system("cls");
        printf("No hay autos de esa marca registrados.\n");
    }
}


 void informarAutosViejos(eAuto* listaAutos,int tamAutos,eColor* listaColores,int tamColores,eMarca* listaMarcas,int tamMarcas,eCliente* listaClientes,int tamClientes)
 {

    system("cls");

    int encontrado = 0;

    printf(" Los autos que son del 2000 para abajo son: \n\n");
    printf("\nPatente        Marca      Color          Modelo     Cliente\n");

    for(int i = 0 ; i < tamAutos; i++)
    {

        if(listaAutos[i].modelo < 2000 && !(listaAutos[i].isEmpty) && listaAutos[i].id > 0 && listaClientes[i].id > 0)
        {

            mostrarAuto(listaAutos[i], listaMarcas,tamMarcas,listaColores,tamColores,listaClientes,tamClientes);
            encontrado = 1;

        }


    }

    if(!encontrado)
    {
        system("cls");
        printf(" No hay autos que sean del siglo pasado.\n");


    }


 }




void informarAutosSeparadosMarca(eAuto* listaAutos,int tamAutos,eColor* listaColores,int tamColores,eMarca* listaMarcas,int tamMarcas,eCliente* listaClientes,int tamClientes)
{

     system("cls");

     char descripcionMarca[20];
     int encontrado;

    printf("*** Lista de autos por marca ****\n\n");

     for(int i = 0; i < tamMarcas; i++)
     {
            encontrado = 0;

             printf("*********************************************************\n");

             printf("Patente        Marca      Color          Modelo     Cliente\n");
            for(int j = 0; j < tamAutos; j++)
            {

                if(!(listaAutos[j].isEmpty) && listaAutos[j].idMarca == listaMarcas[i].id)
                {

                    mostrarAuto(listaAutos[j],listaMarcas,tamMarcas,listaColores,tamColores,listaClientes,tamClientes);

                    encontrado = 1;

                }


            }

           if(!encontrado)
            {
                cargarDescripcionMarca(descripcionMarca,listaMarcas[i].id,listaMarcas,tamMarcas);

                printf("***** No hay autos %s *****\n\n", descripcionMarca);
            }


     }


}



void informarContadorColorMarca(eAuto* listaAutos,int tamAutos,eColor* listaColores,int tamColores,eMarca* listaMarcas,int tamMarcas,eCliente* listaClientes,int tamClientes)
{

   system("cls");

    char descripcionColor[20];
    char descripcionMarca[20];
    int auxIdColor;
    int auxIdMarca;
    int contador = 0;
    int flag = 0;

        mostrarColores(listaColores,tamColores);
        if(!(utn_getEntero(&auxIdColor,4,"Ingrese el color de los autos que desea contar: ", "Error. Ingrese un id valido.\n",5000,5004)))
        {
            flag = 1;

        }

         if(flag)
         {
                system("cls");
                mostrarMarcas(listaMarcas,tamMarcas);


                  if(!(utn_getEntero(&auxIdMarca,4,"Ingrese el id de la marca de los autos que desea contar: ", "Error. Ingrese un id valido.\n",1000,1004)))
                    {
                        system("cls");



                        for(int i = 0; i < tamAutos; i++)
                        {


                            if(!(listaAutos[i].isEmpty) && (listaAutos[i].idColor == auxIdColor) && (listaAutos[i].idMarca == auxIdMarca))
                            {

                                contador++;

                            }

                        }

                         cargarDescripcionMarca(descripcionMarca,auxIdMarca,listaMarcas,tamMarcas);
                         cargarDescripcionColor(descripcionColor,auxIdColor,listaColores,tamColores);

                         if(contador > 0)
                         {
                             printf("Cantidad de autos de color %s y marca %s: %d\n", descripcionColor,descripcionMarca,contador);
                         }
                         else
                         {
                             printf("No hay autos con el color %s y la marca %s. \n",descripcionColor,descripcionMarca,contador);

                         }




                    }


         }


}


void informarMarcaMasElegida(eAuto* listaAutos,int tamAutos,eMarca* listaMarcas,int tamMarcas, eMarcaMasElegida* marcaElegida)
{
    system("cls");
    eMarcaMasElegida marcaMasElegida;
    int marcaActual = 0;
    int flag;
    int flagMax = 0;
    int indiceMarca;



        for(int i = 0 ; i < tamMarcas ; i++)
        {


            flag = 0;

                    for(int j = 0 ; j < tamAutos ; j++)
                    {

                        if(!(listaAutos[j].isEmpty) && listaAutos[j].idMarca == listaMarcas[i].id)
                        {

                            flag++;

                        }

                     }


                marcaElegida[marcaActual].idMarca = listaMarcas[i].id;

                marcaElegida[marcaActual].cantidad = flag;

                marcaActual++;


        }

        for(int k = 0; k < tamMarcas ; k++)   //for para buscar el max
        {

            if(!flagMax)
            {
                marcaMasElegida = marcaElegida[k];
                flagMax = 1;

            }
            else if(marcaElegida[k].cantidad > marcaMasElegida.cantidad && marcaElegida[k].idMarca > 0)
            {

                marcaMasElegida = marcaElegida[k];


            }



        }


        printf("La marca mas elegida es:\n ");
        printf("Id     MARCA\n");

        for(int l = 0; l < tamMarcas; l++) //recorre las marcas y compara
        {

            if(marcaMasElegida.cantidad == marcaElegida[l].cantidad && marcaElegida[l].idMarca > 0)
            {

                indiceMarca = buscarMarcasId(listaMarcas,tamMarcas,marcaElegida[l].idMarca);

                mostrarMarca(listaMarcas[indiceMarca]);

            }



        }



}




void informarTrabajosAuto(eAuto* listaAutos,int tamAutos, eTrabajo* listaTrabajos, int tamTrabajos, eServicio* listaServicios, int tamServicios)
{
    system("cls");

    char auxPatente[6];
    int indice;

                if(!(utn_getCadena(auxPatente,6,3,"Ingrese la patente del auto del que desea averiguar los trabajos hechos al mismo: ","Error. Ingrese una patente valida.\n")))
                {

                    indice = buscarAutoPorPatente(listaAutos,auxPatente,tamAutos);

                    system("cls");

                    if(indice != -1) //para comprobar si existe.
                    {

                        printf("Los trabajos asignados para ese auto son:\n\n ");
                        printf("Fecha        Patente      Descripcion\n\n ");

                        for(int i = 0; i < tamTrabajos; i ++)
                        {

                              if(!(strcmp(listaTrabajos[i].patente,auxPatente)))
                            {

                                mostrarTrabajo(listaTrabajos[i], listaServicios, tamServicios);

                            }



                        }




                    }
                    else
                    {

                        printf("El auto no existe.\n");

                    }




                }


}




void informarImporteAuto(eAuto* listaAutos, int tamAuto,eTrabajo* listaTrabajos, int tamTrabajos,eServicio* listaServicios, int tamServicios)
{

     system("cls");

    char auxPatente[6];
    int indice;
    float precioTotal = 0;

                if(!(utn_getCadena(auxPatente,6,3,"Ingrese la patente del auto al que desea averiguar los importes: ","Error. Ingrese una patente valida.\n")))
                {

                    indice = buscarAutoPorPatente(listaAutos, auxPatente, tamAuto);

                    system("cls");

                    if(indice != -1) // solo para comprobar si existe
                    {

                        for(int i = 0; i < tamTrabajos; i ++)
                        {

                            for(int j = 0; j < tamServicios;j++)
                            {

                              if(listaTrabajos[i].idServicio == listaServicios[j].id && !(strcmp(listaTrabajos[i].patente, listaAutos[indice].patente)))
                                {

                                    precioTotal = precioTotal + listaServicios[j].precio;

                                }


                            }

                        }


                         printf("Los importes realizados a ese vehiculo fueron: $%.2f\n", precioTotal);

                    }
                    else
                    {


                        printf("Ese auto no existe.\n");
                    }




                }



}

void informarServicioRealizadoAuto(eAuto* listaAutos, int tamAuto,eTrabajo* listaTrabajos, int tamTrabajos,eServicio* listaServicios, int tamServicios)
{
    system("cls");


       int auxIdServ;
       int flag = 0;


        mostrarServicios(listaServicios,tamServicios);
        printf("\n\n");

        if(!(utn_getEntero(&auxIdServ,2,"Ingrese el ID del servicio del que desea ver los autos: ","Error. Ingrese un id valido.\n",20000,20003)))
        {
                system("cls");
                    printf("Fecha      Patente      Descripcion\n\n");
                    for(int i = 0; i < tamServicios; i++)
                    {
                        for(int j = 0;  j< tamTrabajos; j++)
                        {


                            if(auxIdServ == listaServicios[i].id && listaTrabajos[j].idServicio == auxIdServ)
                            {


                                 mostrarTrabajo(listaTrabajos[j],listaServicios,tamServicios);
                                 flag = 1;

                            }





                        }




                    }

                    if(!flag)
                    {

                            printf("No hay autos con ese servicio.\n\n");

                    }




            }


}

void informarFechaServicios(eTrabajo* listaTrabajos, int tamTrabajos,eServicio* listaServicios, int tamServicios)
{

    system("cls");

    int auxDia;
    int auxMes;
    int auxAnio;
    int flag = 0;

                       printf("Para ver los servicios realizados en una fecha ingrese:\n\n");
                    if(!(utn_getEntero(&auxDia,2,"El dia: ","Error. Ingrese un dia correcto. (1-31)",1,31)) &&
                       !(utn_getEntero(&auxMes,2,"El mes: ", "Error. Ingrese un mes correcto. (1-12)",1,12)) &&
                       !(utn_getEntero(&auxAnio,2,"El anio: ","Error. Ingrese un anio correcto.(2015-2020)",2015,2020)))
                    {

                        system("cls");

                        printf("Los servicios realizados la fecha %d/%d/%d son: \n\n\n", auxDia, auxMes, auxAnio);
                        printf("Fecha      Patente      Descripcion\n\n");
                        for(int i = 0; i < tamTrabajos; i++)
                        {

                            if( auxDia == listaTrabajos[i].fecha.dia &&
                               auxMes == listaTrabajos[i].fecha.mes &&
                               auxAnio == listaTrabajos[i].fecha.anio)
                            {

                                mostrarTrabajo(listaTrabajos[i],listaServicios,tamServicios);
                                flag = 1;

                                printf("\n\n");

                            }



                        }

                        if(!flag)
                        {

                            printf("No hay trabajos realizados en esa fecha.\n\n");

                        }



                    }


}




/////////////////RECUPERATORIO INFORMES


void mostrarSuciedad(eSuciedad listaSuciedad)
{



    printf(" %d       %-10s        %d hs\n", listaSuciedad.id, listaSuciedad.descripcion, listaSuciedad.duracion);


}


void mostrarSuciedades(eSuciedad* listaSuciedad, int tamSuciedad)
{
    system("cls");
    printf("**** Listado de partes sucias posibles ****\n\n");
    printf(" ID     Descripcion   Tiempo a dedicar \n\n");
    for(int i = 0 ; i < tamSuciedad; i++)
    {
        mostrarSuciedad(listaSuciedad[i]);
    }
    printf("\n\n");


}


int asignarParteMasSuciaAuto(eSuciedad* suciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos, eColor* listaColores, int tamColores, eMarca* listaMarcas, int tamMarcas, eCliente* listaClientes, int tamClientes)
{
    system("cls");

        int todoOk = 0;
        char auxPatente[6];
        int idSuc;
        int indice = -1;

        printf("Los autos a los cuales se le pueden agregar las partes sucias son: \n");

        mostrarAutos(listaAutos, tamAutos, listaMarcas,tamMarcas, listaColores, tamColores, listaClientes, tamClientes);



        if(!(utn_getCadena(auxPatente, 6, 2, "Ingrese la patente del auto a la que le debe asignar la parte mas sucia: ", "Error. Ingrese una patente valida\n")))
        {

            system("cls");

             indice =  buscarAutoPorPatente(listaAutos,auxPatente,tamAutos);


                    if(indice != -1)
                    {

                         printf("La lista de las partes mas sucias son: \n\n");

                         mostrarSuciedades(suciedad,tamSuciedad);

                         if(!(utn_getEntero(&idSuc, 2,"Ingrese el ID de la parte mas sucia posible del auto: ", "Error. Ingrese un ID valido.\n", 1,5)))
                         {


                            listaAutos[indice].idSuciedad = idSuc;
                            printf("Parte a limpiar agregada con exito.\n");
                            todoOk = 1;


                          }




                        }
                        else
                        {

                            printf("La patente que busco no existe.\n\n");


                        }


        }

 return todoOk;
}

int cargarDescripcionSuciedad(char* descripcion, int idSuciedad, eSuciedad* listaSuciedad, int tamSuciedad)
{
    int todoOk = 0;

    for(int i = 0; i < tamSuciedad; i++)
    {

        if(listaSuciedad[i].id == idSuciedad)
        {

            strcpy(descripcion, listaSuciedad[i].descripcion);
            todoOk = 1;

        }


    }

    return todoOk;

}

void mostrarAutoSucio(eAuto listaAutos, eSuciedad* listaSuciedad, int tamSuciedad, eCliente* listaClientes, int tamClientes)
{

    char nombreCliente[20];
    char descSuciedad[20];

	cargarNombreCliente(nombreCliente, listaAutos.idCliente , listaClientes,tamClientes);
	cargarDescripcionSuciedad(descSuciedad, listaAutos.idSuciedad, listaSuciedad, tamSuciedad);

	printf("%-10s    %-10s           %-10s\n", listaAutos.patente, nombreCliente, descSuciedad);


}


void mostrarAutosConSuciedad(eSuciedad* listaSuciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos, eCliente* listaClientes, int tamClientes)
{

    system("cls");
    printf("**** Listado de partes sucias a limpiar de cada auto ****\n\n");
    printf("Patente    Nombre del cliente    Parte a limpiar\n\n");

    for(int i = 0; i < tamAutos; i++)
    {
        if(!(listaAutos[i].isEmpty) && listaAutos[i].id > 0)
        {

           mostrarAutoSucio(listaAutos[i],listaSuciedad,tamSuciedad,listaClientes,tamClientes);

        }
    }

}



void mostrarAutosSeparadosPorSuciedad(eSuciedad* listaSuciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos, eCliente* listaClientes, int tamClientes)
{


     system("cls");

     char descSuciedad[20];
     int encontrado;

    printf("*** Lista de autos separados por parte mas sucia****\n\n");

     for(int i = 0; i < tamSuciedad; i++)
     {
            encontrado = 0;

             printf("*********************************************************\n");

             printf("Patente    Nombre del cliente    Parte a limpiar\n\n");

            for(int j = 0; j < tamAutos; j++)
            {

                if(!(listaAutos[j].isEmpty) && listaAutos[j].idSuciedad == listaSuciedad[i].id)
                {

                    mostrarAutoSucio(listaAutos[j],listaSuciedad,tamSuciedad,listaClientes,tamClientes);

                    encontrado = 1;

                }


            }

           if(!encontrado)
            {
                cargarDescripcionSuciedad(descSuciedad,listaSuciedad[i].id,listaSuciedad,tamSuciedad);

                printf("***** No hay autos que la parte mas sucia sea  %s *****\n\n", descSuciedad);
            }


     }



}






void mostrarSuciedadesOrdenadasPorHora(eSuciedad* listaSuciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos)
{


    eSuciedad aux;

        for(int i = 0; i < tamSuciedad -1 ; i++)
        {


            for(int j = i+1; j < tamSuciedad; j++)
            {


                      if( listaSuciedad[i].duracion < listaSuciedad[j].duracion)
                        {
                            aux = listaSuciedad[i];
                            listaSuciedad[i] = listaSuciedad[j];
                            listaSuciedad[j] = aux;
                        }
                        else if( listaSuciedad[i].duracion == listaSuciedad[j].duracion)
                        {

                                    aux = listaSuciedad[i];
                                    listaSuciedad[i] = listaSuciedad[j];
                                    listaSuciedad[j] = aux;


                        }



            }


        }



}


void mostrarAutoConMasHorasADedicar(eSuciedad* listaSuciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos, eCliente* listaClientes, int tamClientes)
{
    system("cls");
    int encontrado = 0;


        printf("Patente    Nombre del cliente    Parte a limpiar\n\n");

        for(int i = 0 ; i < tamAutos; i++)
        {

                if(listaAutos[i].idSuciedad == 5 || listaAutos[i].idSuciedad == 4 || listaAutos[i].idSuciedad == 3)
                {


                    mostrarAutoSucio(listaAutos[i],listaSuciedad,tamSuciedad,listaClientes,tamClientes);



                    encontrado = 1;


                }


            }


        if(encontrado)
        {

            printf("Estos son los autos a los cuales hay que dedicarle mas de 4 horas.\n\n");

        }
        if(!(encontrado))
        {

            printf("No se encontraron autos con trabajos largos.\n\n");


        }



}




void mostrarAutoConMenosHorasADedicar(eSuciedad* listaSuciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos, eCliente* listaClientes, int tamClientes)
{

 system("cls");
    int encontrado = 0;


        printf("Patente    Nombre del cliente    Parte a limpiar\n\n");

        for(int i = 0 ; i < tamAutos; i++)
        {

                if(listaAutos[i].idSuciedad == 1 || listaAutos[i].idSuciedad == 2)
                {


                    mostrarAutoSucio(listaAutos[i],listaSuciedad,tamSuciedad,listaClientes,tamClientes);



                    encontrado = 1;


                }


            }


        if(encontrado)
        {

            printf("Estos son los autos a los cuales hay que dedicarle 4  horas o menos.\n\n");

        }
        if(!(encontrado))
        {

            printf("No se encontraron autos.\n\n");


        }





}







