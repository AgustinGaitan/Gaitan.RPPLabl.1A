#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "utn.h"


char menu()
{
    char opcion;
    printf("**** Menu Principal ****\n\n");
    printf("a.Alta auto.\n");
    printf("b.Modificar auto.\n");
    printf("c.Baja auto.\n");
    printf("d.Listar autos.\n");
    printf("e.Listar marcas.\n");
    printf("f.Listar colores.\n");
    printf("g.Listar servicios.\n");
    printf("h.Alta trabajo.\n");
    printf("i.Listar trabajos.\n");
    printf("j.Informes.\n");
    printf("k.Salir.\n\n");
    printf("Ingrese la opcion que desea: ");
    fflush(stdin);
    scanf("%c", &opcion);


    return opcion;

}

int menuModificar()
{
    system("cls");
    int opcion;
    printf("**** Menu Modificar ****\n\n");
    printf("1.Modificar color.\n");
    printf("2.Modificar modelo.\n");
    printf("3.Salir.\n");
    utn_getEntero(&opcion,3,"Ingrese la opcion que desea: ", "Error. Ingrese un numero valido.\n",1,3);

    return opcion;
}


int menuInformes()
{
    system("cls");
    int opcion;
    printf("**** Menu de informes ****\n\n");
    printf("1.Mostrar autos de un color a seleccionar.\n");
    printf("2.Mostrar autos de una marca seleccionada.\n");
    printf("3.Mostrar autos mas viejos (del 2000 para abajo).\n");
    printf("4.Mostrar autos separados por marca.\n");
    printf("5.Cantidad de autos de una marca y color a seleccionar.\n");
    printf("6.Mostrar la o las marcas mas elegidas por los clientes.\n");
    printf("7.Trabajos que se le hicieron a un auto a seleccionar.\n");
    printf("8.Suma de importes de un auto a seleccionar.\n");
    printf("9.Mostrar los autos al que se le dio un servicio a seleccionar.\n");
    printf("10.Mostrar servicios realizados en una fecha a ingresar.\n");
    printf("11. Mostrar la lista de suciedades posibles.\n");
    printf("12. Asignarle parte a limpiar a un vehiculo.\n");
    printf("13. Mostrar vehiculos con partes a limpiar asignadas.\n");
    printf("11.Salir.\n");
    utn_getEntero(&opcion,3,"Ingrese la opcion que desea: ", "Error. Ingrese un numero valido.\n",1,16);

    return opcion;


}

