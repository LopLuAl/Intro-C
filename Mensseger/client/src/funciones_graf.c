#include "header-funciones-graf.h"
/**
* \file   funciones_graf.c 
* \brief  Contiene las funciones del menu grafico del cliente con ncurses
* \author Luciano Lopez
* \date   2016.12.5
*/
/*Notas importantes*/
/*
\field[0] -> Campo de usuario
\field[1] -> Campo de contraseña
\dato[0]  -> Usuario
\dato[1]  -> Contraseña
\dato[2]  -> 2 = Usuario Nuevo, 1 = Usuario Viejo
*/
//mandar tipo, usuario y contraseña
/**
* \fn 		void logueo_grafico (char * dato [], int sockfd)
* \details  Funcion principal que se encarg de administrar el menu principal
* \arg      char *dato []
*           int sockfd
* \return   void
* \author   Luciano Lopez
* \date     2016.12.5
*/     
void logueo_grafico (char * dato [], int sockfd)
{
    WINDOW *my_menu_win;
    MENU * my_menu ;
	int  c;
    char * seleccion [] =  {"Registrarse","Conectarse","Salir"};
	
    init_curses();
    my_menu=init_MENU();
    my_menu_win=config_menu_ppal(my_menu);
    
    imprimir_MENU(my_menu,my_menu_win);
    
    while((c = wgetch(my_menu_win)))
	{       
        switch(c)
        {	
            case KEY_DOWN:                                                          // Si presiono la flecha para abajo, va para abajo
                menu_driver(my_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:                                                            // Si presiono la flecha para arriba, va para arriba
                menu_driver(my_menu, REQ_UP_ITEM);
                break;
            case 10:                                                                // Enter 
                if(0==strcmp(seleccion[0],item_name(current_item(my_menu))))        // Me fijo si sellecciono Registrarse
                {
                    delwin(my_menu_win);                                            // Borro la ventana ya que voy a a pasar a otro menu
                    clear();                                                        // Borro la pantalla
                    formulario_reg(dato,sockfd);       
                    if (enviar_user_and_pass(dato,sockfd)<0)
                    {
                        unpost_menu(my_menu);                                       // Liberamos los recursos
                        free_menu(my_menu);
                        endwin();                                                   // Salimos del modo curses
                        exit(0);                                                    // Salimos del programa
                    }
                    imprimir_MENU(my_menu,my_menu_win);
                    break;
                }
                else if (0==strcmp(seleccion[1],item_name(current_item(my_menu))))  // Me fijo si selecciono logearse
                {
                    delwin(my_menu_win);
                    clear();
                    if (formulario_log(dato,sockfd)<0)                              // Si el usuario se equivoco y volvio para atras, se imprime el menu ppal de vuelta
                    {
                        imprimir_MENU(my_menu,my_menu_win);
                    }
                    else                                                            // Si no seguimos con el programa
                    {
                        unpost_menu(my_menu);
                        free_menu(my_menu);
                        endwin();
                        return;
                    }
                }
                else                                                                // Esta es la opccion de salir
                {
                    unpost_menu(my_menu);                                           // Liberamos los recursos
                    free_menu(my_menu);
                    endwin();                                                       // Salimos del modo curses
                    exit(0);                                                        // Salimos del programa
                }
                break;
            default:
                break;
        }
        wrefresh(my_menu_win);                                                       // Refrescamos la pantalla
	}	  
}

/**
* \fn 		void  formulario_reg(char *dato [], int sockfd)
* \details  Contiene el formulario para un usuario que se registra
* \arg      char *dato []
*           int sockfd
* \return   void
* \author   Luciano Lopez
* \date     2016.12.5
*/     
void  formulario_reg(char *dato [], int sockfd)
{
    WINDOW * form_win;
    FIELD  * field[3]; // poner define
	FORM   * my_form;
	int      ch;  
    int      row, col;
    
    getmaxyx(stdscr,row,col);                             // Obtengo las dimensiones del terminal
    init_and_set_FORM(field);                             // Inicio y seteo las opciones de los campos
    my_form = new_form(field);      
    // Creo un formulario asociado a los campos y por ultimo los asocio a la ventanas
    /**/
    form_win = newwin(10, 40,((row-10)/2) ,((col-40)/2)); // Creo una ventana
    set_form_sub(my_form, derwin(form_win, 0, 20,10,40)); // Asigno el formulario a una subventana
    set_form_win(my_form,form_win);
    /**/
    keypad(form_win, TRUE);                               // Asigno el teclado a la ventana del formulario
    wbkgd(form_win, COLOR_PAIR(1));                       // Cambio el color del fondo
    
    post_form(my_form);                                   // Posteo el formulario
    
    print_in_middle(form_win, 1, 0, 40, "Bienvenido NUEVO Usuario", COLOR_PAIR(2)); // Esta funcion imprime en el medio de la ventana
    mvprintw(LINES - 2, 0, "Usted eligio Registrarse, press F2 to GOBACK");         // Es como el printf pero de ncurses 
    mvprintw(LINES - 3, 0, "Ingrese SOLO Numeros y Letras en Ambos Casilleros ");
    mvprintw(LINES - 4 , 0, "CANTIDAD MAXIMA : 10 Caracteres Ambos casilleros ");
    
    wattron(form_win,COLOR_PAIR(1));                       // Activamos el par de color 1 para la ventana
    mvwprintw(form_win, 4, 10, "Usuario");                 // Es como el printf pero imprime solamente en la VENTANA
    mvwprintw(form_win, 6, 10, "pass");
    wattroff(form_win,COLOR_PAIR(1));                      // Desactivamos el par de color 1 para la ventana
    
    box(form_win, 0 , 0);                                  // Recuadra la ventana con una linea
    mvwaddch(form_win, 2, 0, ACS_LTEE);
    mvwhline(form_win, 2, 1, ACS_HLINE, 38);
    mvwaddch(form_win, 2, 39, ACS_RTEE);

    wrefresh(form_win);                                    // Refrescamos la ventna
    
    refresh();                                             // Refrescamos la pantalla
    
    while((ch = wgetch(form_win)) != KEY_F(2))
    {	
        switch(ch)
        {	    
            case KEY_DOWN:
                form_driver(my_form, REQ_NEXT_FIELD);      // Va al proximo campo
                form_driver(my_form, REQ_END_LINE);        // Va a el final del campo
                break;
            case KEY_UP:
                form_driver(my_form, REQ_PREV_FIELD);      // Va a el campo anterior
                form_driver(my_form, REQ_END_LINE);        // Va a el final del campo
                break;
            case KEY_LEFT:
                form_driver(my_form, REQ_LEFT_CHAR);       // Va hacia la derecha
                break;
            case KEY_RIGHT:
                form_driver(my_form, REQ_RIGHT_CHAR);      // Va hacia la izquierda
                break;
            case KEY_BACKSPACE:                            // Si presiono la tecla de borrar se borra 
                form_driver(my_form, REQ_DEL_PREV);
                break;
            case 10:                                       // Si apreto enter, entonces guardo todo lo que obtuve
                form_driver(my_form, REQ_VALIDATION);      // Esta linea sincroniza los buffers
                dato[0]=field_buffer(field[0],0);
                dato[1]=field_buffer(field[1],0);
                dato[2]= "2";                              // Si el tipo es 2 == Usuario nuevo
                delwin(form_win);
                return;
            default:
                form_driver(my_form, ch);
                break;      
        }
    }
    delwin(form_win);
    return;
}
/**
* \fn 		void  formulario_log(char *dato [], int sockfd)
* \details  Contiene el formulario para un usuario ya registrado
* \arg      char *dato []
*           int sockfd
* \return   void
* \author   Luciano Lopez
* \date     2016.12.5
*/     
int  formulario_log(char *dato [], int sockfd)
{
    
    WINDOW *form_win;
    FIELD  *field[3]; // poner define
	FORM   *my_form;
	
    int     ch;
    int     row, col;
    
    getmaxyx(stdscr,row,col);

    init_and_set_FORM(field);
    my_form = new_form(field);
    form_win = newwin(10, 40,((row-10)/2) ,((col-40)/2));
    set_form_sub(my_form, derwin(form_win, 0, 20,10,40));
    set_form_win(my_form,form_win);
    keypad(form_win, TRUE);
    wbkgd(form_win, COLOR_PAIR(4));
    
    post_form(my_form);
    
    print_in_middle(form_win, 1, 0, 40, "Bienvenido Usuario", COLOR_PAIR(3));
    mvprintw(LINES - 2, 0, "Usted eligio Logearse, press F2 to GOBACK");
    mvprintw(LINES - 3, 0, "Ingrese SOLO Numeros y Letras en Ambos Casilleros ");
    mvprintw(LINES - 4 , 0, "CANTIDAD MAXIMA : 10 Caracteres Ambos casilleros ");
    
    wattron(form_win,COLOR_PAIR(3));
    mvwprintw(form_win, 4, 10, "Usuario");
    mvwprintw(form_win, 6, 10, "pass");
    wattroff(form_win,COLOR_PAIR(3));
    
    box(form_win, 0 ,0);
    mvwaddch(form_win, 2, 0, ACS_LTEE);
    mvwhline(form_win, 2, 1, ACS_HLINE, 38);
    mvwaddch(form_win, 2, 39, ACS_RTEE);
    wrefresh(form_win);
    refresh();
    
    
    while((ch = wgetch(form_win)) != KEY_F(2))
    {	
        switch(ch)
        {	    
            case KEY_DOWN:
                form_driver(my_form, REQ_NEXT_FIELD);
                form_driver(my_form, REQ_END_LINE);
                break;
            case KEY_UP:
                form_driver(my_form, REQ_PREV_FIELD);
                form_driver(my_form, REQ_END_LINE);
                break;
            case KEY_LEFT:
                form_driver(my_form, REQ_LEFT_CHAR);
                break;
            case KEY_RIGHT:
                form_driver(my_form, REQ_RIGHT_CHAR);
                break;
            case KEY_BACKSPACE:                         //con borrar comun
                form_driver(my_form, REQ_DEL_PREV);
                break;
            case 10:
                form_driver(my_form, REQ_VALIDATION);
                dato[0]=field_buffer(field[0],0);
                dato[1]=field_buffer(field[1],0);
                dato[2]= "1";                           // Si el tipo es 1 == Usuario viejo
                delwin(form_win);
                return 0;
            default:
                form_driver(my_form, ch);
                break;      
        }
        
    }
    delwin(form_win);
    return -1;
}       
/**
* \fn 		void mostrar_lista_grafico(int sockfd)
* \details  Muestra una lista de usuarios conectados y la interfaz de comunicacion
* \arg      int sockfd
* \return   void
* \author   Luciano Lopez
* \date     2016.12.5
*/   

int mostrar_lista_grafico(int sockfd)
{
        
    int     cantidad=0, i;
    char *  choices[MAX_USR_CONECT] = {};
   
    ITEM ** mis_items;
	MENU *  menu;
    WINDOW *menu_win;
    formar_lista(choices, sockfd);              // Coloca los nombre de usarios conectados en un ARRAY
    mis_items=crear_items_usarios(choices);     // Convierte el array en una lista de ITEMS
	menu = new_menu((ITEM **)mis_items);        // Creo el menu
    menu_win=setear_menu(menu);                 // Seteo el menu
	attron(COLOR_PAIR(2));
	mvprintw(LINES - (LINES-3), 0, "Lista de usuarios conectados:");
	attroff(COLOR_PAIR(2));
	refresh();
	post_menu(menu);                           // Imprimo el menu
	wrefresh(menu_win);
	while((i = wgetch(menu_win)) != KEY_F(2))
    {       
        switch(i)
        {	
            case KEY_DOWN:
                menu_driver(menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(menu, REQ_UP_ITEM);
                break;
            case KEY_LEFT:
                menu_driver(menu, REQ_LEFT_ITEM);
                break;
            case KEY_RIGHT:
                menu_driver(menu, REQ_RIGHT_ITEM);
                break;
            case KEY_NPAGE:
                menu_driver(menu, REQ_SCR_DPAGE);
                break;
            case KEY_PPAGE:
                menu_driver(menu, REQ_SCR_UPAGE);
                break;
            case 10: // Enter 
                write(sockfd,"enter",sizeof("enter"));
                hablar(sockfd, item_name(current_item(menu)));
            case KEY_F(5):
                if (    write(sockfd,"!",strlen("!"))   <   0)  // Mando este Caracter '!' para decirle al server que me mando la lista de usarios conectados
                    perror("Error: ");
                unpost_menu(menu);
                free_menu(menu);
                for(i = 0; i < cantidad; ++i)
                    free_item(mis_items[i]);
                endwin(); 
                return -1;
                 break;
        }
        wrefresh(menu_win);
	}
	//Libero los recursos tomados del sistema
    unpost_menu(menu);
    free_menu(menu);
    for(i = 0; i < cantidad; ++i)
            free_item(mis_items[i]);
    endwin();
    return 0 ;
    ////////////////////////////////
}
/**
* \fn 		void hablar(int sockfd, char const *  user)
* \details  Funcion que manda los mensajes
* \arg      int sockfd, char const *  user
* \return   void
* \author   Luciano Lopez
* \date     2016.12.5
*/ 
void hablar(int sockfd, char const *  user)
{

    FIELD  *field[ELEMENTOS];
	FORM   *my_form;
	WINDOW *my_form_win;
	int  rows, cols,startx, starty;
    char texto[30];
    clear();
    mvprintw(LINES - (LINES-3), 0, "Usted elegio hablar con.....%s",user);
    refresh();
    sleep(1);
    clear();
    refresh();
    if ( write(sockfd,user,strlen(user))<0) // mando el nombre de usuario a conectar
        perror("Error: ");
    sprintf(texto,"Chat con: %s",user);
    mvprintw(LINES - 2, 0, "Para salir del programa, presiona F2");
    mvprintw(LINES - 3, 0, "Para Actualizar la pantalla presione  F5");
    //Inicializacion de los campos
	field[0] = new_field(1, 70, 3, 1, 0, 0);
	field[1] = new_field(1, 70, 8, 1, 0, 0);
	field[2] = NULL;

	//Seteo de las opciones de los campos
	set_field_back(field[0], A_UNDERLINE);
    field_opts_off(field[0],O_EDIT);      // Este campo es para que lo que dijo el otro usuario no pueda ser re escrito
	set_field_back(field[1], A_UNDERLINE); 
	// Creacion del formulario
	my_form = new_form(field);
    // Calulo del centro de la pantalla
    scale_form(my_form, &rows, &cols);
    starty = (LINES - rows) / 2;	
    startx = (COLS - cols) / 2;	
	// Calculo del tamaño requerido por el formulario
	scale_form(my_form, &rows, &cols);
	//Creacion de la ventana asociada al formulario
    my_form_win = newwin(rows + 4, cols + 4, starty, startx);
    // Ascosiacion del telcado a la ventana
    keypad(my_form_win, TRUE);

	// Seteo de la ventana y sub ventana
    set_form_win(my_form, my_form_win);
    set_form_sub(my_form, derwin(my_form_win, rows, cols, 2, 2));

	// Impresion del titulo y recuadro
    box(my_form_win, 0, 0);
	print_in_middle(my_form_win, 1, 0, cols + 4, texto, COLOR_PAIR(1));
	// Impresion del formulario con la ventana
	post_form(my_form);
	wrefresh(my_form_win);
    mvwprintw(my_form_win,3,3, "%s dijo: ", user);
    mvwprintw(my_form_win,8,3, "Yo dije: ");
	wmove(my_form_win, 9,4);
    // Nos movemos al ultimo elemento del formulario asi el cursor queda posicionado en el campo para que nostros hablemos
    form_driver(my_form,REQ_LAST_FIELD);
    refresh();
    wrefresh(my_form_win);
    administrar_mensajeria(sockfd,my_form,field,my_form_win);
    /*Notas importantes*/
    /*
    \field[0] -> Campo de Destinatario
    \field[1] -> Campo de Remitente
    */
}
void administrar_mensajeria(int sockfd, FORM * my_form, FIELD * field [], WINDOW * my_form_win)
{

    int ch = 0, i, max_fd;
    char mensaje [MAX_LONG_MSJ];
    for(i=0;i<MAX_LONG_MSJ;mensaje[i++]='\0');
    fd_set my_set, aux;
    FD_ZERO(&my_set);
    FD_SET(0,&my_set);
    FD_SET(sockfd,&my_set);
    
    
    max_fd = buscar_max(sockfd,0);
    
    aux=my_set;
    
    while(1)
    {
        my_set=aux; 
        select(max_fd+1,&my_set,NULL,NULL,NULL);
        if (FD_ISSET(0, &my_set))
        {
            if((ch = wgetch(my_form_win)))
            {
                switch(ch)
                {
                    case KEY_DOWN:
                        form_driver(my_form, REQ_NEXT_FIELD);
                        form_driver(my_form, REQ_END_LINE);
                        wrefresh(my_form_win);
                        refresh();
                        break;
                    case KEY_UP:
                        form_driver(my_form, REQ_PREV_FIELD);
                        form_driver(my_form, REQ_END_LINE);
                        break;
                    case KEY_BACKSPACE:                                 //con borrar comun
                        form_driver(my_form, REQ_DEL_PREV);
                        wrefresh(my_form_win);
                        refresh();
                        break;
                    case 10:
                        form_driver(my_form, REQ_VALIDATION);           // Se sincroniza los buffers
                        enviar_msj(field_buffer(field[1],0),sockfd);    // Enviamos el mensaje
                        set_field_buffer(field[1], 0, "");              // Limpiamos el recuadro que nostros mandamos el texto
                        set_field_just(field[0], JUSTIFY_LEFT);         // Colocamos el texto en el otro campo, con un justificado a la izquierda
                        set_field_buffer(field[0],0,mensaje);           
                        for(i=0;i<MAX_LONG_MSJ;mensaje[i++]='\0');      // Limpiamos el buffer
                        wrefresh(my_form_win);
//                         form_driver(my_form, REQ_PREV_FIELD);           // Nos movemos de vuelta al campo que queremos para seguir mandando texto
//                         form_driver(my_form, REQ_PREV_FIELD);
                        refresh();
                        break;
                    case KEY_F(2):                                      // Si apretamos F2 salimos entonces liberamos los recursos del sistema
                        unpost_form(my_form);
                        free_form(my_form);
                        free_field(field[0]);
                        free_field(field[1]); 
                        endwin();
                        exit(0);
                        break;
                    default:
                        form_driver(my_form, ch);
                        break;
                }
            }
        }
        if(FD_ISSET(sockfd,&my_set))
        {
            refresh();
            recibir_mensaje(mensaje,sockfd);                // Recibimos el mensaje
            set_field_just(field[0], JUSTIFY_LEFT);         // Colocamos el texto en el otro campo, con un justificado a la izquierda
            set_field_buffer(field[0],0,mensaje);           
            wrefresh(my_form_win);
            refresh();
        }
    }    
	close(sockfd);
	return ;
}
int buscar_max (int n1, int n2)
{
    int  mayor = 2;
    
    if (n1>mayor)
    {
        mayor=n1;
        return mayor;
    }
    else if(n2>mayor)
    {
        mayor=n2;
        return mayor;
    }
    else
        return mayor;
}














































































/*
            */
// //                 unpost_menu(menu);
// //                 free_menu(menu);
// //                 for(i = 0; i < cantidad; ++i)
// //                     free_item(mis_items[i]);
// // //                 endwin();
// //                 formar_lista(choices, sockfd);              // Coloca los nombre de usarios conectados en un ARRAY
// //                 mis_items=crear_items_usarios(choices);     // Convierte el array en una lista de ITEMS
// //                 menu = new_menu((ITEM **)mis_items);        // Creo el menu
// //                 menu_win=setear_menu(menu);                 // Seteo el menu
// //                 attron(COLOR_PAIR(2));
// //                 mvprintw(LINES - (LINES-3), 0, "Lista de usuarios conectados REFRESCADOS !!!:");
// //                 attroff(COLOR_PAIR(2));
// //                 post_menu(menu);                           // Imprimo el menu
// //                 wrefresh(menu_win);
// //                 refresh();
//                 unpost_menu(menu);
//                 free_menu(menu);
//                 for(i = 0; i < cantidad; ++i)
//                 free_item(mis_items[i]);
//                 endwin();
//                 return -1;
//                 break;
