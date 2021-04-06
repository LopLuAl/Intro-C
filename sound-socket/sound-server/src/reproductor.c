#include "server-header.h"

void leer_and_load(NODO **head)
{
    DIR *my_dir;
    struct dirent *my_dir1 = NULL;
    char aux [256];
    int  item, numero=0;
    my_dir=opendir(".");

    while(( my_dir1=readdir(my_dir))!=NULL)
    {
        strcpy(aux,my_dir1->d_name);
        item=discriminar(aux);
        if(item == 1)
        {
            crearlista(&head, aux, numero);
            numero++;
        }
    }
    return;
}
int discriminar(char * ls )
{
    int item = 0, i=0;
    for (i=0;ls[i]!='\0';i++)
    {
            if(ls[i]=='.')
                if(ls[i+1]=='r')
                    if(ls[i+2]=='a')
                        if(ls[i+3]=='w')
                            item=1;
                        
    }
  
    return item;
}

void crearlista     (NODO *** head, char *cancion, int numero)
{
    NODO * elemento;
    DATO * contenido;
    elemento= (NODO*)malloc(sizeof(NODO));
    contenido=(DATO*)malloc(sizeof(DATO));
    /*Le cargo los valores al nodo*/
    strcpy(contenido->nombre,cancion);
    contenido->nro=numero;
    /*Fin de carga de valores al nodo*/
    elemento->info=(void*)contenido;

    ////// ACA VIENE LA MAGIA ;) //////
    if( (**head )== NULL )
    {
        elemento->ptr_next = NULL;
        elemento->ptr_prev = NULL;
        **head = elemento;
        
    }
    else
    {
        (***head).ptr_prev=elemento;
        elemento->ptr_next=**head;
        elemento->ptr_prev=NULL;
        **head=elemento;
    }
    ////// ACA SE TERMINA LA MAGIA ;) //////    
    return;
}
void imprimir_temas (NODO * head, int sockdup)
{
    NODO * aux;
    aux=head;
    char message[30];
    while(aux->ptr_next!=NULL)
    {
        /*El Problema lo tengo aca, si le pongo los sleep llega con un delay horrible pero llega bien y si se los saco anda a veces bien y la mayoria de las veces mal (diria todas)*/
        
        if (  write (sockdup,((DATO*)aux->info)->nombre , sizeof (((DATO*)aux->info)->nombre))  < 0  )
            perror("Error en la escritura");
        //sleep(1);
        sprintf(message,"%d",((DATO*)aux->info)->nro);
        if ( write (sockdup, message, sizeof (message)) < 0 )
            perror("Error en la escritura");
        //sleep(1);
        aux=aux->ptr_next;
    }
    if ( write (sockdup,((DATO*)aux->info)->nombre , sizeof (((DATO*)aux->info)->nombre)) < 0)
        perror("Error en la escritura");
    //sleep(1);
    sprintf(message,"%d",((DATO*)aux->info)->nro);
    if ( write (sockdup, message, sizeof (message)) < 0)
        perror("Error en la escritura");
               
}
void seleccion_and_play (NODO *     head, int sockdup)
{
    int seleccion;
    NODO * aux;
    aux=head;
    char message [] = "\nSelecione un tema para escuchar\n";
    char in [10];
    int fd_tema,control;
    unsigned char buf[LENGTH*RATE*SIZE*CHANNELS/8];
    if ( write (sockdup, message, sizeof (message)) < 0)
        perror("Error en la escritura");
    read(sockdup,in,sizeof(in));
    seleccion=atoi(in);
    printf("selecciono %d \n",seleccion);
    while(  ((DATO*)aux->info)->nro != seleccion )
        aux=aux->ptr_next;
//     printf("Tema seleccionado: %d\t%s\n",((DATO*)aux->info)->nro,((DATO*)aux->info)->nombre);    
    printf("Entrando en la funcion reproducir \n");
//     reproducir(((DATO*)aux->info)->nombre, sockdup);
    
    if (    (fd_tema=open(((DATO*)aux->info)->nombre,O_RDWR) ) < 0 )
        perror ("Error al abrir archivo de musica");

    printf("Reproduciendo\n");
   
    while(1)
    {
        control=read(fd_tema,buf,sizeof(buf));
        printf("lei algo\n");
        /*Verificando si lei todo*/
        printf("Verificando\n");
        if (control!=sizeof(buf))
            perror("Error control:");
        printf("Verificado\n");
        control = write(sockdup, buf, sizeof(buf)); /* reproduce */
        printf("MAnde algo\n");
        sleep(1);
        if (control != sizeof(buf))
        {
            fprintf(stderr,"Error en función write, Código de error: %s\n",strerror (control)); 
        }
    }
}
void reproducir         (char * tema, int sockdup      )
{
    
}