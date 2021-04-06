/**
* \file funcs.c. 
* \brief Contiene las funciones del proyecto 1erParcial
* \author Luciano Lopez
* \date 2016.06.13
*/

#include <1erParcial.h>

/**
* \fn int my_strlen (char * str)
* \details Calcula la longitud en bytes de una cadena ASCIIZ cuya dirección recibe como argumento y devuelve su resultado
* \arg [in] str: Puntero a la cadena de caracteres cuyo tamaño desea calcularse.
* \return len: Devuelve un entero igual a la cantiddad de bytes de la cadena.
* \author Luciano Lopez
* \date 2016.06.13
*/

int my_strlen (char * str)
{
  int i;
  for(i=0;*(str+i)!='\0';i++);
  return i;
}


/**
* \fn char * my_strcpy (char * strdst, char * strorg)
* \details Copia el contenido de la cadena ASCIIZ desde la dirección de memoria recibida en el primer argumento
* \        , a partir de la dirección de memoria que se recibe como segundo argumento.
* \arg [in] strdst: Puntero a la dirección de memoria a partir de la que se debe copiar la cadena.
* \arg [in] strorg: Puntero a la cadena de caracteres origen que debe copiarse
* \return status: 0 si hubo error. De otro modo devuelve un puntero a la cadena destino.
* \author Luciano Lopez
* \date    2016.06.13
*/
char * my_strcpy (char * strdst, char * strorg)
{
  int i,cont=0;
  //*strdst -> posicion del cont a copiar
  //*strorg -> posicion a copiar
  cont = my_strlen (strdst); // llamo a esta funcion para saber la cantidad de caracteres del string
  for(i=0; i != cont;i++)
    *(strorg+i)=strdst[i];
  return 0;
}
/**
* \int my_strcmp (const char * s1, const char * s2)
* \details Compara las dos cadenas de caracteres s1 y s2. Devuelve un entero menor, igual o mayor que cero si se encuentra que s1 es, respectivamente, menor que, igual a (concordante), o mayor que s2.
* \arg [in] s1: Puntero a una de las cadenas a comparar.
* \arg [in] s2: Puntero a la otra cadena a comparar.
* \return   status: 0 si ambas cadenas son iguales. <0 si s1 < s2 (esto es si la diferencia entre los caracteres no coincidentes encontrados en primer instancia es negativa). >0 si s1 > s2 (esto es *           si la diferencia entre los caracteres no coincidentes encontrados en primer instancia es positiva)
* \author   Luciano Lopez
* \date     2016.06.13
*/

int my_strcmp (const char *s1, const char *s2)
{
  while(*s1 == *s2)  // mientras sean iguales 
  {
    s1++;            // voy incrementando caracter a caracter
    s2++;
    if (*s1 == '\0') // hasta encontrar el fin de la palabra 
    {
      return 0;      // como son iguales, retorno 0
    }
  }
  if(*s1 < *s2)
    return -1;       // si s1 (palabra de la blacklist) es menor que cualquier palabra retorno -1
  else
    return 1;        // en el caso contrario retorno valor positivo
}
/**
* \fn int moderar (char * str, char * blacklist)
* \details Busca en el mensaje de texto cuya dirección de memoria recibe en el segundo argumento,
* cada uno de las strings contenidas a partir de la dirección de memoria que se recibe como tercer argumento. 
* Por cada coincidencia reemplaza cada caracter individual dentro de la string econtrada en el mensaje de texto de origen con el caracter 'X'
* \arg [in] blacklist_size: Cantidad de elementos de la lista de palabras prohibidas.
* \arg [in] msg: Puntero a la dirección de memoria de inicio del mensaje.
* \arg [in] blacklist: Dirección del arreglo de punteros a las cadenas de palabras prohibidas.
* \return   status: 0 si no hubo error. 1 en caso contrario.
* \author   Luciano Lopez
* \date 2016.06.13
*/

