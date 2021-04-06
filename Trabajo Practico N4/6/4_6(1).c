/*4.6
Escribir una función que responda al siguiente prototipo:
y reemplace en la cadena ”s” todas las apariciones del caracter ”viejo” por el
carácter ”nuevo”.
*/
//scanf("%{^\n}",&char); // 
#include <header.h>


int main (int argc, char *argv[] )
{     	
  char nuevo, viejo,*p;
  int i;
  
  p=argv[1]; //argv[1] (1-> asi nos evitamos el ./prg) apunte a p
  
  printf("Bienvenido a Replace program   \n ");
  
  printf("Por favor introduzca el caracter que quiere reemplazar   \n ");
  scanf("%c",&viejo);
  getchar();			//nunca olvidar el getchar, asi no queda nada en el buffer!
  
  printf("Por favor introduzca el nuevo caracter   \n ");
  scanf("%c",&nuevo);
  getchar();
  
  replace (p,  nuevo,  viejo);	  //lamada a la funcion, le pasamos el ptr p, caracter nuevo y viejo
  
  for (i=0;*(p+i) != '\0'  ;i++ ) //recorremos el puntero a p, modificado
    printf("%c",*(p+i));	
  printf("\n");
  
  return 0;
}








