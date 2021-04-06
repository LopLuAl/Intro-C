/**
* \file   header-client.h 
* \brief  Contiene los includes de las funciones de ncurses, listas y socket
* \author
* \date   2016.12.5
*/

/*Include para la libreria estatica de sockect*/
#include "header-sock-lib.h" 
/*Include de las funciones de listas, el include la libreria de listas que une los nodos esta dentro de este archivo*/
#include "header-funciones-listas.h"
/*Include de las funciones de ncurses para el menu de logueo o registro*/
#include "header-funciones-graf.h"

#include "header-funciones-client.h"


#define MAXDATASIZE 4096

void    	sigalrm_hand    (int senial);
void    	sigchld_hand    (int senial);
