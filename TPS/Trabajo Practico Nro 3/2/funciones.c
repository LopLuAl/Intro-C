#include "./includes/header.h"

int factorial(int num) // Desarrollo del factorial:
{
    
    int temporal; // Declaracion de variable, en la cual se van a realizar las sucesivas multiplicaciones
    temporal = num -1; // Al numero que recibimos lo decrementamos en uno
    while (temporal >= 1) // mientras el numero temporal sea mayor o igual a 1 se ejecuta el while
    {	
    	num = temporal * num; // Multiplicamos sucevamente hasta obtener todos los factoriales
	temporal -- ;
        printf("El factorial de  es :  %d\n",num); // Imprimimos
        
    }
    

}

int validacion(float numero)
{
    int valic; // Declaracion de un variable auxiliar para trabajar con la parte int
    valic=numero; // numero es float, valic int
    
    if ( numero < 0 ) /* Preguntamos si el nuero (float) es > 0 de esta forma cubrimos la opcion de que sea negativo */
    {
        printf("Por favor ingrese un numero >0!\n"); 
        return 1; // si resesulta negativo devolvemos 1
    }
    numero=numero-valic; // Le restamos la parte entera de la decimal ej: 3.2-3=0.2
                         // 3-3=0 -> en este caso pasa de largo y devuelve 1 la funcion
    if  ( numero > 0 ) 
    {
        printf("Por favor ingrese un numero int !!\n"); 
        return 1;
    }
    else
        return 0;
    
}




