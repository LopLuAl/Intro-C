/*Funcion que se ejecuta en el server y verifica que la pass y el usuario esten registrados devuelve 1 si esta correcto y devuelve 0 si no encontro coincidencias.*/ 
/*Recibe contraseña y nombre de usuario*/
#include "header.h"
int funcion_check_us_pw(char usuario[],char contrasenia[]) 
{
    FILE *F=NULL;
    char oracion[100];
    char buf1[100];
    char buf2[100];
    char buf3[]={" "};
    int i=0;;
    int g=0;;
    memset(oracion,'\0',100);
    strcpy(buf1,usuario);
    strcat(buf1,buf3);
    strcpy(buf2,contrasenia);
    strcat(buf1,buf2);
//     printf("busco 1 = %s \n",buf1);
    if((F = fopen("./bin/usuarios_y_contrasenias.info","r")) == NULL) //Abrimos el archivo uqe contiene las contraseñas y los usuarios.
        perror("No se pudo encontrar el archivo");

    while (!feof(F))
{
    fread(oracion,100,1,F);
    for (i=0;oracion[i]!='\n' ;i++); //copio hasta el enter
    oracion[i]='\0';
    i++;
    g=g+i;
//     printf("busco 1 = %s \n",buf1);
    if(!strcmp(oracion,buf1))			
        {

            printf("Perfecto!!!\n");
            return 1;
}
    fseek(F,g,SEEK_SET); //Nos posicionamos al inicio del archivo.
     memset(oracion,'\0',100);
}
    fclose(F); // Cierro el file descriptor.
    printf("no encontre registro \n");
    return 0;
}


