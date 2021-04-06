#include "client-header.h"
int main(int argc, char * argv[])
{
	int sockfd;                    /*File Descriptor para sockets*/
	char buf[MAXDATASIZE];         /* Buffer donde se reciben los datos de read ()*/
    int max_fd;
    char buffer[256];
    int i=0,num;

    fd_set my_set, aux;
   
	if (argc < 2)
	{
		fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
		exit(1);
    }

	sockfd = conectar (argc, argv);

                                    
    FD_ZERO(&my_set);
    FD_SET(0,&my_set);
    FD_SET(sockfd,&my_set);
    
    max_fd = buscar_max(sockfd,STDIN);
    
    aux=my_set;
    
    while(1)
    {
        my_set=aux; 

        select(max_fd+1,&my_set,NULL,NULL,NULL);

        if (FD_ISSET(0, &my_set))
        {
            fgets(buffer,50,stdin);
            if ( (write(sockfd,buffer,50))<0)
                perror("Error escritura");
            num=atoi(buffer);
  
            
        }
        else if(FD_ISSET(sockfd,&my_set))
        {
             for(i=0;i!= 50;buf[i++]='\0');

            if (( num =read (sockfd, buf, 75)) == -1) // Leo el mensaje que me manda Ingrese nombre a reproducir
            {
                perror("error de lectura en el socket");
                exit(1);
            }
            if (strlen(buf)==(strlen(".")))
            {
        
                printf("Deberias escuchar Audio  \n");
                reproducir(sockfd);
                for(i=0;i!= 75;buf[i++]='\0');
            }
            printf("%s \n ",buf);

        }
    }    
    
	close(sockfd);
	return 0;
}