/**
* \file   funciones_graf.c 
* \brief  Contiene las funciones generales de main-client.c
* \author 
* \date   2016.12.5
*/

#include "header-client.h"

/**
* \fn 		void check (int sockfd)
* \details  Chequea que la conexion este bien con el server sino, sale del programa
* \arg      int sockfd
* \return   void
* \author   Luciano Lopez
* \date     2016.09.6
*/
void check (int sockfd)
{
    int i;
    int numbytes;                  /*Contendrá el número de bytes recibidos por read () */
    char buf[MAXDATASIZE];         /* Buffer donde se reciben los datos de read ()*/
    memset(buf,'\0',MAXDATASIZE);
    if ((numbytes=read(sockfd,buf,MAXDATASIZE))<0)
        perror("Error al leer 1er mensaje: ");
   
    buf[numbytes] = '\0';
    
    if ((i=strcmp(buf,"Connecction OK"))==0)
    {
        return;
    }
    else
    {
        exit(0);
    }
}
int enviar_user_and_pass(char *dato [], int sockfd)
{
    char tipo[10];
    int numbytes;                  /*Contendrá el número de bytes recibidos por read () */
    char buf[MAXDATASIZE];         /* Buffer donde se reciben los datos de read ()*/
    memset(buf,'\0',MAXDATASIZE);
    printf("buf tiene esto =%s",buf);
    strcpy(tipo,dato[2]);
    if((write(sockfd,tipo,strlen(tipo)))<0)
        perror("Error mandando el tipo");
    if( (   write(     sockfd,dato[0],10    )   ) < 0   )
        perror("Error mandando el Usuario");
    if( (   write(     sockfd,dato[1],10   )   ) < 0   )
        perror("Error mandando  la Contrasenia");
       

    if ((numbytes=read(sockfd,buf,2))<0)//// IMPORTANTE MODIFICACION/////////    ->>>>  , LE PUSE 2 BITES AL READ PARA QUE LEA PORQUE SINO TARDA MUCHO EN LEER Y ESPERA TANTO QUE EL SERVER YA LE ESTA MANDANDO LAS OPCIONES DE CONECCION Y LE LLEGA EL OK MAS EL PRINCIPIO DEL NOMBRE DE EL PRIMER USUARIO, LOCO PERO PASA ESO, O LE PONEMS UN SLEEP O LE BAJAMOS LA CANTIDAD DE BYTES A LEER; PORQUE MAX DATA SIZE SON 4000 BITES.... MODIfICaCION BY TINCHOOO 
        perror("Error al leer 1er mensaje: ");
    buf[numbytes] = '\0';

    if (    (   numbytes=strcmp(buf,"OK")   )==0  )
        return 1;
    else
    {
        return -1;
    }
}
