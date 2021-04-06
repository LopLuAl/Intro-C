#include "header.h"

int analisis_de_USR_PID(char* ID_USR,char* buffer_nombre_opcion_elegida)
{
  int i;
  int a=0;
  for(i=0;ID_USR[i]!='\0';i++)
  {
    if(strcmp(ID_USR,buffer_nombre_opcion_elegida))
      a++;
  }
  if(a==0)
    return 0;
  else
    return -1;
}