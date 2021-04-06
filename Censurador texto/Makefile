#Agregar nombre del objeto ejecutable a generar por ld
EXEC   = parcial
######################################################################
CC     = gcc
CFLAGS = -c -Wall -I.
LDFLAGS=  -g -Wall
#Agregar nombres de los objetos reubicables que generará el compilador
OBJS   = main.o funcs.o
######################################################################
SOURCES= $(OBJS:.o=.c)
HEADERS= *.h

$(EXEC): $(OBJS) Makefile
	$(CC) $(LDFLAGS)  $(OBJS) -o $@
%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

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
