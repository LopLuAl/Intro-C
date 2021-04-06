/*
 4.4
Escribir una funcion que reciba como argumento puntero a una secuencia de
bytes, la asuma como una secuencia en ASCII terminada en 0 (a los fines de
la evaluacion, este caracter en C es \0 ), calcule su longitud y la retorne de acuerdo al siguiente prototipo:
int myStrlen (const char *) ;
*/
//scanf("%{^\n}",&char); // 
#include <header.h>

int main (int argc, char * argv [])
{     
  const char charsito[] = "hola", *p;
  int a;
  p=&charsito;
  a=myStrlen(p);
  printf("la longitud del string es:  %d \n",a); 
  return 0;
}

	
