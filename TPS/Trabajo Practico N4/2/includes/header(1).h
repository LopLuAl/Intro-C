#include <stdio.h> 
#include <stdlib.h>
/*! \file structcmd.h
    \brief A Documented file.
    
    Details.
*/
/*! \def MAX(a,b)
    \brief A macro that returns the maximum of \a a and \a b.
   
    Details.
*/
/*! \var typedef unsigned int UINT32
    \brief A type definition for a .
    
    Details.
*/
/*! \var int errno
    \brief Contains the last error code.
    \warning Not thread safe!
*/
/*! \fn int open(const char *pathname,int flags)
    \brief Opens a file descriptor.
    \param pathname The name of the descriptor.
    \param flags Opening flags.
*/
/*! \fn int close(int fd)
    \brief Closes the file descriptor \a fd.
    \param fd The descriptor to close.
*/
/*! \fn size_t write(int fd,const char *buf, size_t count)
    \brief Writes \a count bytes from \a buf to the filedescriptor \a fd.
    \param fd The descriptor to write to.
    \param buf The data buffer to write.
    \param count The number of bytes to write.
*/
/*! \fn int read(int fd,char *buf,size_t count)
    \brief Read bytes from a file descriptor.
    \param fd The descriptor to read from.
    \param buf The buffer to read into.
    \param count The number of bytes to read.
*/

//Prototipo de la funcion analis
/* Observar que le pasamos todas las variables las pasamos por referencia 
	asi nos evitamos de poner los return
*/
void analisis ( char *pepe[], int miargc, double *sump, double *sumn,double *sumt );

