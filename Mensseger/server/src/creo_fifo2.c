#include "header.h"

void   creo_fifo2(int* fpd2)
{
  if((*fpd2= open(FIFO2,O_RDONLY))==-1)
  {
    if(mkfifo(FIFO2,0660)<0)
    {
      perror("mkfifo: ");
      exit(1);
    }
    else
    {
      if((*fpd2= open(FIFO2,O_RDONLY))==-1)
      {
	perror("Open: ");
	exit (1);
      }
    }
  }
}