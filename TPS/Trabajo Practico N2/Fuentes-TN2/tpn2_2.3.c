#include <stdio.h>
#include <math.h>
/*					2.3
Escribir un programa que calcule la superficie de un c ́ırculo cuyo radio se ingresa
				    por teclado
*/
float resultado =0;
float radio=4;
#define pi 3.1416

int main (void)
{
  scanf("%f",&radio);
  resultado = pi * pow(2,radio);
  printf("El resultado es %f",resultado);
  return 0;
}

/* 
Pseudocodigo

Declarar variables:
-> resultado
-> radio

Ingresar valores por el  teclado del radio
Multiplicar la constante pi por el cuadrado del radio
Alamacenar el resultado de esa operacion en la variable resultado
imprimir en pantalla la variable resultado
*/