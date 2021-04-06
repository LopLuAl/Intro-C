/* 4.1

 Escriba una función que imprima, byte a byte, los bytes que constituyen una
variable long cuya dirección recibe como argumento
 */

#include <header.h>

int main ()
{
    long y = 1250;//Declaramos la variable y le asignamos un valor cualquiera
    long*p;
    printf("");
    p=&y;
    pasaje (p);//la pasamos por referencia
    return 0;
}