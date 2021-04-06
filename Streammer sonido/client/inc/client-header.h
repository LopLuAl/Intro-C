#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include "sock-lib.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <linux/soundcard.h>
#include <sys/select.h>

#define STDIN 0

#define MAXDATASIZE 4096/* máxima cantidad de bytes que puede recibir en una transacción*/
/* segundos de audio a grabar */
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

void set_audio_params    (int fd);
int buscar_max           (int n1, int n2);
void reproducir          (int sockfd      );

