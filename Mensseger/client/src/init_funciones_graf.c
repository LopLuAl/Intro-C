#include "header-funciones-graf.h"
/**
* \file   init_funciones_graf.c 
* \brief  Contiene las funciones inicio de curses y configuracion de ncurses
* \author Luciano Lopez
* \date   2016.12.5
*/
/**
* \fn 		void init_curses(void)
* \details  Inicializa curses
* \arg      void
* \return   void
* \author   Luciano Lopez
* \date     2016.12.5
*/     
void init_curses(void)
{
    initscr();                                                             // Inicializo curses
    start_color();                                                         // Inicializo los collores
    noecho();                                                              // No hago eco de lo que escribo
    keypad(stdscr, TRUE);                                                  // Asigno el teclado a la tty
    init_pair(1, COLOR_RED, COLOR_YELLOW);                                 // Inicializo un par de colores
    init_pair(2, COLOR_RED, COLOR_CYAN);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_BLACK, COLOR_CYAN);
    assume_default_colors(COLOR_RED,COLOR_BLUE);                           // Cambio de color las letras y el fondo del tty en gral
}
/**
* \fn 		MENU * init_MENU(void)
* \details  Inicializa el menu con las opciones que apareceran en pantalla 
* \arg      void
* \return   MENU *
* \author   Luciano Lopez
* \date     2016.12.5
*/
MENU * init_MENU (void)
{
    char * choices[] = {"Registrarse","Conectarse","Salir",(char *)NULL}; // Elementos del menu, el ultimo elemento como una lista, apunta a NULL
    ITEM **my_items;
    MENU * my_menu ;
    int i,n_choices;
    
    n_choices = ARRAY_SIZE(choices);                                       // Obtengo la longitud del ARRAY
    my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));                 // Reservo memoria para el array, el tamaño es de tamaño ITEMqq
    
    for(i = 0; i < n_choices; ++i)
        my_items[i] = new_item(choices[i], choices[i]);                    // Creo el nuevo item
	
    my_menu = new_menu((ITEM **)my_items);                                 // Creo el menu
    
    return my_menu;
}
/**
* \fn 		void init_and_set_FORM(FIELD * field[])
* \details  Se encarga de configurar el menu principal
* \arg      MENU *my_menu 
* \return   WINDOW * 
* \author   Luciano Lopez
* \date     2016.12.20
*/
WINDOW * config_menu_ppal(MENU *my_menu)
{
    WINDOW *my_menu_win;
    int   row, col;
    
    getmaxyx(stdscr,row,col);                                       // Obtengo las dimensiones de la pantalla
    my_menu_win = newwin(10, 40,((row-10)/2) ,((col-40)/2));        // Creo una ventana centrada
    wbkgd(my_menu_win, COLOR_PAIR(2));                              // Asigno el color de fondo 2 a la ventana
    
    set_menu_win(my_menu, my_menu_win);                             // Asigno el menu a la ventana
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 15, 4, 11));       // Asigno una subventana
    set_menu_mark(my_menu, " -> ");                                 // Creo un "Cursor"
    keypad(my_menu_win, TRUE);                                      // Asigno el Teclado a la ventana
    
    return my_menu_win;
}
/**
* \fn 		void init_and_set_FORM(FIELD * field[])
* \details  Inicia y setea los campos del formulario para usuario previamente registrado
* \arg      FIELD * field[] 
* \return   void
* \author   Luciano Lopez
* \date     2016.12.5
*/
void init_and_set_FORM(FIELD * field[])
{
    //Inicio los campos del formulario
    
    ////////////////////////////////////////
    field[0] = new_field(1, 10, 4, 18, 0, 0);
	field[1] = new_field(1, 10, 6, 18, 0, 0);
	field[2] = NULL;
    ////////////////////////////////////////
    
    // Configuro las opciones del formulario
	set_field_back(field[0], A_UNDERLINE);                                 // Este campo tendra una linea subrayada   
    field_opts_off(field[0], O_AUTOSKIP);                                  // En teoria no podes salir de este campo hasta que este completo
    set_field_type(field[0],               
                   TYPE_ALNUM,                                             // Solamente acepta Caracteres alfanumericos
                   LONG        );                                          // Cantidad maxima de caracteres por campo
    set_field_back(field[1], A_UNDERLINE);                          
    field_opts_off(field[1], O_AUTOSKIP);               
    field_opts_off(field[1], O_PUBLIC);                                    // Este campo lo que pongas no estara visible
    set_field_type(field[1],               
                   TYPE_ALNUM,             
                   LONG        );            
   
}
/*Notas importantes*/
/*
\field[0] -> Campo de usuario
\field[1] -> Campo de contraseña
*/




















                  
