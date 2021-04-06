#include <header.h> 
int myStrncmp (const char *s1, const char *s2, int n) 
{
  int i,j;
  int aux1, aux2;
  for (i=0,j=0; i!=   '\n'; i++ )
  {
    aux1 = *(s1 + i); 	   // asignamos cada caracter a una var aux
    aux2 = *(s2 + i);
    if( aux1 < aux2 ) j++; //preguntamos cual es menor o mayor luego incrementamos o decremtamos j
    else if( aux1 > aux2 ) j--;
    
  }
  return j; 			   //ahora lo devolvemos
}
