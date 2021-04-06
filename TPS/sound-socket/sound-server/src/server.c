#include "sock-lib.h"
#include "server-header.h"
/*Variable Global: Solo porque no hay mas remedio!!!!*/
int cantchilds=0;
/*Es Global por vago, cambiar a local*/
int sockdup;

/*Server.c -> tiene el main, es el que crea el proceso hijo
  reproductor.c-> tiene todas las funciones de reproductoccion*/

void sigalrm_hand (int senial)
{
  while ((waitpid(-1,NULL,WNOHANG))>0)
    cantchilds--;
  alarm (TIME);
  return;
}


void sigint_hand (int senial)
{
//     if (senial == SIGINT)
    close(sockdup);
    exit(0);
    return;
}

int main ()
{
    int sockfd; 
    struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */

    NODO * head = NULL;
    /*
    if (signal(SIGINT, sigint_hand) == SIG_ERR )
    {
        perror ("signal : ");
        exit (1);
    }*/

    if (signal(SIGALRM, sigalrm_hand) == SIG_ERR )
    {
        perror ("signal: ");
        exit (1);
    }
    
    if ((sockfd = Open_conection (&my_addr)) == -1)
    {
            perror ("Falló la creación de la conexión"); 
            exit (1);
    }

    alarm (TIME);
    
    while(1)
    {
        sockdup = Aceptar_pedidos (sockfd);
        
        if (cantchilds < MAX_CANT_CHILDS) 
        {
            cantchilds++;
            if (!fork())
            {
                leer_and_load(&head);
                imprimir_temas(head,sockdup);
                seleccion_and_play (head,sockdup);
                exit(0);
            }
        }
        else
        {

        }
        
    }
    exit(0);
}
