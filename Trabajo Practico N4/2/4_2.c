/*
                                    4.2
Se ingresan 40 datos numéricos, de los cuales hay que mostrar la sumatoria de
todos ellos, el promedio, la suma de los elementos que ocupan la posicion par y
el promedio de los valores positivos.
*/

#include <header.h>

int main (int argc , char *argv[])
{     	
	//Declaracion de variables	
	double sump=0, *a; // sump sumatoria de los elemntos pares
	double sumn=0, *b; // sump sumatoria de los elemntos negativos
	double sumt=0, *c; // sump sumatoria total
	a=&sump;
   	b=&sumn;
	c=&sumt;
	analisis(argv, argc, a, b, c);
	printf("El valor de argv es. %p \n", argv);
	printf("La sumatoria de los  pares es   %4.2f \n", *a);
	printf("La sumatoria de los  negativos es %4.2f \n", *b);
	printf("La sumatoria  total es            %4.2f \n", *c);
	printf("El promedio de la sumatoria es            %4.2f \n", (*c/(argc-1)) );
	//le resto 1 a argc para que no me cuente el espacio de "./prg"
	    
	return 0;
}
