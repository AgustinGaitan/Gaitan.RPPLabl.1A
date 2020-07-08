#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"
#include "menus.h"
#include "fechas.h"
#include "marcas.h"
#include "servicios.h"
#include "trabajos.h"
#include "colores.h"
#include "informes.h"
#include "suciedad.h"

#define TAMAUTO 10
#define TAMCOLOR 5
#define TAMMARCA 5
#define TAMSERV 4
#define TAMTRABAJO 10
#define TAMCLIENTE 10
#define TAMSUCIEDAD 5



int main()
{
    eAuto listaAutos[TAMAUTO] = {
    {1,"a1",1000,5000,1995,0,1,1},
    {2,"z2",1000,5003,1993,0,2,2},
    {3,"k9",1004,5004,2005,0,3,4},
    {4,"h3",1004,5001,2007,0,4,4},
    {5,"y9",1000,5000,1995,0,5,1},
    {6,"l5",1001,5000,2019,0,6,5},
    {7,"b5",1000,5003,2015,0,7,3}};



    eMarca listaMarcas[TAMMARCA] = {{1000,"Chevrolet"},{1001,"Fiat"},{1002,"Ford"},{1003,"Peugeot"},{1004,"Renault"}};
    eColor listaColores[TAMCOLOR] = {{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eServicio listaServicios[TAMSERV] = {{20000,"Lavado",250},{20001,"Pulido",300},{20002,"Encerado",400},{20003,"Completo",600}};
    eTrabajo listaTrabajos[TAMTRABAJO]  = {
    {1,"a1",20003,{23,6,2020},0},
    {2,"a1",20002,{22,6,2020},0},
    {3,"h3",20001,{23,6,2020},0},
    {4,"y9",20003,{25,6,2020},0},
    {5,"k9",20003,{26,6,2020},0},
    {6,"l5",20001,{26,6,2020},0},
    {7,"b5",20000,{27,7,2020},0}};



    eCliente listaClientes[TAMCLIENTE] = {
    {1,"Juan",'m',},
    {2,"Roberto",'m'},
    {3,"Alejandra",'f'},
    {4,"Karen",'f'},
    {5,"Jorge",'m'},
    {6,"Clara",'f'},
    {7,"Carla",'f'},
    {8,"Alberto",'f'},
    {9,"Diaz",'f'},
    {10,"Mauro",'f'}};

    eSuciedad listaSuciedad[TAMSUCIEDAD] ={{1,"Asientos",4},{2,"Ruedas",2},{3,"Vidrios",5},{4,"Llantas",5},{5,"Motor",12}};





    char confirmar;
    char confirmarInformes;
    int idAuto = 0;
    int flag = 1;              //CAMBIAR LA FLAG CAMBIAR SI NO SE HARDCODEA
    int idTrabajo = 0;
    eMarcaMasElegida marcaElegida[TAMMARCA];

    inicializarAutos(listaAutos,TAMAUTO);
   inicializarTrabajos(listaTrabajos,TAMTRABAJO);

    for(int i = 0; i < 7; i++)  //no inicializa los hardcodeados
    {

        listaAutos[i].isEmpty = 0;

    }
      for(int j = 0; j < 7; j++)   //no inicializa los hardcodeados
    {

        listaTrabajos[j].isEmpty = 0;

    }

    do
    {

        switch(menu())
        {

            case 'a':

                    idAuto++;
                    if(altaAuto(listaAutos,idAuto,TAMAUTO,listaMarcas,TAMMARCA,listaColores,TAMCOLOR,listaClientes,TAMCLIENTE))
                    {
                        flag = 1;
                    }

            break;
            case 'b':
                if(flag)
                {
                    if(modificarAuto(listaAutos,TAMAUTO,listaMarcas,TAMMARCA,listaColores,TAMCOLOR,listaClientes,TAMCLIENTE))
                    {
                        printf("Modificacion exitosa.\n\n");
                    }

                }
                else
                {
                    printf("Primero debe ingresar un vehiculo\n");
                }

            break;
            case 'c':
                 if(flag)
                {
                    bajaAuto(listaAutos,TAMAUTO,listaMarcas,TAMMARCA,listaColores,TAMCOLOR,listaClientes,TAMCLIENTE);

                }
                else
                {
                    printf("Primero debe ingresar un vehiculo\n");
                }

            break;
            case 'd':
                 if(flag)
                {

                    ordenarAutos(listaAutos,TAMAUTO,listaMarcas,TAMMARCA);
                    mostrarAutos(listaAutos,TAMAUTO,listaMarcas,TAMMARCA,listaColores,TAMCOLOR,listaClientes,TAMCLIENTE);
                    printf("\nOrden Ascendente\n");

                }
                else
                {
                    printf("Primero debe ingresar un vehiculo\n");
                }

            break;
            case 'e':
                system("cls");
                mostrarMarcas(listaMarcas, TAMMARCA);

            break;
            case 'f':
                system("cls");
                mostrarColores(listaColores, TAMCOLOR);

            break;
            case 'g':
                system("cls");
                mostrarServicios(listaServicios,TAMSERV);

            break;
            case 'h':
                 if(flag)
                {
                    idTrabajo++;
                    altaTrabajo(listaTrabajos, idTrabajo, TAMTRABAJO,listaServicios,TAMSERV,listaAutos,TAMAUTO,listaMarcas,TAMMARCA,listaColores,TAMCOLOR,listaClientes,TAMCLIENTE);
                }
                else
                {
                    printf("Primero debe ingresar un vehiculo\n");
                }

            break;
            case 'i':
                 if(flag)
                {
                    mostrarTrabajos(listaTrabajos, TAMTRABAJO, listaServicios, TAMSERV);

                }
                else
                {
                    printf("Primero debe ingresar un vehiculo\n");
                }

            break;
            case 'j':
                        switch(menuInformes())
                        {
                            case 1:
                                informarAutosColor(listaAutos,TAMAUTO,listaColores,TAMCOLOR,listaMarcas,TAMMARCA,listaClientes,TAMCLIENTE);
                                break;
                            case 2:
                                informarAutosMarca(listaAutos,TAMAUTO,listaColores,TAMCOLOR,listaMarcas,TAMMARCA,listaClientes,TAMCLIENTE);
                                break;
                            case 3:
                                informarAutosViejos(listaAutos,TAMAUTO,listaColores,TAMCOLOR,listaMarcas,TAMMARCA,listaClientes,TAMCLIENTE);
                                break;
                            case 4:
                                informarAutosSeparadosMarca(listaAutos,TAMAUTO,listaColores,TAMCOLOR,listaMarcas,TAMMARCA,listaClientes,TAMCLIENTE);

                                break;
                            case 5:
                                informarContadorColorMarca(listaAutos,TAMAUTO,listaColores,TAMCOLOR,listaMarcas,TAMMARCA,listaClientes,TAMCLIENTE);

                                break;
                            case 6:
                                inicializarMarcaMasElegida( marcaElegida, TAMMARCA );
                                informarMarcaMasElegida(listaAutos,TAMAUTO,listaMarcas,TAMMARCA,marcaElegida);
                                break;
                            case 7:
                                informarTrabajosAuto(listaAutos,TAMAUTO,listaTrabajos,TAMTRABAJO,listaServicios,TAMSERV);
                                break;
                            case 8:
                                informarImporteAuto(listaAutos,TAMAUTO,listaTrabajos,TAMTRABAJO,listaServicios,TAMSERV);
                                break;
                            case 9:
                                informarServicioRealizadoAuto(listaAutos,TAMAUTO,listaTrabajos,TAMTRABAJO,listaServicios,TAMSERV);
                                break;
                            case 10:
                                informarFechaServicios(listaTrabajos,TAMTRABAJO,listaServicios,TAMSERV);
                                break;
                            case 11:
                                    mostrarSuciedades(listaSuciedad, TAMSUCIEDAD);
                                break;
                            case 12:
                                asignarParteMasSuciaAuto(listaSuciedad,TAMSUCIEDAD,listaAutos,TAMAUTO,listaColores,TAMCOLOR,listaMarcas,TAMMARCA,listaClientes,TAMCLIENTE);

                                break;
                            case 13:

                                mostrarAutosConSuciedad(listaSuciedad,TAMSUCIEDAD,listaAutos,TAMAUTO,listaClientes,TAMCLIENTE);
                                break;
                            case 14:
                                mostrarAutosSeparadosPorSuciedad(listaSuciedad,TAMSUCIEDAD,listaAutos,TAMAUTO,listaClientes,TAMCLIENTE);
                                break;

                            case 15:

                                mostrarSuciedadesOrdenadasPorHora(listaSuciedad,TAMSUCIEDAD,listaAutos,TAMAUTO);
                                mostrarSuciedades(listaSuciedad, TAMSUCIEDAD);

                                break;
                            case 16:
                                mostrarAutoConMasHorasADedicar(listaSuciedad,TAMSUCIEDAD,listaAutos,TAMAUTO,listaClientes,TAMCLIENTE);
                                break;

                            case 17:
                                printf("Desea salir? 's' para afirmar, 'n' para negar: ");
                                fflush(stdin);
                                scanf("%c", &confirmarInformes);
                                break;

                        }


                break;
            case 'k':
                printf("Desea salir? 's' para afirmar, 'n' para negar: ");
                fflush(stdin);
                scanf("%c", &confirmar);

            break;




        }
        system("pause");
        system("cls");







    }while(confirmar != 's');






    return 0;
}
