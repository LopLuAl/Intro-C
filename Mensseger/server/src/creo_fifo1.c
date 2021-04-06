#include "header.h"

void creo_fifo1(int* fpd1)
{
  if((*fpd1= open(FIFO1,O_RDONLY))==-1)
  {
    if(mkfifo(FIFO1,0660)<0)
    {
      perror("mkfifo: ");
      exit(1);
    }
    else
    {
      if((*fpd1= open(FIFO1,O_RDONLY))==-1)
      {
	perror("Open: ");
	exit (1);
      }
    }
  }
}