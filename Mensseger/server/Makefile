mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
PROJECT := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))

CC := gcc

SRC_PATH := ./src
INC_PATH := ./inc
OUT_PATH := .
OBJ_PATH := ./obj

INCLUDES := -I./inc
LFLAGS   := -Wall
CFLAGS   := -Wall -c

SRC_FILES := $(wildcard $(SRC_PATH)/*.c)
INC_FILES := $(wildcard $(INC_PATH)/*.h)
OBJ_FILES := $(subst $(SRC_PATH),$(OBJ_PATH),$(SRC_FILES:.c=.o))

LIBS := -llistas -lsock
LD_FILE := 
LIB_PATH := -L./libs

$(PROJECT): $(OBJ_FILES)
	@echo "*** Linking project $(PROJECT) ***"
	$(CC) $(LIB_PATH) $(LFLAGS) $(LD_FILE) -o $(OUT_PATH)/$(PROJECT).bin $(OBJ_FILES) $(LIBS)
	@echo ""

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo "*** Compiling C file $< ***"
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@ 
	@echo ""

clean:
	rm -f $(OBJ_PATH)/*.*
	rm -f $(OUT_PATH)/*.*

lib:
	gcc -c ./src_lib/lista-lib.c -o ./src_lib/libreria.o -I./inc
	ar rcs ./libs/liblistas.a ./src_lib/libreria.o
	
	gcc -c -o ./src_lib/sock-lib.o ./src_lib/sock-lib.c -g -Wall -I./inc
	ar rcs ./libs/libsock.a ./src_lib/sock-lib.o
	
commit: cleanall
	svn add --force *
	svn ci -m"Nueva versión de $(EXEC)"
	
doxy:
	doxygen Doxyfile