#include "header.h"

void aviso_que_me_llego(int sockdup)
{
  char mando_ok[]="OK";
  if(write(sockdup,mando_ok,strlen(mando_ok))==-1)
  {
    perror ("Error en Write 1: "); 
    exit (1);
  }
}