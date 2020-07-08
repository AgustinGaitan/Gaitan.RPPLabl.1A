#ifndef SUCIEDAD_H_INCLUDED
#define SUCIEDAD_H_INCLUDED
#include "autos.h"
#include "marcas.h"
#include "colores.h"
#include "clientes.h"


typedef struct
{

    int id;
    char descripcion[20];

}eSuciedad;


#endif // SUCIEDAD_H_INCLUDED




int asignarParteMasSuciaAuto(eSuciedad* suciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos, eColor* listaColores, int tamColores, eMarca* listaMarcas, int tamMarcas, eCliente* listaClientes, int tamClientes);




void mostrarSuciedad(eSuciedad listaSuciedad);





void mostrarSuciedades(eSuciedad* listaSuciedad, int tamSuciedad);



void mostrarAutosConSuciedad(eSuciedad* listaSuciedad, int tamSuciedad, eAuto* listaAutos, int tamAutos, eCliente* listaClientes, int tamClientes);


void mostrarAutoSucio(eAuto listaAutos, eSuciedad* listaSuciedad, int tamSuciedad, eCliente* listaClientes, int tamClientes);
