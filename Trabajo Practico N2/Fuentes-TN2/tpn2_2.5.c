/*					2.5
      Escribir un programa donde ingresa por teclado una temperatura expresada en
      grados Celsius. Calcula su valor en grados Kelvin, y muestra por pantalla el
      valor en °C y su equivalente en °K. (Recordar °C = °K − 273)
*/
#include <stdio.h>

float celcious,kelvin;

int main (void)
{
  printf("Bienvenido Por Favor Introduzca La temperatura en grados celcious /n ");
  
  scanf("%f",&celcious);
  kelvin = celcious + 273;
  printf("La temperatura en Grados Kelvin = %5.3f", kelvin);
  printf("La temperatura en Grados Celcious = %5.3f", celcious);

  return 0;
}
/*
Psuedocodigo:
Declarar variables
  -> Celcious
  -> Kelvin

Tomar el valor ingresado por el teclado
Alamacenarlo en un una variable (celcious)
Conventir de celcious a Kelvin -----> kelvin = celcious + 273
Imprimir el resultado de los grados kelvin 
De paso tambien los grados celcious 
  


*/

  
