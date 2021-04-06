#include "header-maxfds.h"
int fun_max_fds(int nargs, ...)
{
  va_list ap;
  int j;
  int num;
  int aux=0;
  va_start(ap, nargs);
  for (j =0; j<nargs; j++)
    {
      num=va_arg(ap, int);
      if (num>aux)
      aux=num;
    }
  va_end(ap);
  printf("\n");
  return aux;
}