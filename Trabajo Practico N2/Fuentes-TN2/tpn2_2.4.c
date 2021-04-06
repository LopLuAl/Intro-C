/*					2.4
 Escribir un programa tal que ingresados los coeficientes A, B y C de una ecuaci ́on
cuadŕatica,informe sus ra ́ıces, en caso de que las mismas sean imaginarias pre-
sentar una leyenda indicativa en la pantalla.
*/

#include <stdio.h>
#include <math.h>

float resultado =0;
float a,b,c;
float x1,x2;
float delta;
int main (void)
{
  printf("Bienvenido Por Favor Introduzca A,B y C  ");
  printf("A");
  scanf("%f",&a);
  printf("B");
  scanf("%f",&b);
  printf("C");
  scanf("%f",&c);
  delta=pow(2,b)-4*a*c;
  if(delta<0)
    printf("Las raices son imaginarias");
  else
  {
  x1=(-b+sqrt(delta))/2*a;
  x2=(-b-sqrt(delta))/2*a;
  printf("El resultado de: /n X1=%10.4f/n X2= %10.4f ",x1,x2);  
  }
  return 0;
}
/*
Psuedocodigo:
Declarar variables
  -> A
  -> B
  -> C
  -> x1
  -> X2
  -> Delta
  -> Resultado

Hacer una funcion que que lea los valores ingresados por el telcado y luego calucle la formula resolvente

Tomar valores del teclado
Alamacenar esos valores en distintas variables
Con las variables calcular el Δ :
almacenar ese resultado en la variable Δ
si  Δ < 0
Imprimir el texto: "raices imaginarias"
sino
x1+(-b+sqrt(delta))/2*a;
x2=(-b-sqrt(delta))/2*a;
Imprimir resultado de x1 y x2 
*/

  
