#include "header.h"

void funcion_sockdup(int sockdup)
{		
    char buffer_conneccion_ok[]="Connecction OK";					//Buffer Conneccion ok.
    char buffer_recepcion_default[2];
    char *buffer_nombre =NULL;
    char *buffer_nombre_opcion_elegida =NULL;
    char *buffer_pw=NULL;
    char *FIFO_NAME = "./fifos/";
    
    pid_t pid =0 ;
    FIFO_NAME=malloc(20);
    
    strcpy(FIFO_NAME,"./fifos/");
    
    buffer_nombre=malloc(LARGO_USR_PW);
    buffer_pw=malloc(LARGO_USR_PW);
    buffer_nombre_opcion_elegida=malloc(LARGO_USR_PW);
    
    if(write(sockdup,buffer_conneccion_ok,strlen(buffer_conneccion_ok))==-1)	//Aviso que la Conneccion se completo.
    {
        perror ("Error en Write 1: "); 
        exit (1);
    }
    
    while(1)
    {
        if(read(sockdup,buffer_recepcion_default,1)==-1)                //Leo primera vez, me manda usuario
        {                                                               //registrado o nuevo.
            perror ("Error en Read 1: "); 
            exit (1);
        }
        printf("hola ?\n");
        buffer_recepcion_default[1]='\0';
        printf("El buff tiene %s\n",buffer_recepcion_default);
       
        if(!strcmp(buffer_recepcion_default,QUIERO_CONECTARME))			//Conectado
        {
//             printf("Alguien se quiere conectar...\n");
            funcion_leo_nombre_y_pw(sockdup,buffer_nombre,buffer_pw);	//Leo nombre y pw.
            if(!(funcion_check_us_pw(buffer_nombre,buffer_pw)))         //Checkea que este bien el us y la pass
            {
                printf(">>>>>>INGRESASTE MAL LOS DATOS<<<<<<\n");       // //**** IMPORTANTE*** ///VER QUE HACER SI PONGO MAL LOS DATOS.........
            }
            pid=getpid();
            aviso_que_me_llego(sockdup);
            funcion_agrega_a_conectados(buffer_nombre);					
//             printf("Alguien se quiere conectar2...\n");
            funcion_mando_opciones_de_conexiones(sockdup);
            funcion_reciba_opcion_elegida(sockdup, buffer_nombre_opcion_elegida);
            crear_propio_fifo(pid,FIFO_NAME);
//             printf("FIFO_NAME es: %s\n",FIFO_NAME);
//             printf("LlegueMañana\n");
            funcion_conecta_con_la_opcion_elegida(buffer_nombre_opcion_elegida, sockdup,FIFO_NAME);
        }
        if(!strcmp(buffer_recepcion_default,QUIERO_REGISTRARME))		//Requiere registrarse
        {
//             printf("Alguien se registro...\n");
            funcion_leo_nombre_y_pw(sockdup,buffer_nombre,buffer_pw);	//Leo nombre y pw.
            aviso_que_me_llego(sockdup);
            pid=getpid();
            funcion_registra(buffer_nombre, pid);
            funcion_login(buffer_nombre,buffer_pw);
        }
        else
            printf("Sali error en funcion_sockdup.c \n");
    }
    return;
}
void crear_propio_fifo(int user, char* FIFO_NAME)
{
    printf("pid y FIFO_NAME son %d %s\n",user,FIFO_NAME);
    
    char user_aux[10];
    char* fifo_aux;
    
    snprintf(user_aux,10,"%d",user);
    fifo_aux=(char*)malloc((strlen(FIFO_NAME))+(strlen(FIFO_NAME)));
    strcpy(fifo_aux,FIFO_NAME);
    strcat(fifo_aux,user_aux);
    mkfifo(fifo_aux,0666);
    strcpy(FIFO_NAME,fifo_aux);
}
