#Agregar nombre del objeto ejecutable a generar por ld
EXEC   = 3.3
######################################################################
CC     = gcc
CFLAGS = -g -c -Wall -I./includes -lm
LDFLAGS=  -g -Wall -lm
#Agregar nombres de los objetos reubicables que generará el compilador
OBJS   = 3_3.o funciones.o
######################################################################
SOURCES= $(OBJS:.o=.c)
HEADERS= *.h

$(EXEC): $(OBJS)
	$(CC) -lm $(LDFLAGS)  $(OBJS) -o $@
%.o: %.c Makefile
	$(CC) -lm $(CFLAGS) -c $< -o $@

all: $(EXEC) doxy

doxy:
	doxygen Doxyfile

clean:
	rm -f $(EXEC) $(OBJS) *~

new: clean $(EXEC)

cleanall: clean
	rm -r -f doxy

commit: cleanall
	svn add --force *
	svn ci -m"Nueva versión de $(EXEC)"
