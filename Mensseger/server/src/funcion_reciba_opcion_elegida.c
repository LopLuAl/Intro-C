#include "header.h"

void funcion_reciba_opcion_elegida(int sockdup, char* buffer_nombre_opcion_elegida)
{
  if(read(sockdup,buffer_nombre_opcion_elegida,LARGO_USR_PW)==-1)	//Leo primera vez, me manda usuario
  {									//registrado o nuevo.
    perror ("Error en Read 1: "); 
    exit (1);
  }
}