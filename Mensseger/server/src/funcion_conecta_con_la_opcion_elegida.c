#include "header.h"
void	funcion_conecta_con_la_opcion_elegida(char* buffer_nombre_opcion_elegida, int sockdup, char * FIFO_NAME)
{
//   FILE *F=NULL;
//   char* ID_USR;
//   char Mnj_error[]="Error persona no encontrada";
//   int retval=-1;
//   int nro_elementos=100;
//   ID_USR=(char*)malloc(nro_elementos*sizeof(char));
//   if((F = fopen("PID-USR.info","r")) == 0)
//   {
//     perror("No se pudo encontrar el archivo usuarios-conectado.info: ");
//     exit(1);
//   }
//   while(retval==-1)
//   {
//     if((fread(ID_USR,16,1,F)) == 0)
//     {
//       perror("Read, funcion_conecta_con_la_opcion_elegida: ");
//       exit(1);
//     }
//     ID_USR[17]='\0';
//     retval=analisis_de_USR_PID(ID_USR,buffer_nombre_opcion_elegida);		//En el caso verdadero, la fun, dev su pid
//     if(retval==0)								//en buffer_nombre_opcion_elegida.
//     {
//       lo_conecto_con(buffer_nombre_opcion_elegida);			
//     }
//     if(retval==-1)
//     {
//       if((write(sockdup,Mnj_error,strlen(Mnj_error)))==-1)		
//       {										
// 	perror ("Error en Write, funcion_conecta_con_la_opcion_elegida: "); 
// 	exit (1);
//       }
//     }
//   }
//   free(ID_USR);
    lo_conecto_con(buffer_nombre_opcion_elegida,FIFO_NAME,sockdup);	
}