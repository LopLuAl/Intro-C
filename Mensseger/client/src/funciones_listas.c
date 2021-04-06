#include "header-funciones-listas.h"

/**
* \file   funciones_listas.c 
* \brief  Contiene las funciones para operar con una lista
* \author Luciano Lopez
* \date   2016.09.2
*/

/**
* \fn 		void imprimir (NODO *head)
* \details  Imprime lo que tiene la lista
* \arg      NODO * head puntero de la cabecera
* \return   void
* \author   Luciano Lopez
* \date     2016.09.6
*/
void imprimir (NODO *head)
{

   
    NODO * recorre;
   	#ifdef DEBUG
    int j=0;
 	#endif
    recorre=head;
	printf("\n");
    do
    {
		#ifdef DEBUG	
		j++;	
		printf("\nNodo numero %d\n",j);
		printf("Direccion actual del  nodo %p\n",recorre);
		printf("Direccion actual del  nodo anterior %p\n",recorre->prev);
		printf("Direccion del proximo nodo %p\n",recorre->next);
		#endif

		printf("Contenido: %s\n",((DATO*)recorre->info)->user);
		printf("Contenido: %s\n",((DATO*)recorre->info)->passwd);
		recorre=recorre->next;
    }while((recorre->next!=NULL));//|(j==3)
    
	#ifdef DEBUG	
	j++;	
	printf("\nNodo numero %d\n",j);
    printf("Direccion actual del  nodo %p\n",recorre);
    printf("Direccion actual del  nodo anterior %p\n",recorre->prev);
    printf("Direccion del proximo nodo %p\n",recorre->next);
	#endif
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
  char user     [CANT_MAX];
  char password [CANT_MAX];

  if((F = fopen("../bin/fichero.dat","a+")) == NULL)
  {
//     a+ Abre el archivo para lectura y escritura. La lectura o escritura comenzará al final del fichero, sin afectar al contenido previo. Si el fichero no existe se intenta crear.
      perror("No se pudo encontrar el archivo");
      exit(1);
  }
  
  while(!feof(F))
  {
      fread( user,sizeof(user),1,F);
      fread(password,sizeof(password),1,F);
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
 	fp = fopen ("../bin/fichero.dat", "a+" );
	
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
