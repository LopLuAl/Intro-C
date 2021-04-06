#include "header.h"

int busco_pid_de_la_opcion_elegida(char* usuario)
{
    FILE *F;
    int acumulada=0;
    char dato[20];
    char aux_renglon[20];
    char aux_nombre[10];
    char pid[10];
    int retval,i,k,largo,m,pid_int;
    int count_aux =0;
    
    if((F = fopen("./bin/usuarios_y_pid.info","r")) == NULL)
    {
        perror("No se pudo encontrar el archivo, Error en busco_pid_de_la_opcion_elegida.c : ");
        exit(1);
    }
    memset(dato,'\0',20);
    memset(pid,'\0',10);
    do
    {
        for(k=0;k<11;k++)                          // Separo nombre de usuario por nombre de usuario
            aux_nombre[k]=aux_renglon[k];   
        aux_nombre[10]='\0';
        largo=strlen(aux_nombre);
        largo++;
        
        if(!(strcmp(aux_nombre,usuario)))
        {
            for(m=0;largo<21;largo++,m++)
                pid[m]=aux_renglon[largo];
            pid_int=atoi(pid);
            return pid_int;
        }
        
        memset(aux_renglon,'\0',20);
        fseek(F,acumulada++,SEEK_SET);
        
        if((retval=(fread(dato,20,1,F))) == -1)
        {
            perror("Error en fread: ");
            exit(1);
        }
        for(i=0;dato[i]!='\n';i++)                  //aca separo un rengloon,..
            aux_renglon[i]=dato[i];                 //Copio los datos a otra variable separados por renglon
        //Cuando llegue al fin de archivo incrementa un contador pero necesito que recorra el bucle una o dos veces mas entonces si entra una vez va a seguir entrando varias veces, por eso la condicion de parada del do-while pregunta por count_aux que sea igual a 2, para vos Marotta refutador :P
        if(feof(F)!=0)
            count_aux++;
        
        acumulada=acumulada+i;
    }while(!(count_aux==2));
    return -1;                                      //Salio por error...
}