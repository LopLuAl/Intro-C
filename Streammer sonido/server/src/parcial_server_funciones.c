#include "server-header.h"

void leer_and_load(NODO **head, char path [])
{
    DIR *my_dir=NULL;
    struct dirent *my_dir1 = NULL;
    char aux [256];
    int  item, numero=0;    
    char * lista [10] = {};
    char * temp;
    int i, j;
    for(i=0;i<=20;lista[i++]='\0');
    if ((my_dir=opendir(path)) == NULL)
    {
        perror("No se puede abrir directorio");
        exit(1);
    }

    while(( my_dir1=readdir(my_dir))!=NULL)
    {
        strcpy(aux,my_dir1->d_name);
        item=discriminar(aux);
        if(item == 1)
        {
            lista[numero]=malloc(strlen(my_dir1->d_name));
            strcpy(lista[numero],my_dir1->d_name);
            numero++;
        }
    }

    for(i=0; i<(numero-1); i++) 
    {
        for(j=i+1; j<numero; j++) 
        {
            if(strcmp(lista[i], lista[j]) > 0) 
            {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    } 
    for(i=0;i<numero;i++)
    {
        crearlista(&head, lista[i], i);
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


void imprimir_temas (NODO * head,int sockdup )
{
    NODO * aux;
    aux=head;
    while(aux->ptr_next!=NULL)
    { 
        if ( ( write(sockdup,((DATO*)aux->info)->nombre,50))  < 0)
            perror("Error escribiendo");
        sleep(1);
        aux=aux->ptr_next;
    }

    if ( ( write(sockdup,((DATO*)aux->info)->nombre,50))  < 0)
            perror("Error escribiendo");
}

int imprimir_msg_bienvenida(int sockdup,NODO * head, char tema [50])
{
    char * mensajes[6]={"\nBienvenidos a Server\n","Seleccione una opccion\n","1-reproducir\n","2-mostrar\n", "Ingrese un caracter valido\n","Tema no encontrado :(\n" };
    char  buf2[100];
    int i,auxa,longitud,longitud2;
    NODO * aux;
    aux=head;
    for(i=0;i<4;i++)
    {
        if(    (   auxa=write(sockdup,mensajes[i],strlen(mensajes[i]) ) )   <0  )
            perror("Error");
    }
    if(    (   i=read(sockdup,buf2,100) )   <0  )
        perror("Error al escribir msg opcion rep");

    i=atoi(buf2);

    if(i==1)
    {
        i=-1;
        write(sockdup,"Introduzca el nombre de la cancion a reproducir",strlen("Introduzca el nombre de la cancion a reproducir"));
        
        if(    (   read(sockdup,buf2,100) )   <0  )
            perror("Error al escribir msg opcion rep");

        longitud=strlen(buf2);
        longitud--;
        
        while(aux->ptr_next!=NULL)
        {    
            longitud2=strlen(((DATO*)aux->info)->nombre);
            if (longitud==longitud2)
            {
                strcpy(tema,((DATO*)aux->info)->nombre);
                i=1;
            }
            aux=aux->ptr_next;
        }
        
        longitud2=strlen(((DATO*)aux->info)->nombre);
        
        if (longitud==longitud2)
        {
            strcpy(tema,((DATO*)aux->info)->nombre);
            i=1;
        }
        
        if(i==-1)
        {
            if(    ( auxa=  write(sockdup,mensajes[5],strlen(mensajes[5]) ) )   <0  )
                perror("Error");        
        }

    }
        
    if (i == 0)
    {
        if(    ( auxa=  write(sockdup,mensajes[4],strlen(mensajes[4]) ) )   <0  )
            perror("Error");
    }

    while(i==0)
    {
        if(    (   i=read(sockdup,buf2,100) )   <0  )
            perror("Error al escribir msg opcion rep");
        i=atoi(buf2);
    }
   
    return i;
}

void seleccion_and_play (char tema [], int sockdup)
{
    int fd_tema,control;
    char buf[LENGTH*RATE*SIZE*CHANNELS/8];
    
    if ((fd_tema=open(  tema,O_RDWR))   <   0)
    {
        perror ("Error al abrir archivo de musica");
        write(sockdup,"archivo no encontrado\n",strlen("archivo no encontrado\n"));
        exit(1);
    }
    
    write(sockdup,".",strlen("."));
    
    do{
      
        control = write(sockdup, buf, LENGTH*RATE*SIZE*CHANNELS/8);
        if (control != (LENGTH*RATE*SIZE*CHANNELS/8))
            fprintf(stderr,"Error en función write, Código de error: %s\n",strerror (control));
    }while((read(fd_tema,buf,LENGTH*RATE*SIZE*CHANNELS/8))>0);
    
    write(sockdup,"EOF",strlen("EOF"));
    printf("Termino el tema\n");
}

int discriminar_path_child(char  path [])
{
    int fd_conf,x,i;
    char buf [50];
    char * name  = "servidor.conf";
    char cantchilds_s [50];
    if((fd_conf=open(name,O_RDONLY))<0)
        perror("Problema al abrir el archivo: ");
    if(read(fd_conf,buf,50)<0)
        perror("Problema al leer el archivo: ");
    for(x=0;x!=50;x++)
    {
        if(buf[x]=='/')
        {

            for(i=0;buf[x]!='\n';x++,i++)
            {
                path[i]=buf[x];
            }
            for(i=0;buf[x]!='.';x++,i++)
            {
               cantchilds_s[i]=buf[x]; 
            }
        }
    }
    return (atoi(cantchilds_s));
}