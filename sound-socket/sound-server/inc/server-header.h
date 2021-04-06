#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/soundcard.h>
#include <ctype.h>


/* segundos de audio a grabar */
#define LENGTH 1
/* sampling rate = velocidad de muestreo del audio a la entrada*/
#define RATE 4000
/* sample size = Tamaño de muestra. Típicamente 8 o 16 bits */
#define SIZE 4
/* 1 = mono 2 = stereo */
#define CHANNELS 1


typedef struct nodo
{
    struct nodo * ptr_next;
    struct nodo * ptr_prev;
    void * info;
}NODO;

typedef struct dato
{
    char nombre[256];
    int nro;
}DATO;


void leer_and_load      (NODO **    head);
int  discriminar        (char *     ls);
void crearlista         (NODO ***   head, char *cancion, int numero);
void imprimir_temas     (NODO *     head, int sockdup);
void seleccion_and_play (NODO *     head, int sockdup);
void reproducir         (char * tema, int sockdup      );
void set_audio_params (int fd);