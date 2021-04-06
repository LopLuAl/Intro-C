/*4.5
Escribir una funcion que dados dos punteros a caracteres y un numero ”n” entero recibidos como parametros, compare lexicogr ́aficamente los primeros ”n”
caracteres a partir de cada puntero, devolviendo un valor positivo, cero o negativo, segun corresponda. (Funci ́on strncmp() de la biblioteca <string.h >). El
prototipo de la funcion pedida es:
int myStrncmp (const char *s1, const char *s2, int n) ;*/
//scanf("%{^\n}",&char); // 
#include <header.h>

int main (void)
{     	
  char *s22,*s11,cadena1[100],cadena2[100]; //Declaramos dos cadenas de long max 100 caract
  int a,resu;
  printf("Por favor ingrse la cadenas dos cadenas: \n");  // ingresamos las cadeanas
  scanf("%[^\n]",&cadena1);
  getchar();					//recordar siempre poner el getchar para que no quede nada en el buffer
  printf("ahora ingrese la segunda cadena\n"); 
  scanf("%[^\n]",&cadena2);
  getchar();
  
  for(a=0;*(cadena1 + a) != '\0';a++); //recorremos un string para tener un 'n' y asi poder comparar
									   //ambos vectores 
  
  s11=&cadena1[0];					   // puntero apunte  a cadena1, pasamos un puntero a char asi 										   // podemos recorrer con el ptr cada caracter
									   // fue escrito asi s11=&cadena1[0]; xq el gcc rompia
  s22=&cadena2[0];					   // puntero apunte  a cadena2
  
  resu=myStrncmp(s11, s22, a);		   //lamada a funcion, pasaje de los str y 'n'
    printf("valor de resu %d\n",resu); // analisis del resultado
    if(resu > 0)
      printf("El segundo string es mas grande\n");
    else if(resu < 0)   
      printf("El primer string es mas grande\n");
     if (resu == 0)   
        printf("Los str iguales D:\n");
      //printf("mmmm.... que decirte....\n");
  return 0;
}
