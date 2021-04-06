/*					2.4
 Escribir un programa tal que ingresados los coeficientes A, B y C de una ecuaci ́on
cuadŕatica,informe sus ra ́ıces, en caso de que las mismas sean imaginarias pre-
sentar una leyenda indicativa en la pantalla.
*/

#include <stdio.h>



int a=1;
int b=1;
int c=1;

int main (void)
{
  
    printf("Bienvenido Por Favor Introduzca A,B y C \n ");
    printf("A \n");
    scanf("%u",&a);
    if( (a<0) || (a==0) )
    {
      printf("Por favor introduzca un valor distinto y mayor que 0 \n");
      scanf("%u",&a);
    }  
    printf("B \n ");
    scanf("%u",&b);
    if( (b<0) || (b==0) )
    {
      printf("Por favor introduzca un valor distinto y mayor que 0 \n ");
      scanf("%u",&b);
    }
    printf("C \n");
    scanf("%u",&c);
    if( (c<0) || (c==0) )
    {
      printf("Por favor introduzca un valor distinto y mayor que 0 \n ");
      scanf("%u",&c);
    }
    if( (a==b) && (a==c) )
      printf("El triángulo es EQUILATERO\n");
    if( ( (a==b) && (a!=c) ) || ( (a==c) & (a!=b) ) )
      printf("El triángulo es ISOCELES\n");
    if ( ( (a!=b) && (a!=c) ) )
      printf("El triángulo es ESCALENO\n");
  
  return 0; 

}

/*
Psuedocodigo:
Declarar variables
  -> Lado A
  -> Lado B
  -> Lado C

Recibir los datos de las 3 variables mediante la entrada del teclado por ejemplo.

Una vez ingresados esos valores
preguntar
si los valores ingresados son !0 y > a 0
comparar

si son todos iguales
  Imprimir eqilatero
si solamente son 2 iguales
  Imprimir isoceles
sino 
  Imprimir escaleno
*/

  
