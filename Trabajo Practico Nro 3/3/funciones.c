#include <header.h> 
void suma       (char  cont1[], int nro1)
{
  double s1=0,s2=0,s3;
  char *aux1, *aux2;
  aux1=&cont1[nro1-1];
  aux2=&cont1[nro1+1];
  s1=atof(aux1); //, cont[i+1])
  s2=atof(aux2); 
  s3=s1+s2;
  printf("El valor de la suma de %2.2f + %2.2f = %2.2f \n",s1,s2,s3);
}
void resta       (char  cont2[], int nro2)
{
  double s1=0,s2=0,s3;
  char *aux1, *aux2;
  aux1=&cont2[nro2-1];
  aux2=&cont2[nro2+1];
  s1=atof(aux1); //, cont[i+1])
  s2=atof(aux2); 
  s3=s1-s2;
  printf("El valor de la suma de %2.2f - %2.2f = %2.2f \n",s1,s2,s3);
}
void dividir       (char  cont3[], int nro3)
{
  double s1=0,s2=0,s3;
  char *aux1, *aux2;
  aux1=&cont3[nro3-1];
  aux2=&cont3[nro3+1];
  s1=atof(aux1); //, cont[i+1])
  s2=atof(aux2); 
  s3=s1/s2;
  printf("El valor de la suma de %2.2f / %2.2f = %2.2f \n",s1,s2,s3);
}
void multiplicar       (char  cont4[], int nro4)
{
  double s1=0,s2=0,s3;
  char *aux1, *aux2;
  aux1=&cont4[nro4-1];
  aux2=&cont4[nro4+1];
  s1=atof(aux1); //, cont[i+1])
  s2=atof(aux2); 
  s3=s1*s2;
  printf("El valor de la suma de %2.2f * %2.2f = %2.2f \n",s1,s2,s3);
}
void potencia    (char  cont5[], int nro5)
{
  double s1=0,s2=0,s3;
  char *aux1, *aux2;
  aux1=&cont5[nro5-1];
  aux2=&cont5[nro5+1];
  s1=atof(aux1); //, cont[i+1])
  s2=atof(aux2); 
 //s3=pow(s1,s2);
  printf("El valor de la potencia de %2.2f ^ %2.2f = %2.2f \n",s1,s2,s3);
}
void raiz    (char  cont6[], int nro6)
{
  double s1=0,s2=0,s3;
  char *aux1, *aux2;
  aux1=&cont6[nro6-1];
  aux2=&cont6[nro6+1];
  s1=atof(aux1); //, cont[i+1])
  s2=atof(aux2); 
  //s3=sqrt(s1,s2);
  printf("El valor de la potencia de %2.2f ^ %2.2f = %2.2f \n",s1,s2,s3);
}
void factorial   (char  cont7[], int nro7)
{
  
  char *aux1;
  int temporal,s1=0,factorial = 0;

  aux1=&cont7[nro7-1];
  s1=atoi(aux1);
  factorial=s1;
  temporal = factorial  -1;
  while (temporal >= 1)
  {
    factorial = temporal * factorial;	
    temporal -- ;
  }
  printf("El factorial de  %d! es: %d   \n",s1,factorial);
}