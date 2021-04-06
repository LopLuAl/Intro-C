/*
                                    3.1
Escriba una funcióon que reciba dos argumentos (x e y) y devuelva como resul-
tado xy . Realizar todas las validaciones que considere necesarias.
*/


#include "./includes/header.h"
int main (void)
    
{
    float x,y,resu;
    printf("Bienvenido\n");
    printf("Por favor introduzca dos numeros a multiplicar!\n");
    printf("Numero A\n");
    scanf("%f",&x);
    getchar();
    printf("Numero B\n");
    scanf("%f",&y);
    getchar();
    resu=multiplicar(x,y);
    printf("El resultado es %f",resu);
}