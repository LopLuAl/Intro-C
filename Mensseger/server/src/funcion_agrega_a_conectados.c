#include "header.h"

void funcion_agrega_a_conectados(char* buffer_nombre)
{
  FILE *F= NULL;
//   printf("buffer_nombre es: %s\n",buffer_nombre);
  if((F = fopen("./bin/usuarios_conectados.info","a+")) == NULL)		//Abro archivo conectados,
  {
    perror("No se pudo encontrar el archivo usuarios_conectado.info: ");
    exit(1);
  }
  fseek(F,0,SEEK_END);
  if(fwrite(buffer_nombre,LARGO_USR_PW,1,F)==-1)			//Escribo en archivo conectados,
  {
    perror ("Error en Write 3: "); 
    exit (1);
  }
//   if(fwrite("\n",1,1,F)==-1)			//Escribo en archivo conectados,
//   {
//     perror ("Error en Write 3: "); 
//     exit (1);
//   }
  fclose(F);
  return;
}