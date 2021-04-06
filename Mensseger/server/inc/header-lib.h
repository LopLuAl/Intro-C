#ifndef aux1
#define aux1

#define  CANT_MAX 15

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

#endif