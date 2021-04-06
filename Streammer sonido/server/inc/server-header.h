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
#include "sock-lib.h"

#define LENGTH 1
/* sampling rate = velocidad de muestreo del audio a la entrada*/
#define RATE 48000
/* sample size = Tamaño de muestra. Típicamente 8 o 16 bits */
#define SIZE 16
/* 1 = mono 2 = stereo */
#define CHANNELS 2
/*Calcula dinámicamente el tamaño del buffer de audio*/
#define buffsize LENGTH*RATE*SIZE*CHANNELS/8
/* segundos de audio a grabar */


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


void leer_and_load          (NODO **    head ,char path []                          );
int  discriminar            (char *     ls                              );
void crearlista             (NODO ***   head, char *cancion, int numero );
void imprimir_temas         (NODO *     head, int sockdup               );
void reproducir             (char *     tema, int sockdup               );
int imprimir_msg_bienvenida (int sockdup        , NODO * head  , char tema [50]                     );
void seleccion_and_play (char tema [], int sockdup);
int discriminar_path_child(char  path []);
void my_sigchld (int sig);
void sigalrm_hand (int senial);
void sigint_hand (int senial);
