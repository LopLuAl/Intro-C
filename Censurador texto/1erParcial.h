#include <stdio.h>
#include <stdlib.h>


int    my_strlen 		 (char * str                                                   );
char * my_strcpy	         (char * strdst, char * strorg                                 );
int    my_strcmp 		 (const char *s1, const char *s2                               );
int    moderar                   (int blacklist_size, char *msg, char *blacklist[]             );
int    estadistica               (int blacklist_size, char *msg, char *blacklist[], int cant []);
void   mostrar_estaditicas       (char *blacklist[], int  cant [], int blacklist_size          );