#include "header-client.h"
int main(int argc, char * argv [])
{
 	int sockfd=0;                         
	char *logeo[2];
    if (argc < 2)
	{
		fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
		exit(1);
    }
    sockfd = conectar (argc, argv);                 /*Conectar al server*/
    check (sockfd);                                 /*Chequeo de conexion ppal*/
    logueo_grafico(logeo,sockfd);   
    /*Esta funcion contiene todo lo referido a el menu realizado con ncurses*/
    if (enviar_user_and_pass(logeo,sockfd)<0)
    {
        printf("Error al datos de usuarios\n");
        exit(0);
    }
    while (mostrar_lista_grafico(sockfd) < 0)
    {
        sleep(1);
        mostrar_lista_grafico(sockfd);
    }
 	close(sockfd);                        
	return 0;
}