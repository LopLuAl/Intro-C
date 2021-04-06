/*Funcion que manda el archivo que contiene solo los nombres de los usuarios conectados que se aloja
 en el servidor.*/ 

#include "header.h"

void funcion_mando_opciones_de_conexiones(int sockdup)
{
    FILE *F=NULL;
    char  * dato;
    int leido=1;
    int i = 0;
    char buf [10];
    
    dato=(char*)malloc(10);
    
//     printf("Leyendo archivo....\n");
    
    if((F = fopen("./bin/usuarios_conectados.info","r+")) == 0)
    {
        perror("No se pudo encontrar el archivo usuarios-conectado.info: ");
        exit(1);
    }
    leido=fread(dato,10,1,F); 					    //leo archivo de usuarios conectados
    if (leido==0)
        printf("No hay nadie conectado\n");
    while (!feof(F) && leido!=0)
    {
        write(sockdup,dato,10);					    //mando el archivo 11 a 11
        leido=fread(dato,10,1,F);  				    //leo archivo de usuarios conectados
    }   
    write(sockdup,"!",strlen("!")); 		        //mando comando  para indicar que termine de mandar el archivo
//     printf("termino de enviar\n");
    fclose(F);
    sleep(1);
  	
    while(1)
    {
        sleep(1);
//         printf("esperando que me digan que enviar....\n");
        i=read(sockdup,buf,10); 
        buf[i]='\0';
//         printf(" Recibi: %s \n", buf);
        if(0==strcmp(buf,"!"))
        {
//             printf("Leyendo archivo....\n");
            if((F = fopen("./bin/usuarios_conectados.info","r+")) == 0)
            {
                perror("No se pudo encontrar el archivo usuarios-conectado.info: ");
                exit(1);
            }
            leido=fread(dato,10,1,F); 					//leo archivo de usuarios conectados
            if (leido==0)
                printf("No hay nadie conectado\n");
            while (!feof(F) && leido!=0)
            {
//                 printf("cadena que mande por socket : %s \n",dato);
                write(sockdup,dato,10);					//mando el archivo 11 a 11
                leido=fread(dato,10,1,F);  				//leo archivo de usuarios conectados
            }   
            write(sockdup,"!",strlen("!")+1); 		    //mando comando  para indicar que termine de mandar el archivo
//             printf("termino de enviar\n");
            fclose(F);
        }
        if (0==strcmp(buf,"enter"))
            return;
    }
}
