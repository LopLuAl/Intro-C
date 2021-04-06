#include <stdio.h>

/*      2.8     */
/*
Escribir un programa que obtenga el factorial de un n´umero ingresado por
teclado.
*/
int main(void)
{
    
    float numeros=2;
    float cantidad =0;
    float temporal=0;
    float promedio = 0;
    printf("Por Favor Ingrese los numero a hacer el promedio\n");
    while (numeros != 0)
    {
    numeros=0;
    scanf("%f",&numeros);    
    if (numeros != 0)
    {
    	cantidad ++;
    	temporal += numeros;	       
    }
    }
    promedio = temporal / cantidad;	
    printf(" El promedio es ....:%5.3f\n",promedio);
    return 0;
}
/*Pseudocodigo*/
/*
Declarar variables
	-> numeros
	-> temporal	
	-> cantidad
	-> promedio
mientras ( los numeros ingresados sean distintos de 0)
	ingresamos los numeros
	si (los numeros son distintos de 0)
		sumamos 1  a la variable cantidad
		sumamos el numero ingresado a la sumatoria total del promedio y guardamos ese valor en la variable temporal
luego de haber ingresado el 0, hacemos la division entre la sumatoria y la cantidad de datos ingresados
almacenamos ese valor en la varible promedio 
imprimimos el resultado en pantallas
*/
