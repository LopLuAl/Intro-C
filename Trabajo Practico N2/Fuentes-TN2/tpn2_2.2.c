#include <stdio.h>
/*				2.2				*/
/*Escribir un programa que calcule la diferencia entre dos n ́
  numeros e indique si el resultado es positivo, negativo o cero.*/

int resultado =0;
int minuendo=4;
int sustraendo=-3;

int main (void)
{
  resultado = sustraendo - minuendo;
  
  if(resultado<0)
    printf("Resultado negativo /n");
  else	
    printf("Resultado Positivo /n");
  return 0;
}
/*			Pseudocodigo			*/
/*
 * Declarar variables
 * -> resultado
 * -> minuendo
 * -> sustraendo
 * 
 * Hacer la cuenta sustraendo - minuendo
 * Almacenar ese resultado en la variable resultado
 * 
 * Preguntar
 * 
 * Si reusltado < 0
 * 	Imprimir Resultado negativo
 * sino 
 * 	Imprimir Resultado Positivo
 */
  