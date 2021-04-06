#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define TAMANO 4096
int main (int argc, char * argv [])
{
 int fd,cant;
// char *buffer = malloc (TAMANO);// puede estar definida asi o
 char *buffer ; 
  buffer = (char*) malloc (TAMANO);  
//  fd = open ("miself.c",O_RDONLY);
  if ((fd = open (argv[1],O_RDONLY))<0)
     perror("No se pudo abrir el archivo.\nManera de uso ./my-cat [archivo].\n");
 
 cant = read(fd,buffer,TAMANO);
 write(1,buffer,TAMANO); // a la mierda printf.
 close(fd);
 free(buffer);
 return 0;
}