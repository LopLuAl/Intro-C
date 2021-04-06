#include <header.h> 
int myStrlen (const char *pepe)
{
int i;
for(i=0;*(pepe+i)!='\0';i++);
return i;
}