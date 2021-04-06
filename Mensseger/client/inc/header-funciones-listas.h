/**
* \file   funciones_listas.c 
* \brief  Contiene las funciones para operar los datos con una lista
* \Note: El archivo src-lista-lib.c es contiene el codigo para hacer la union y modificacion de los nodos. Esta compilada de forma estatica.
* \author Luciano Lopez
* \date   2016.12.5
*/
#ifndef AUX1
#define AUX1

#define  CANT_MAX 10

#include <string.h>
#include <header-listas-lib.h>  // Este el header que contendra  los prototipos de las funciones que unen y modifican los nodos de las listas

void 	imprimir	    (NODO *  head					                    );
NODO * 	agregarnodo	    (void						                        );
void 	recuperarlista	(NODO ** head					                    );
void 	salvarlista	    (NODO *  head			                            );
void 	crearlistas     (NODO ** head,char user [],char password [], TIPO t );

#endif
