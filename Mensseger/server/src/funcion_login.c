/*Funcion que se ejecuta en el server y registra en un archivo el usuario y la contraseña del cliente.*/ 
/*Recibe contraseña y nombre de usuario*/
#include "header.h"
void funcion_login(char usuario[],char contrasenia[]) 
{
//   printf("Llegue\n");
//          printf("la pw es: %s\n",contrasenia);
//       printf("el us es: %s\n",usuario);
    FILE *F=NULL;
    if((F = fopen("./bin/usuarios_y_contrasenias.info","r+w+")) == NULL) //Abrimos el archivo uqe contiene las contraseñas y los usuarios.
    perror("No se pudo encontrar el archivo");
    fseek(F,0,SEEK_END); //Nos posicionamos al final del archivo.
    if(-1== fwrite("\n",1,1,F))// Lo separo en reglones. 
    {
	perror("Error escribiendo mensaje en socket");
	exit (1);
    }   
    if(-1== fwrite(usuario,strlen(usuario),1,F))//Escribo el usuario.
    {
	perror("Error escribiendo mensaje en socket");
	exit (1);
    }   
    if(-1==  fwrite(" ",1,1,F)) // Separo el usuario de la contraseña con un espacio.
    {
	perror("Error escribiendo mensaje en socket");
	exit (1);
    }   
    if(-1==     fwrite(contrasenia,strlen(contrasenia),1,F)) // Escribo la contraseña
    {
	perror("Error escribiendo mensaje en socket");
	exit (1);
    }   
//        printf("voy a registrar el usuario y pass:\n");
//        printf("la pw es: %s\n",contrasenia);
//        printf("el us es: %s\n",usuario);
    fclose(F); // Cierro el file descriptor.
    return;
}
