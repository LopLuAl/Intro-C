/**
* \file   src-lista-lib.c
* \brief  Contiene las funciones escenciales para armar una lista
*         Funciones que dio Florencia y Furfaro que estan andando
* \author Luciano Lopez
* \date   2016.09.2
*/

#include<header-listas-lib.h>

/**
* \fn void agregoinicio(NODO**head, NODO* dato,TIPO t) 
* \details Agrega Nodo al inicio de una lista SIMPLE o DOBLE
* \arg    NODO ** head  Puntero a puntero de la cabeza de la lista, paso la direccion del puntero de cabecera, lo estoy pasando por referencia
*         NODO  * dato  Puntero al nuevo espacio de memoria reservado para el nuevo NODO
*         TIPO     t    Tipo de lista a hacer SIMPLE o DOBLE
* \return void
* \author Luciano Lopez
* \date   2016.09.2
*/
void agregoinicio(NODO**head, NODO* dato,TIPO t) 
{
  if(t == SIMPLE)
  {
    if(head == NULL)        //Si la lista esta vacia, igualo el primer nodo con la cabecera
      *head=dato;
    else
    {
      dato -> next=*head;   // Se copia la direccion de cabecera, al puntero next del nodo creado
      *head=dato;           // Ahora este nuevo nodo, tendra la direccion de cabeza 
    }
  }
  else if(t == DOBLE)
  {
    if((*head) == NULL)     //Si la lista esta vacia, igualo el primer nodo con la cabecera
    {
      dato->prev=NULL;      // Inicializo los punteros prev y next a NULL asi no apuntan a chot
      dato->next=NULL;
      *head=dato;
    }
      else                  //La lista no estaba vacia...
    {
      dato->next=*head;     //La direccion de head la copio en la direccion de dato->next ya que este va a ser el proximo nodo cabeza de la lista
      (*head)->prev=dato;   //Hago el lazo que recorre la lista para atras entre el nodo actual de cabeza y el futuro 
      *head =dato;          //Ahora el nuevo nodo es la direccion de cabeza
      dato->prev=NULL;      //Como es la cabecera, el dato->prev tiene que apuntar a NULL
    }
  }
}
/**
* \fn void agregofin(NODO**head, NODO* dato,TIPO t)
* \details Agrega Nodo al final de una lista SIMPLE o DOBLE
* \arg     NODO ** head  Puntero a puntero de la cabeza de la lista, paso la direccion del puntero de cabecera, lo estoy pasando por referencia
*          NODO  * dato  Puntero al nuevo espacio de memoria reservado para el nuevo NODO
*          TIPO     t    Tipo de lista a hacer SIMPLE o DOBLE
* \return  void
* \author  Luciano Lopez
* \date    2016.09.2
*/
void agregofin(NODO**head, NODO* dato,TIPO t)
{
  
  NODO *aux;                  // Declaro una variable de tipo NODO que luego voy a usarla...
  
  if(*head == NULL)           // Si la lista esta vacia....
  {
    agregoinicio(head,dato,t);// La lleno como una lista normal
    return;
  }
  
  aux=*head;                  // Igual la direccion de cabecera a aux asi no pierdo la referencia del principio de la lista
                              // Voy recorriendo nodo hasta encontrar el ultimo nodo  
  while(aux->next!=NULL)      // **De esta forma logro no mostrar el ultimoelemento de la lista pero si la recorro toda**
    aux=aux->next;            // esto no me sirve si quiero mostrar toda la lista(el contenido).
  
  aux->next=dato;             // Asigno los punteros prev y next de la misma forma que con la funcion agregoinicio, pero con la diferencia que aux es el ultimo nodo de la lista
  dato->next=NULL;
  
  if(t==DOBLE)                // Si la lista es doble...
    dato->prev=aux;           // Tengo que ademas enlazar el puntero prev al nodo anterior
}
/**
* \fn void insertnodoleft(NODO*aux,NODO*dato,NODO *head)
* \details  Agrega Nodo al izquiera de un nodo cualquiera
* \arg      NODO * nprev Nodo de la derecha
*           NODO * dato  Nodo a insertar
*           NODO * head  Puntero de la cabeza de la lista, paso la direccion del puntero de cabecera, lo estoy pasando por referencia
* \return   void
* \author   Luciano Lopez
* \date     2016.09.2
*/
void insertnodoleft(NODO*nprev,NODO*dato,NODO *head)
{

  NODO * aux1;       	            // Declaro una variable de tipo NODO para no perder la direccion de incio de la lista  
  aux1 = head;                
  
  while(aux1->next!=nprev)
        // Busco el nodo que esta  a la izquierda del nodo que quiero insertar
    aux1=aux1->next;          

  dato->next = nprev;             // igual la direccion del nuevo_nodo->next a la del nodo de la derecha 
  aux1->next = dato ;             // Ahora igual la direccion del nodo_izquierda->next con la direccion del nuevo nodo
  dato->prev =  aux1;             // Uno los punteros de prev con el nodo anterior
  nprev->prev= dato ;             // Uno el puntero anterior del siguiente nodo insertado con la direccion actual de dicho nodo
}
/**
* \fn void borrarnodo(NODO *d, NODO ** head)
* \details  Borra un nodo
* \arg      NODO ** head // puntero a puntero de la cabeza de la lista, paso la direccion del puntero de cabecera, lo estoy pasando por referencia
            NODO  * d    // puntero al  nodo a borrar
* \return   void
* \author   Luciano Lopez
* \date     2016.09.2
*/
void borrarnodo(NODO *d, NODO ** head)
{   
  NODO * aux;
  if ( d == *head)			 	// si el nodo a borrar es la cabeza de la lista
    *head = d->next; 
  else										// si no lo es...
  {
    aux=*head; 
    while(aux->next!=d)		// Recorro la lista buscando el nodo a borrar
      aux=aux->next;
    aux->next=d->next;		// Aca enlazo el nodo siguiente del nodo a borrar con el nodo anterior de dicho nodo
    ((d->next)->prev)=aux;
  }
  free(d->info);					//primero hago un free de los datos 
  
  free(d); 								// Libero la memoria para que la ocupe un futuro nodo
}
