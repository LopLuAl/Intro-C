#include <header.h> 
void pasaje ( long * pepe )
{
  char vctr[8]= {};
  int i;
  //long y;
  //y=*pepe;
  sprintf(vctr,"%d",*pepe);//llamamos a la funcion sprintf, var  salida, "%d" a 
			   //que queremos que lo convierta, *pepe variable de entrada
    for(i=0;i<4;i++)
      printf("%c\n",vctr[i]);
}