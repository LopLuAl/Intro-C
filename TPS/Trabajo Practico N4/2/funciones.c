#include <header.h> 
void analisis ( char *pepe[], int miargc, double *sump, double *sumn, double *sumt )
{

	int i;
	printf("El valor de argv es. %p \n", pepe);
	for (i=1 ; i < miargc ;i++ )
	{
		double aux=0;
		aux = atof(pepe[i]);//Convertimos el string a float			    	
		(*sumt) += aux;		// realizamos la sumatoria
							//printf("el valor de aux %f\n",aux);		
		if( (i % 2) == 0  ) // para saber la posicion par simplemente usamos el operador resto
							// si da 0 la operacion, es la posicion par y sumamos
		{
			(*sump)+=aux;					
		}	     		
		if ( aux < 0 )		//si el valor convertido es menor que 0, lo almacenamos en su correspondiente
							// variable
			(*sumn)+=aux; 
	}
}
