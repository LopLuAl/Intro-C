#include <stdio.h>

/*      2.8     */
/*
Escribir un programa que obtenga el factorial de un n´umero ingresado por
teclado.
*/
int main(void)
{
    
    int factorial = 0;
    int temporal;
    printf("Por Favor Ingrese el numero\n");
    scanf("%d",&factorial);
    temporal = factorial -1;
    while (temporal >= 1)
    {	
    	factorial = temporal * factorial;
	temporal -- ;
    }
    printf("numero %d\n",factorial);

    return 0;
}
/*Pseudocodigo*/
/*
Declarar variables
	-> Factorial
	-> Temporal
Ingresamos el numero que deseamos hacerle el factorial
le restamos 1 al numero que queremos hacerle el factorial y asignamos ese valor a otra variable
mientras (factorial sea menor igual a 1)
	multiplicamos factorial por temporal 
	le restamos uno a temporal
imprimios el factorial en pantalla
*/
