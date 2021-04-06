/*Funcion que se ejecuta en el server y registra en un archivo el usuario y el pid del proceso hijo que atiende pedidos
 de ese usuario.*/ 
/*Recibe pid y nombre de usuario*/

#include "header.h"

void funcion_registra(char* usuario,int pid)
{
    FILE *F=NULL;
    char buff[100];
    memset(buff,'\0',100);
    if((F = fopen("./bin/usuarios_y_pid.info","a+")) == NULL)
        perror("No se pudo encontrar el archivo");
    fseek(F,0,SEEK_END); 
    if(-1== fwrite(usuario,LARGO_USR_PW,1,F))
    {
      perror("Error escribiendo mensaje en socket");
      exit (1);
    }   
    if(-1==  fwrite(" ",1,1,F))
    {
      perror("Error escribiendo mensaje en socket");
      exit (1);
    }   
    snprintf(buff,100,"%d",pid);
    if(-1==     fwrite(buff,strlen(buff),1,F))
    {
      perror("Error escribiendo mensaje en socket");
      exit (1);
    }   
    if(-1== fwrite("\n",1,1,F))
    {
      perror("Error escribiendo mensaje en socket");
      exit (1);
    }  
    fclose(F);
}