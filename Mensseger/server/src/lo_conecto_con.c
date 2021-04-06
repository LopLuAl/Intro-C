#include "header.h"

void lo_conecto_con(char* buffer_nombre_opcion_elegida, char * FIFO_NAME, int sockdup)
{
//     printf("LLeguehoy\n");
    char buff_recibido[100];		  //Con este leo lo que quiero... max 150 caract.
    int read_val,aux_largo,readval_2;
    char auxx[10];
    
    int fd_1;
    int fd_2;
    char FIFO_NAME_2[]="./fifos/";    //fifo del otro cliente
    
    int maxfd;				          //Variable que utilizaremos para almacenar el mayor fd a controlar
    int selectRetval;			      //Variable que utilizaremos para almacenar el valor retornado por select
    int pid_elegido;
    
    fd_set rfds,rfdsAux;              //Variables que utiliza el select para hacer el control de los fd
    FD_ZERO(&rfds);                   //Seteo los file descriptors a "watchear" (controlar)
    
    memset(buff_recibido,'\0',100);
    
    if((fd_1=open(FIFO_NAME,O_RDWR))==-1)
    {
        perror("Error en open1: ");
        exit(1);
    }
    
//     printf("buffer_nombre_opcion_elegida es: %s\n",buffer_nombre_opcion_elegida);
    pid_elegido=busco_pid_de_la_opcion_elegida(buffer_nombre_opcion_elegida);
//     printf("el pid_elegido es: %d\n",pid_elegido);
    sprintf(auxx,"%d",pid_elegido);
//     printf("el pid_elegido es: %s\n",auxx);
    strcat(FIFO_NAME_2,auxx);
//     printf("FIFO_NAME_2 es: %s\n",FIFO_NAME_2);
    while((fd_2=open(FIFO_NAME_2,O_RDWR))==-1)
      usleep(10);
    
    maxfd = fun_max_fds(2, fd_2, sockdup);
//     printf("Llegue\n");							//NO LLEGA ACAAAAA

    FD_SET(sockdup, &rfds); 		      //Recordar que el 0 es stdin (teclado por default)
    FD_SET(fd_2,&rfds);

    rfdsAux = rfds;                       //Guardo las settings en un auxiliar dado que en cada loop se desconfigura
 
    while(1)
    {
        rfds = rfdsAux;		//recargo la información del rfds (por "read file descriptor")
        selectRetval = select(maxfd+1, &rfds, NULL, NULL, NULL);
        if (-1 == selectRetval)
            perror("select()");
        else
        {
            if(FD_ISSET(sockdup,&rfds))	
            {					//Aca tengo que pasar la info por fifo
//                 printf("Entre1\n");
                if((read_val=(read(sockdup,buff_recibido,100)))==-1)    //leo sockdup info que quiere mandar cliente
                {
                    perror("Error en read1: ");
                    exit(1);
                }
                if(write(fd_1,buff_recibido,read_val)==-1)              //La mando al fifo para que el otro cliente la lea
                {
                    perror("Error en write: ");
                    exit(1);
                }
//                 printf("Llegue1\n");
            }
            if(FD_ISSET(fd_2,&rfds))
            {
//                 printf("Entre2\n");
                if((readval_2=read(fd_2,buff_recibido,100))==-1)	     //leo fifo 
                {
                    perror("Error en read2: ");
                    exit(1);
                }
                aux_largo=strlen(buff_recibido);
                buff_recibido[aux_largo]='\0';
//                 printf("buffer_recibido es: %s\n",buff_recibido);
                if(write(sockdup,buff_recibido,readval_2)==-1)          //le mando por socket al cliente la info recibida en 
                {						                                // el fifo.
                    perror("Error en write2: ");
                    exit(1);
                }
//                 printf("Sali 2\n");
            }
        }
    }
    close(fd_1);					                                     /* Devolvemos recursos al sistema */
    close(fd_2);					                                     /* Devolvemos recursos al sistema */
} 