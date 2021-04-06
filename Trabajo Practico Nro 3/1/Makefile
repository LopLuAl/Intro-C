#####ESTO ES UN MAKEFILE HECHO POR LUCIANO#####
##Variables
CC = gcc
CFLAGS = -g -c 
FLAG2 = -o
FLAG = -I /includes
### Declaracion Variable

EXE = prg
OBJS = funciones.o 1_1.o 
prg: 1_1.o funciones.o 
	$(CC)  $(OBJS) -o $@
1_1.o: 1_1.c #Para generara el 1_1.o necesito el 1_1.c!
	$(CC) $(CFLAGS) $< -o $@
funciones.o: funciones.c
	$(CC) $(CFLAGS) $< -o $@
doxy:
	doxygen Doxyfile
clean:
	rm -f $(EXE) $(OBJS) *~