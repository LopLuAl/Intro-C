/* 
/*		2.10				*/ 
/*Se tienen 5 sensores de temperatura, que registran 15 temperaturas distintas 
cada uno. Esas temperaturas se ingresan de a una por vez, primero las 15 del 
1er sensor, luego las 15 del segundo, y asi sucesivamente. 
• Temperatura promedio detectada por cada sensor. 
• Maxima temperatura registrada por cada sensor. 
• Numero de sensor que registro la temperatura maxima 
*/ 
#include <stdio.h> 
int main(void) 
{ 
  float sensor1[5]; 
  float sensor2[5]; 
  float sensor3[5]; 
  float sensor4[5];
  float sensor5[5]; 
  int i=0,v=0; 
  float aux_m,aux_ms;  
  float promedio=0;    
  // asignacion de valores a los sensores 	
  printf("Bienvenido\n");
  printf("Por favor ingrese valores al sensor 1\n"); 
  for(i=0;i<5;i++)
  {
    //recorremos el vector y asignamos valor mediante scanf
    scanf("%f",&sensor1[i]);	
    getchar(); // ponemos el getchar para que al proximo scanf no tome ningun valor
  }
  printf("Por favor ingrese valores al sensor 2\n");
  for(i=0;i<5;i++)
  {
    //recorremos el vector y asignamos valor mediante scanf
    scanf("%f",&sensor2[i]);	
    getchar();
  }
  printf("Por favor ingrese valores al sensor 3\n");
  for(i=0;i<5;i++)
  {
    //recorremos el vector y asignamos valor mediante scanf
    scanf("%f",&sensor3[i]);	
    getchar();
  }
  printf("Por favor ingrese valores al sensor 4\n");
  for(i=0;i<5;i++)
  {
    scanf("%f",&sensor4[i]);	
    getchar();
  }
  printf("Por favor ingrese valores al sensor 5\n");
  for(i=0;i<5;i++)
  {
    scanf("%f",&sensor5[i]);	
    getchar();
  }
  for(i=0;i<5;i++) 
  { 
  // comparamos con la variable auxiliar mientras recorremos el vector
    if(aux_m<sensor1[i]) 
      aux_m=sensor1[i]; 
    if(aux_ms<sensor1[i]) 
       aux_ms=sensor1[i];
    //sumamos todos los valores
    promedio+=sensor1[i];
  }
  // divimos la sumatoria por la cantidad de valores
  promedio=promedio/5; 
  printf("El valor promedio del sensor 1 es %2.2f\n",promedio); 
  //Imprimimos el valor maximo del sensor 1
  printf("La temperatura maxima registrada por el sensor 1 es:%2.2f\n ",aux_ms); 
  // comparamos el valor maximo del vector con el resto de los vectores
  for(i=0,aux_ms=0,promedio=0;i<5;i++) 
  { 
    // pregunto si el mayor valor tomado, es mayor al valor que esta en el subindice de ese sensor
    if(aux_m<sensor2[i]) 
      aux_m=sensor2[i]; 
    // pregunto el mayor valor tomado, es mayor que el valor de ese subindice, este valor maximo lo voy a comparar con todos los valores de los sensores
    if(aux_ms<sensor2[i]) 
      aux_ms=sensor2[i]; 
    //sumamos todos los valores
    promedio+=sensor2[i];  
  }
  promedio=promedio/5; 
  printf("El valor promedio del sensor 2 es %2.2f\n",promedio); 
  // imprimimos el valor maximo del sensor 2 
  printf("La temperatura maxima registrada por el sensor 2 es: %2.2f\n ",aux_ms); 
  // comparamos el valor maximo del vector  con el resto de los vectores
  for(i=0,aux_ms=0,promedio=0;i<5;i++) 
  { 
    if(aux_m<sensor3[i]) 
      aux_m=sensor3[i]; 
    if(aux_ms<sensor3[i]) 
      aux_ms=sensor3[i];
    //sumamos todos los valores
    promedio+=sensor3[i];
  }  
  promedio=promedio/5; 
  printf("El valor promedio del sensor 3 es %2.2f\n",promedio); 
  // Imprimimos el valor maximo del sensor 3  
  printf("La temperatura maxima registrada por el sensor 3 es: %2.2f\n ",aux_ms);	 
  // comparamos el valor maximo de los sensores anteriores con los del sensor 4
  for(i=0,aux_ms=0,promedio=0;i<5;i++) 
  { 
    if(aux_m<sensor4[i]) 
      aux_m=sensor4[i]; 
    if(aux_ms<sensor4[i]) 
      aux_ms=sensor4[i];
    //sumamos todos los valores
    promedio+=sensor4[i];
  }
  promedio=promedio/5; 
  printf("El valor promedio del sensor 4 es %2.2f\n",promedio); 
  //Imprimimos el valor maximo registrado por el sensor 4 
  printf("La temperatura maxima registrada por el sensor 4 es:%2.2f\n ",aux_ms); 
  // comparamos el valor maximo de los sensores anteriores con los del sensor 5
  for(i=0,aux_ms=0;i<5;i++) 
  { 
    if(aux_m<sensor5[i]) 
      aux_m=sensor5[i]; 
    if(aux_ms<sensor5[i]) 
      aux_ms=sensor5[i];
  //sumamos todos los valores
    promedio+=sensor5[i];
  }
  promedio=promedio/5; 
  printf("El valor promedio del sensor 5 es %2.2f\n",promedio);    
  //Imprimimos el valor maximo registrado por el sensor 5
  printf("La temperatura maxima registrada por el sensor 5 es:%2.2f\n ",aux_ms); 
  printf("El valor maximo de todos los sensores es %2.2f\n",aux_m); 

  return 0; 
} 
/*Pseudocodigo*/ 
/* 
se declaran las  variables, usamos vector para una mayor comodidad 
recorremos los vectores 
Accion  x 5 
{ 
preguntamos mientras recorremos el vector 
si el valor reorrido  es el maximo de todos lo imprimimos 
preguntamos si el valor maximo del sensor anterior es mayor a algun valor del siguiente sensor 
	imprimimos el valor maximo de los 5 sensores 
} 
Accion  x 5 
{ 
mientras recorremos el vector 
sumamos todas los valores de los subindices y los divimos por 15 
imprimimos el valor en pantalla 
} 
*/  
