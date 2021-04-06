#include "header.h"

void funcion_leo_nombre_y_pw (int sockdup, char* buffer_nombre, char* buffer_pw)
{
  
//     buffer_nombre=malloc(10);
//     buffer_pw=malloc(10);
    if(read(sockdup,buffer_nombre,10)==-1)			//Leo el nombre.
  {
    perror ("Error en Read 3, funcion_leo_nombre_y_pw: "); 
    exit (1);
  }	
  printf("separo\n");
  if(read(sockdup,buffer_pw,10)==-1)				//Leo la pw del usuario.
  {
    perror ("Error en Read 4, funcion_leo_nombre_y_pw: "); 
    exit (1);
  }	
//   printf("Aux es: %d\n",aux);
//   printf("nombre: %s\n",buffer_nombre);
//   printf("nombre: %s\n",buffer_pw);
}
