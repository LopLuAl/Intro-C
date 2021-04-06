#include "client-header.h"
void set_audio_params (int fd)
{
	int 	arg;		/* argumento para ioctl */
	int	status;		/* salida de ioctl */

/* seteamos los parametros de muestreo  */
	arg = SIZE;	   /* arg = Tamaño de muestra */
	status = ioctl(fd, SOUND_PCM_WRITE_BITS, &arg); 
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
	status = ioctl(fd, SOUND_PCM_WRITE_CHANNELS, &arg);
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

void reproducir (int sockfd)
{
    int fd,control,i=0;
    char buf_audio[buffsize];
    sleep(1);
    if (    (fd=open("/dev/dsp",O_RDWR))  < 0 )
        perror ("Error Abrir");
   
    printf("Reproduciendo\n");
    set_audio_params (fd);
    while(i==0)
    {
        if ((control = read (sockfd, buf_audio, buffsize)) == -1)
        {
            perror("error de lectura en el socket");
            exit(1);
        }
        if(control < 192000)
            i=1;
        control = write(fd, buf_audio, buffsize); /* reproduce */
        
        if (control != buffsize)
        {
            fprintf(stderr,"Error en función write, Código de error: %s\n",strerror (control)); 
        }
    }
    sleep(1);
}
