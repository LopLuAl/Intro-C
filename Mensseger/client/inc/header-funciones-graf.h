/**
* \file   header-funciones-graf.h 
* \brief  Contiene los includes de la libreria ncurses y los prototipos de las funciones para el menu grafico
* \author 
* \date   2016.12.5
*/

#include <menu.h>
#include <form.h>
#include <stdlib.h>
#include <string.h>
/*Include para la libreria estatica de sockect*/
#include "header-sock-lib.h"
// #include "header-client.h"
/*Include para la funcion de int enviar_user_and_pass(char *dato [], int sockfd) */
#include "header-funciones-client.h"
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define LONG 10
#define ELEMENTOS 3
#define MAX_USR_CONECT 50 
#define MAX_LONG_MSJ 150
// #define CTRLD 	4


void init_and_set_FORM(FIELD * field[]);
void imprimir_MENU(MENU * my_menu, WINDOW * my_menu_win);
MENU * init_MENU(void);
void init_curses(void);
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
void logueo_grafico (char * dato [], int sockfd);
void formulario_reg(char *dato [], int sockfd);
int formulario_log(char *dato [], int sockfd);
int mostrar_lista_grafico(int sockfd); 
void hablar(int sockfd, char const *  user);
void enviar_msj     (char  mensaje [], int sockfd);
void recibir_mensaje(char   mensaje[], int sockfd);
WINDOW * config_menu_ppal(MENU *menu);
void set_form_reg(WINDOW *form_win,FIELD *field[],FORM  *my_form);
void la (WINDOW * form_win, FIELD  * field[],FORM   * my_form);
void formar_lista( char * choices [], int sockfd);
ITEM ** crear_items_usarios(char * choices []);
WINDOW * setear_menu(MENU * menu) ;
int buscar_max (int n1, int n2);
void administrar_mensajeria(int sockfd, FORM * my_form, FIELD * field [],WINDOW * my_form_win);