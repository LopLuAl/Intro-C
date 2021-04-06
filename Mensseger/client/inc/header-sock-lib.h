/**
* \file   header-sock-lib.h 
* \brief  Contiene los includes de la libreria socklib dada por la catedra * \y los prototipos de las funciones utilizadas por dicha libreria
* \author 
* \date   2016.12.5
*/


#ifndef AUX3
#define AUX3

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

#define PORT 3490	/* El puerto donde se conectará, servidor */
#define BACKLOG 10	/* Tamaño de la cola de conexiones recibidas */
#define MAX_CANT_CHILDS 14000 /* Cantidad máxima de childs que crearé*/
#define TIME 1
#define SIZE_BUFF 1024

int	conectar (int, char **);

int	Open_conection (struct sockaddr_in *); /* Función que crea la conexión*/

int	Aceptar_pedidos (int);	/* Función que acepta una conexión entrante*/

#endif
