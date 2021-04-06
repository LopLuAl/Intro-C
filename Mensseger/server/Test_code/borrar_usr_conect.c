 #include"./inc/header.h"
// #include"./inc/variables.h"
#include <stdlib.h>
#include <stdio.h>
#include "./inc/header-lib.h"

int main (void)
{
    NODO *head;
    NODO *recorrea;
    char *s;
    recuperarlista(&head);
     recorrea=head;
// 	printf("Introduzca el Usuario a borrar\n");
//     scanf("%s",s);
//     do
//     {
//         printf("Contenido: %s\n",((DATO*)recorre->info)->user);
//         recorre=recorre->next;
//     }while((recorre->next!=NULL) || (strcmp(((DATO*)recorre->info)->user,s)!=0) );
//     
//     borrarnodo(recorre, &head);
    imprimir(head);
    return 0;
}
void imprimir (NODO *head)
{

   
    NODO * recorre;
//    	#ifdef DEBUG
    int j=0;
//  	#endif
    recorre=head;
	printf("\n");
    do
    {
			
		j++;	
		printf("\nNodo numero %d\n",j);
		printf("Direccion actual del  nodo %p\n",recorre);
		printf("Direccion actual del  nodo anterior %p\n",recorre->prev);
		printf("Direccion del proximo nodo %p\n",recorre->next);
		

		printf("Contenido: %s\n",((DATO*)recorre->info)->user);
		printf("Contenido: %s\n",((DATO*)recorre->info)->passwd);
		recorre=recorre->next;
    }while((recorre->next!=NULL));//|(j==3)
    
	
	j++;	
	printf("\nNodo numero %d\n",j);
    printf("Direccion actual del  nodo %p\n",recorre);
    printf("Direccion actual del  nodo anterior %p\n",recorre->prev);
    printf("Direccion del proximo nodo %p\n",recorre->next);

//     printf("Contenido: %d\n",((DATO*)recorre->info)->edad);
}

/**
* \fn 		NODO * agregarnodo()
* \details  Reserva espacio en memoria para el la estructura de tipo NODO y para la estructura de tipo DATO 
* \arg      void
* \return   NODO * direccion del nodo con su dicha estructura contenedora de datos
* \author   Luciano Lopez
* \date     2016.09.6
*/

NODO * agregarnodo()
{
    NODO *nuevo_dato;                                 // Declaro puntero del tipo NODO
    DATO *datos;  

    nuevo_dato   =  (NODO*) malloc( sizeof(NODO) );   // Reservas memoria dinamica del tamaño de NODO, la casteo a tipo NODO y la direccion que me devuelve la guardo en aux
    datos        =  (DATO*) malloc( sizeof(DATO) );   // Reservas memoria dinamica del tamaño de DATO, la casteo a tipo DATO y la direccion que me devuelve la guardo en datos
    nuevo_dato->info =(void*)datos;
   // printf("Usuario: %s\nContraseña: %s\n");
    return nuevo_dato;
}

/**
* \fn 		void recuperarlista(NODO ** head)
* \details  Recupera la lista de un archivo y la pone de vuelta en la memoria heap
* \arg      NODO **  head Direccion del puntero de cabeza
* \return   void
* \author   Luciano Lopez
* \date     2016.09.6
*/
void recuperarlista(NODO ** head)
{
  FILE *F;
  char user     [10];
  char password [10];

  if((F = fopen("./usuarios_conectados.info","a+")) == NULL)
//     a+ Abre el archivo para lectura y escritura. La lectura o escritura comenzará al final del fichero, sin afectar al contenido previo. Si el fichero no existe se intenta crear.
      perror("No se pudo encontrar el archivo");
  
  while(!feof(F))
  {
      fread( user,sizeof(user),1,F);
//       fread(password,sizeof(password),1,F);
      crearlistas(head,user,password,DOBLE );
//       darle la opcion de simple
  }
  
}

/**
* \fn 		void salvarlista(NODO * head)
* \details  Guarda la lista en un archivo
* \arg      NODO *  head puntero de cabeza
* \return   void
* \author   Luciano Lopez
* \date     2016.09.6
*/

void salvarlista(NODO * head)
{
	FILE *fp;
 	NODO * P;
 	fp = fopen ("./bin/fichero.dat", "a+" );
	
  	P=head; 	
 	
	while(P!=NULL)
  	{	
		fwrite(&(((DATO*)P->info)->user),sizeof((((DATO*)P->info)->user)),1,fp);
// 		(dato)=(((DATO*)P->info)->contrasenia);
		//fprintf(fp,"%c\n",dato);
		fwrite(&(((DATO*)P->info)->passwd),sizeof((((DATO*)P->info)->passwd)),1,fp);		        
		P=P->next;
 	}
	fclose ( fp );
}

/**
* \fn 		void crearlistas(NODO ** head,int dato, TIPO t )
* \details  Reserva el espacio en memoria de los nodos, inicializa el valor del dato del nodo y los entrelaza
* \arg      NODO **  head Direccion del puntero de cabeza
*           int dato Contenido del nodo
*           TIPO t   Elijo el tipo de lista SIMPLE o DOBLE
* \return   void
* \author   Luciano Lopez
* \date     2016.09.6
*/

void crearlistas(NODO ** head,char usr [],char password [], TIPO t )
{
  NODO *nuevo_dato;

  nuevo_dato=agregarnodo();
  strcpy(((DATO*)nuevo_dato->info)->user,usr);  
  strcpy(((DATO*)nuevo_dato->info)->passwd,password);
  agregoinicio(head,nuevo_dato,t);
}


