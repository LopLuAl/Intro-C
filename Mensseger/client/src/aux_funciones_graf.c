#include "header-funciones-graf.h"
/**
* \file   init_funciones_graf.c 
* \brief  Contiene funciones auxiliares de ncurses
* \author Luciano Lopez
* \date   2016.20.5
*/
/**
* \fn 		imprimir_MENU(MENU * my_menu, WINDOW * my_menu_win)
* \details  Imprime el menu en pantalla
* \arg      MENU * my_menu, WINDOW * my_menu_win 
* \return   void
* \author   Luciano Lopez
* \date     2016.12.5
*/
void imprimir_MENU(MENU * my_menu, WINDOW * my_menu_win)
{
    
    /* Print a border around the main window and print a title */
    box(my_menu_win, 0,0);
	print_in_middle(my_menu_win, 1, 0, 40, "Chat Proyecto TPO", COLOR_PAIR(1));
	
    mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
	mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
	mvprintw(LINES - 2, 0, "F2 to exit");
	    
    refresh();
        
	/* Post the menu */
	post_menu(my_menu);
	wrefresh(my_menu_win);
}
/**
* \fn 		print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
* \details  Imprime en el medio de una ventana
* \arg      WINDOW *win, int starty, int startx, int width, char *string, chtype color 
* \return   void
* \author   Luciano Lopez
* \date     2016.12.5
*/
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{	
    int length, x, y;
	float temp;
	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}
/**
* \fn 		void formar_lista( char * choices [], int sockfd)
* \details  Recibe los nombres de usuarios conectados del servidor y los coloca en un array
* \arg      char * choices [], int sockfd 
* \return   void
* \author   Luciano Lopez
* \date     2016.12.5
*/
void formar_lista( char * choices [], int sockfd)
{
    int     cantidad=0, i;
    char    name [11];
    
    while(1)
    {
        for(i=0;i<11;name[i++]='\0');               // Limpio constantemente el buffer
        if((i=read(sockfd,name,10))<0)              // Leo los datos...
            perror("Error leyendo los usuarios");
        name[i]='\0';
        if(0==strcmp(name,"!"))                     // El server cuando termina de mandarme la lista de usuarios conectados me manda '!' como Caracter delimitador
            break;
        choices[cantidad]=malloc(strlen(name));     // Reservamos memoria dinamica con malloc para cada elemento del array
        strcpy(choices[cantidad],name);             // Copiamos el string que llego por sockect al string que va a ser nuestro futuro menu
        cantidad++;
    }
    
    choices[cantidad+1]=(char *)NULL;

}
/**
* \fn 		ITEM ** crear_items_usarios(char * choices [])
* \details  Los nombre recibidos, los coloca en una estructura llamada ITEMs
* \arg      char * choices [] 
* \return   ITEM **
* \author   Luciano Lopez
* \date     2016.12.5
*/
ITEM ** crear_items_usarios(char * choices [])
{
    int     cantidad=0, i;
    ITEM ** mis_items;
    /* Create items */
    cantidad = ARRAY_SIZE(*choices);
    mis_items = (ITEM **)calloc(cantidad, sizeof(ITEM *));
    for(i = 0; i < cantidad; ++i)
        mis_items[i] = new_item(choices[i], choices[i]);
    return mis_items;
    
}
/**
* \fn 		WINDOW * setear_menu(MENU * menu) 
* \details  Configura el menu
* \arg      MENU * menu
* \return   WINDOW *
* \author   Luciano Lopez
* \date     2016.12.5
*/
WINDOW * setear_menu(MENU * menu) 
{
    int    fila,columna;
    WINDOW *menu_win;
    
    menu_opts_off(menu, O_SHOWDESC);
    getmaxyx(stdscr,fila,columna);
    menu_win = newwin(10, 49,((fila-10)/2) ,((columna-49)/2)); // Crea la ventana asociada al menu
    keypad(menu_win, TRUE);                                    // Asigna el telcado a la ventana
    set_menu_win(menu, menu_win);                              // Seteamos la ventana y la subventana
    set_menu_sub(menu, derwin(menu_win, 6, 48,3 ,1));
	set_menu_format(menu, 5, 3);
	set_menu_mark(menu, " * ");                               // Seteamos el caracter de indice para el menu
    box(menu_win, 0, 0);                                      // Imprimimos el recuadro del borde
    return menu_win;
}
/**
* \fn 		void enviar_msj     (char  mensaje [], int sockfd) 
* \details  Envia los mensajes 
* \arg      char  mensaje [], int sockfd
* \return   void
* \author   Luciano Lopez
* \date     2016.12.5
*/
void enviar_msj     (char  mensaje [], int sockfd)
{
    if(write(sockfd,mensaje,strlen(mensaje))<0)
    {   
        perror("Error");
        exit(0);
        
    }
}
/**
* \fn 		void recibir_mensaje(char  mensaje[], int sockfd) 
* \details  Recibe los mensajes
* \arg      char  mensaje[], int sockfd
* \return   void
* \author   Luciano Lopez
* \date     2016.12.5
*/
void recibir_mensaje(char  mensaje[], int sockfd)
{
    if(read(sockfd,mensaje,100)<0)
    {   
        perror("Error");
        exit(0);
        
    }
}