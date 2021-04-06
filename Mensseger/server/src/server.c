/**
 * DOXYGEN COMMENTS
 *
 * @file   main.c
 *
 * @Author Fuschetto, Marotta, Lopez.
 *
 * @date   05/12/2016 [DD/MM/YYYY]
 *
 * @brief  
 *
 * @Comentarios: Sv generico con select
 * 		 Trapeo de señal ctrl-c DESACTIVADO para poder trabajar en signals.c
 *
 * @todo   What's to do?
 */

/* **************************************************************** */
/*                              INCLUDEs                            */

    #include "header.h"

/* **************************************************************** */
/*                              DEFINEs                             */

// Add private define's here

/* **************************************************************** */
/*                              MACROs                              */

// Add private macro's here

/* **************************************************************** */
/*                              GLOBALs                             */
/*Variable Global: Solo porque no hay mas remedio!!!!*/
    int cantchilds=0;

/* **************************************************************** */
/*                             DATA TYPEs                           */

// Add structure's, enum's, typedefs, etc, here

/* **************************************************************** */
/*                               CODE                               */

void sigalrm_hand (int senial)
  {
    while ((waitpid(-1,NULL,WNOHANG))>0)
      cantchilds--;
    alarm (TIME);
    return;
  }

int main (void)
{
    int sockfd; 			/* File Descriptor del socket por el que el servidor "escuchará" conexiones*/
    int sockdup;
    struct sockaddr_in my_addr;		/* contendrá la dirección IP y el número de puerto local */
    
    if ((sockfd = Open_conection (&my_addr)) == -1)
    {
            perror ("Falló la creación de la conexión"); 
            exit (1);
    }
    
    if (signal(SIGALRM, sigalrm_hand) == SIG_ERR )
    {
      perror ("signal");
      exit (1);
    }
  
    alarm (TIME);
    while(1)
    {
      printf("Espero pedidos...\n");
      sockdup = Aceptar_pedidos (sockfd);			// Aca se pone un fork () y se lo convierte en un server concurrente
      if (cantchilds < MAX_CANT_CHILDS) 			// En tal caso, lo que sigue es el child process
      {								// El padre vuelve a Aceptar_pedidos
	  cantchilds++;
	  if (!fork())
	  {
	      funcion_sockdup(sockdup);
	      exit(0);
	  }
      }
        close(sockdup);
    }
	exit(0);
}