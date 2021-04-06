#include "sock-lib.h"
#include <sys/select.h>
/* According to earlier standards */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/soundcard.h>
#include <ctype.h>
#include <stdlib.h>

/* segundos de audio a grabar */
#define LENGTH 1
/* sampling rate = velocidad de muestreo del audio a la entrada*/
#define RATE 4000
/* sample size = Tamaño de muestra. Típicamente 8 o 16 bits */
#define SIZE 4
/* 1 = mono 2 = stereo */
#define CHANNELS 1
#define MAXDATASIZE 4096/* máxima cantidad de bytes que puede recibir en una transacción*/
#define STDIN 0

void set_audio_params (int fd)
{
    int arg;		/* argumento para ioctl */
    int	status;		/* salida de ioctl */

/* seteamos los parametros de muestreo  */
    arg = SIZE;	   /* arg = Tamaño de muestra */
    status = ioctl(fd, SOUND_PCM_WRITE_BITS, &arg); // Escribir en el disp de audio a grabar el tamaño de la muestra. en arg me devuelve de cuanto es lo que realemnte me grabo 
/* SOUND_PCM_WRITE_BITS es la macro que escribe en la placa de sonido (a través del driver por supuesto), el valor del tamaño de muestra en bits que seteamos en la variable arg, cuyo puntero se provee como tercer argumento a ioctl().
La interfaz genérica de audio manejada por streams traduce comandos generales a los comandos particulares para el hardware de modo transparente al programador */
    if (status == -1) 
            perror("Error con comando SOUND_PCM_WRITE_BITS");
/* El hecho que ioctl devuelva error no quiere decir que no se haya configurado el parámetro que se quiso programar.*/
    if (arg != SIZE)
/* Por lo general la variable pasada por referencia vuelve con el valor programado si el original no estaba entre los posibles valores del parámetro que se quiso configurar. Por ejemplo, Tamaño de muestra: si arg hubiese ido en un valor por ejemplo 13, o 15, seguramente no coicidiría con los valores posibles para configurar el conversor A/D de la placa de sonido. 
En tal caso el driver programa al valor mas cercano al argumento recibido,modifica la variable recibda como referencia al valor, para que el programa que lo envió pueda saber el valor con el que se configuró, y hace que la función devuelva -1, para que se pueda analizar el error y tomar nota del valor configurado finalmente. */
            fprintf (stderr,"Tamaño de muestras no soportado. Se programó %d\n",arg);

    arg = CHANNELS;  /* mono o stereo */
    status = ioctl(fd, SOUND_PCM_WRITE_CHANNELS, &arg); // cantidad de canales.
    if (status == -1)
            perror("Error en comando SOUND_PCM_WRITE_CHANNELS");
    if (arg != CHANNELS)
            fprintf (stderr,"Cantidad de canales no soportado. Se programó %d\n",arg);

    arg = RATE;	   /* Velocidad de Muestreo */
    status = ioctl(fd, SOUND_PCM_WRITE_RATE, &arg);
    if (status == -1)
            perror("Error en comando SOUND_PCM_WRITE_RATE");
    if (arg != RATE)
            fprintf (stderr,"Velocidad de muestreo no soportada. Se programó %d\n",arg);

    return;
}
int buscar_max (int n1, int n2)
{
    int  mayor = 2;
    
    if (n1>mayor)
    {
        mayor=n1;
        return mayor;
    }
    else if(n2>mayor)
    {
        mayor=n2;
        return mayor;
    }
    else
        return mayor;
}
int main(int argc, char * argv[])
{
	int sockfd;  /*File Descriptor para sockets*/
	int max_fd;
	int numbytes;/*Contendrá el número de bytes recibidos por read () */
        int flag= 0;
        fd_set my_set, aux;
	char bufe[MAXDATASIZE];  /* Buffer donde se reciben los datos de read ()*/
        int fd, fd_tema,control;
        unsigned char buf[LENGTH*RATE*SIZE*CHANNELS/8];
        char buffer [10];
        int num;
	if (argc < 2)
	{
		fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
		exit(1);
        }
        
        sockfd = conectar (argc, argv);
        
        max_fd = buscar_max(sockfd,STDIN);
        FD_ZERO(&my_set);
        FD_SET(0,&my_set);
        FD_SET(sockfd,&my_set);
      
        aux=my_set;
        while(1)
        {
            my_set=aux;
            
            select(max_fd+1,&my_set,NULL,NULL,NULL);
           
            if (FD_ISSET(0, &my_set))
            {
                fgets(buffer,sizeof(buffer),stdin);
                num=atoi(buffer);
                while(num > 9  || num < 0)
                {
                    printf("Ingrese un caracter entre 0 y 10\n");
                    fgets(buffer,sizeof(buffer),stdin);
                    num=atoi(buffer);
                
                }
                write(sockfd,buffer,sizeof(buffer));
                flag=1;
                  
            }
            else if(FD_ISSET(sockfd,&my_set))
            {
                if(flag==1)
                {
                    if (    (fd=open("/dev/dsp",O_RDWR))  < 0 )
                        perror ("Error Abrir");
                    set_audio_params (fd);
                    printf("Parametros Seteados y dispositvo de audio abierto \n");
                }
                if ((numbytes = read (sockfd, bufe, MAXDATASIZE)) == -1)
                {
                    perror("error de lectura en el socket");
                    exit(1);
                }
                if (flag == 1)
                {
                    printf("Reproduciendo\n");
                    while(1)
                    {
                        control = write(fd, buf, sizeof(buf)); 
                        if (control != sizeof(buf))
                        {
                            fprintf(stderr,"Error en función write, Código de error: %s\n",strerror (control)); 
                        }
                    }
                }
                
                bufe[numbytes] = '\0';
                printf("%s \n",bufe);
                
//                 if (write(sockfd,"ok",2)<0)
//                     perror("Estamos en el horno");
    
            }
           
        }
	/* Devolvemos recursos al sistema */
	close(sockfd);
	return 0;
}