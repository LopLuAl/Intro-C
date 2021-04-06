/**
 * DOXYGEN COMMENTS
 *
 * @file   header.h
 *
 * @Author Fuschetto, Marotta, Lopez.
 *
 * @date   05/12/2016 [DD/MM/YYYY]
 *
 * @brief  
 *
 * @todo   What's to do?
 */


#ifndef aux2
#define aux2

/* **************************************************************** */
/*                              INCLUDEs                            */

/*Header para liblista*/
#include "header-lib.h"

/*Header para libsocket*/
#include "sock-lib.h"

/*Header's otros*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "sock-lib.h"
#include <sys/wait.h>
#include <signal.h>
#include "header-maxfds.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

/* **************************************************************** */
/*                              DEFINEs                             */
#define LARGO_USR_PW 10
#define QUIERO_REGISTRARME "2"
#define QUIERO_CONECTARME "1"
#define MAX_MNJS 150
#define FIFO1 "./FIFOS/my_pipe_1"
#define FIFO2 "./FIFOS/my_pipe_2"

/* **************************************************************** */
/*                               CODE                               */

NODO *  agregarnodo     (                                 );
void    recuperarlista  (NODO ** head                     );
void    crearlistas     (NODO ** head,char user [],char password [], TIPO t );
void    sigalrm_hand    (int senial                       );
void    sigchld_hand    (int senial                       );
void 	salvarlista	(NODO * head			  );
void 	imprimir	(NODO *head			  );
void 	signaltrap	(				  );
void 	funcion_sockdup (int				  );
void    funcion_leo_nombre_y_pw			(int,char*,char*		);
void    funcion_agrega_a_conectados		(char*				);
void 	funcion_registra			(char*,int			);
void    funcion_mando_opciones_de_conexiones	(int				);
void 	funcion_reciba_opcion_elegida		(int, char*			);
void    funcion_conecta_con_la_opcion_elegida	(char*, int	, char *	);
int	analisis_de_USR_PID			(char*, char*			);
void 	lo_conecto_con				(char*,char*,int		);
void 	funcion_login				(char[], char[]			);
void	creo_fifo2				(int*				);
void	creo_fifo1				(int*				);
int	busco_pid_de_la_opcion_elegida		(				);
void 	aviso_que_me_llego			(int				);
void crear_propio_fifo(int , char * );
int funcion_check_us_pw(char usuario[],char contrasenia[]) ;
#endif
