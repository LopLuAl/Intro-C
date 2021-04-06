/**
* \file   header-listas-lib.h 
* \brief  Contiene los prototipos de las funciones de armado de listas de la libreria liblistas.a
* \author 
* \date   2016.12.5
*/

#define  CANT_MAX 10

#include <stdio.h>
#include <stdlib.h>
#include <variables.h>



typedef struct nodo
{
    void *info;
    struct nodo *prev;
    struct nodo *next;
}NODO;

typedef enum
{
    SIMPLE,
    DOBLE
}TIPO;

void agregoinicio   (NODO**head , NODO *  dato, TIPO t     );
void agregofin      (NODO**head , NODO *  dato, TIPO t     );
void insertnodoleft (NODO *nprev, NODO *  dato, NODO *head );
void borrarnodo     (NODO *d    , NODO ** head             );

