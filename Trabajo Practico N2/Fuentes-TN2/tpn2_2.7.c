/*				2.7						*/
/*
Escribir un programa que imprima la tabla de multiplicaci ́on de cualquier n ́
umero
de 0 a 10 ingresado por teclado.
*/

#include <stdio.h>



int a=1;
int b[9];
int c=1;

int main (void)
{
  
    printf("Bienvenido Por Favor Introduzca el numero \n ");
    scanf("%u",&a);
    c=a*0;
    printf("%d x 0 = %d\n",a,c);
    c=a*1;
    printf("%d x 1 = %d\n",a,c);
    c=a*2;
    printf("%d x 2 = %d\n",a,c);
    c=a*3;
    printf("%d x 3 = %d\n",a,c);
    c=a*4;
    printf("%d x 4 = %d\n",a,c);
    c=a*5;
    printf("%d x 5 = %d\n",a,c);
    c=a*6;
    printf("%d x 6 = %d\n",a,c);
    c=a*7;
    printf("%d x 7 = %d\n",a,c);
    c=a*8;
    printf("%d x 8 = %d\n",a,c);
    c=a*9;
    printf("%d x 9 = %d\n",a,c);
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

  
