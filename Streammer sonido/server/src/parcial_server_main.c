#include "server-header.h"
int cantchilds=0;
void my_sigchld (int sig)
{
	wait (0);
}

void sigalrm_hand (int senial)
{
    while ((waitpid(-1,NULL,WNOHANG))>0)
        cantchilds--;
    alarm (TIME);
    return;
}

void sigint_hand (int senial)
{
    printf("Leroooo :P\n");
    printf("Saliendo :( \n");
    exit(0);
    return;
}




int main ()
{
    int sockfd; 
    struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */
    int sockdup,opc;
    char tema [50]="aaa";
    char path [50]="";
    int max_cantidad_hijos;
    NODO * head = NULL;

    max_cantidad_hijos=discriminar_path_child(path);
    printf("path main: %s\n",path);
    printf("max_cantidad_hijos %d \n",max_cantidad_hijos);
    
    if (signal (SIGCHLD, my_sigchld)==SIG_ERR)
	{
		perror ("signal: ");
		exit (1);
	}
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
    leer_and_load(&head,path);
    while(1)
    {
        sockdup = Aceptar_pedidos (sockfd);
        if (cantchilds < max_cantidad_hijos) 
        {
            cantchilds++;
            if (!fork())
            {
                while(1)
                {  
                     opc =imprimir_msg_bienvenida(sockdup,head,tema);
                     switch(opc)
                     {
                        case 1:
                        {
                            strcat(path,"/");
                            strcat(path,tema);
                            seleccion_and_play (path,sockdup);
                            break;
                        }
                        case 2:
                        {
                            imprimir_temas (head,sockdup);
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                }
            }
            else // padre
            {
                
            }
        }
        else
        {
            if(    (   write(sockdup,"Server Busy",strlen("Server Busy")    ) )   <0  )
                    perror("Error al escribir msg Bienvenida");
        }
        
    }
    exit(0);
}
