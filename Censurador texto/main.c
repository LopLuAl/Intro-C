#include <1erParcial.h>

int main (int argc, char *argv[])
{
  char buf[4096],buf2[4096];  
  int  cant[argc],q;
  
  for(q=0;q!=argc;cant[q++]=0);
  
  while(!feof(stdin))
  {
    fgets(buf,4096,stdin);  // lo que entra por el standard input, lo guardo en buf
    for (q=0;q!=4096;q++)   // copio los datos, a otro buffer  
      buf2[q]=buf[q];
    moderar(argc,buf,argv);
    *cant = estadistica(argc,buf2,argv,cant);
  }
  // cuando termino de leer todo el archivo, muestro las estadisticas.
  mostrar_estaditicas(argv,cant, argc);
  return 0;
}
