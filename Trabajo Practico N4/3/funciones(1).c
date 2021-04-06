#include <header.h> 
void stringReverse (char *argv[])
{
	int i=1; 
    for (i=1;*(argv+i) != '\0'  ;i++ ) //recorro el string hasta que llegue al final
	{
		printf("String : %s \n", *(argv+i));
	}
	while(i != 1) //con el valor obtenido de i
	{
		i--;	 // lo decremento hasta que sea al reves	
		printf("String al reves: %s \n", *(argv+i));		
	}
}
