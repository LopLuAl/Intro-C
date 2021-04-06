/**
\file Ejercicio3-1.c
\brief Este archivo contiene el programa principal con su funcion main correspondiente
\details El programa solicitara el ingreso de dos numeros uno de ellos sera la base y el otro el exponente que luego seran tratados (de forma entera) por la funcion "potenciador" que devolvera el valor del numero 1 elevado al exponente del numero 2.
\author Germán Sivit gsivit@hotmail.com
\date 14 de Mayo de 2016
\version 1.0
*/ 
/*
 3.2
Escribir una función que calcule el factorial de un número natural pasado como
parámetro. Realizar todas las validaciones que considere necesarias.
 */
//#include "../includes/miheader.h"
#include "./includes/header.h"

int main (void)
{
    float num;
    int final;
    printf("Bienvenidos Por favor ingrese un numero para calcular el factorial\n El numero debe ser Z\n");  // Mensaje de bienvenida, hay que ser amable :)
    scanf("%f",&num); // Ingreso de numero por primera vez
    final = validacion(num);
    // Mientras el numero no sea el correcto no sale del while
    // la funcion validacion retorna 0 o 1 dependiendo si el numero
    // esta bien ingresado o no
    while (final==1)
    {
        scanf("%f",&num); // se ingresa por teclado el valor
        final = validacion(num); // se manda el valor a la funcion
    }
    factorial(num); // Llamamos a la funcion factorial
    return 0;
}







