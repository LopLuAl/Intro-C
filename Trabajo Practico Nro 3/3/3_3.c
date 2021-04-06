/*
 * 3.3
Realice una calculadora, donde cada una de las operaciones sea una funci ́on. La
misma deber ́
a poder: sumar, restar, multiplicar, dividir, calcular el factorial,
potencia y raiz. La forma de ingresar los datos debe ser de la misma forma que
se hace en una calculadora tradicional.
Importante: se deben hacer todas las validaciones necesarias para no incurrir
en un error o mal calculo. Nota: Como usuario se debe poder hacer tantas
operaciones como se desee, deber ́a existir alguna condici ́on de fin*
*/
//scanf("%{^\n}",&char); // 
#include <header.h>
#include <math.h>


int main (void)
{     	
  char in[30]={};
  int i;
  printf("Bienvenido a la calculadora\n");
  printf("Para salir presione la letra e\n");  
  //scanf("%[^\n]",&in);
  while(1)
  {
      scanf("%[^\n]",in);
      getchar(); // esto se come cualquier cosa que quede en el buffer!
      for(i=0;i<30;i++)
      {
	if( in[i] <= 'z' && in[i] >= 'a' &&in[i] != 'e')
	{
	  printf("Caracter: %c No valido. Por favor ingrese un valor entre 0 y 9. Operadores validos: +, -, *, /, !, ^, s \n", in[i]);
	
	  exit(2);  
	}
      }
      for(i=0;i<30;i++)
      {
	switch (in [i])
	{
	  case '+':
	    suma (in,i); 
	    break;
	  case '-':
	    resta (in,i);
	    break;
	  case '/':
	    dividir(in,i);
	    break;
	  case '*':
	    multiplicar(in,i);
	    break;
	  case '!':
	    factorial(in,i);
	    break;
	  case '^':
	    potencia(in,i);
	    break;
	  case 's':
	    raiz(in,i);
	    break;
	  case 'e':
	    exit(2);
	  default:
	    break;
	}  
      }
  }
  return 0;
}
