#####ESTO ES UN MAKEFILE HECHO POR LUCIANO#####
##Variables
CC = gcc
CFLAGS = -g -c 
FLAG2 = -o
FLAG = -I /includes
### Declaracion Variable

EXE = prg
OBJS = funciones.o 3_2.o 
prg: 3_2.o funciones.o 
	$(CC)  $(OBJS) -o $@
3_2.o: 3_2.c #Para generara el 1_1.o necesito el 1_1.c!
	$(CC) $(CFLAGS) $< -o $@
funciones.o: funciones.c
	$(CC) $(CFLAGS) $< -o $@
doxy:
	doxygen Doxyfile
clean:
	rm -f $(EXE) $(OBJS) *~