int moderar (int blacklist_size, char *msg, char *blacklist[])
{
  // msg_size = argc
  // *msg = puntero a buf
  // *blacklist = argv
 
  int a, i, c, f, resu, z,flag=0;
  
  char palabra[40];
 
  for(a=0;a!=40;a++) //borro la cadena
   palabra[a] = '\0';
  
  for(i=0,c=0;msg[i]!='\0';i++,c++)                       // recorro la cadena hasta que encuentre un \0 que es el fin del parrafo.
  {
    if (msg[i] == ' ' || msg[i] == '.'|| msg[i] == ',')   // el meotodo para encontrar palabras es guardar caracter a caracter en un vector de char y preguntar si se encontro espacio coma o punto,
                                                          // para delimitar la palabra y definir una nueva
    {         
      for(f=1;f!=blacklist_size;f++)                      // se compara la palabra con todas las palabras del blacklist
      {
        resu = my_strcmp(blacklist[f],palabra); 
        if (resu==0)                                      // si la funcion devuelve 0 -> se encontro coincidencia
        {
          resu = my_strlen(palabra);                      // obtener el largo de la palabra para luego rellenarlo con X's
          for (z=0;z!=resu; z++)                          
            printf ("X");
          printf(" ");                                    // printifeamos un espacio asi las palabras no quedan sandwichito 
          for(a=0;a!=40;a++)                              // borro el vector para poder alojar una nueva palabra
            *(palabra+a)='\0';
          flag =1;                                        // como la palabra ya la imprimos con Xs para no volver a imprimir caracteres erroneos, ponemos una var de flag 
        }
      }
      if(flag == 0)                                       // La variable FLAG entra en juego cuando no se encontraron palabras que coincidan con el blacklist
      {
        printf("%s",palabra);                             // imprimimos la palabra
        printf(" ");                                      // dejamos un espacio para que no queden las palabras pegadas
        for(a=0;a!=40;a++)                                //borro la cadena
          *(palabra+a)='\0';
      }
      else                                                // si el flag estaba en 1, lo vovlemos a su estado original, para poder seguir imprimiendo palabras no coincidentes.
        flag =0;
      c=-1;                                               // pongo -1 asi cuando pase por c++, el valor de c sea 0
    }
    else
      *(palabra+c)=*(msg+i);                              // si no se encuentra ningun caracter que delimiten una palabra, alamcenamos los caracteres de buffer en un vector de chatrs
  }
  printf("\n");                                           // cuando termina el parrafo, deja un renglo en blanco
  return 0 ;
}
/**
* \fn int estadistica (int blacklist_size, char *msg, char *blacklist[], int cant[])
* \details Busca en el mensaje de texto cuya dirección de memoria recibe en el segundo argumento,
* cada uno de las strings contenidas a partir de la dirección de memoria que se recibe como tercer argumento. 
* Por cada coincidencia incrementa un vector de enteros que cada posicion representa una palabra distinta.
* \arg [in] blacklist_size: Cantidad de elementos de la lista de palabras prohibidas.
* \arg [in] msg: Puntero a la dirección de memoria de inicio del mensaje.
* \arg [in] blacklist: Dirección del arreglo de punteros a las cadenas de palabras prohibidas.
* \arg [in] cant: vector de interos que contiene la cantidad de palabras coincidentes
* \return   cant: vector de interos que contiene la cantidad de palabras coincidentes
* \author   Luciano Lopez
* \date 2016.07.07
*/
int estadistica (int blacklist_size, char *msg, char *blacklist[], int cant[])
{
  // msg_size = argc
  // *msg = puntero a buf
  // *blacklist = argv

  int a, i, c, f, resu;
  char palabra[40];
  
  for(a=0;a!=40;a++)                                          //borro la cadena
    palabra[a] = '\0';
  
  for(i=0,c=0;msg[i]!='\0';i++,c++)                           // recorro la cadena hasta que encuentre un \0 que es el fin del parrafo.
  {
    if (msg[i] == ' ' || msg[i] == '.'|| msg[i] == ',')       // si encontro un caracter delimitante la palabra guardada en el string, se compara con la base de datos de la blacklist
    {	      

      for(f=1;f!=blacklist_size;f++)
      {
        resu = my_strcmp(blacklist[f],palabra);  
        if (resu==0)                                          // si resultado == 0 => incremento la cantidad de palabras encontradas del mismo tipo
          cant[f] ++;          
      }
      for(a=0;a!=40;a++)                                      //borro la cadena
        *(palabra+a)='\0';
      c=-1;                                                   // pongo -1 asi cuando pase por c++, el valor de c sea 0
    }
    else
      *(palabra+c)=*(msg+i);                                  // si no se encuentra ningun caracter delimitante, los caracteres se alamcenan en este vector
  }
  return *cant ;                                              // devolvemos cantidad para no perder los datos
}
/**
* \fn void mostrar_estaditicas (char *blacklist[], int  cant [], int blacklist_size)
* \details  Esta funcion se encarga de imprimir por stderr los datos, del vector de enteros.
* \arg [in] blacklist: Dirección del arreglo de punteros a las cadenas de palabras prohibidas.
* \arg [in] cant: vector de interos que contiene la cantidad de palabras coincidentes
* \arg [in] blacklist_size: Cantidad de elementos de la lista de palabras prohibidas.
* \author Luciano Lopez
* \date 2016.07.07
*/

void mostrar_estaditicas (char *blacklist[], int  cant [], int blacklist_size)
{
  int f;
  for (f=1;f!=blacklist_size;f++)   
    fprintf(stderr,"La palabra    %s     aparecio       %d   veces. \n", blacklist[f], (*(cant+f)-1));
  fprintf(stderr,"\n");
}
