#include <header.h> 

void replace (char *s, char nuevo, char viejo)
{
  int i;
  
  for (i=0;*(s+i) != '\0'  ;i++ ) //recorremos el ptr a vtr de caractres
  {
    if(*(s+i) == viejo) //si el caracter recorrido es igual al viejo
      *(s+i) = nuevo;   // lo reemplazamos
  } 
}
