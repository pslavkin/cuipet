CC=g++
LIBS= -lncurses -lpthread  -lpanel -lrt -L lib/ -lcdk_ps -lX11 -lGL -lGLU -lglut

SRC_DIR=./c
EXE_DIR=./exe


_OBJ= cuipet.o status_bar.o stretcher.o screen_update.o menu.o ncurses_pthread.o sheets.o histograms.o
OBJ_DIR=./obj
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

_DEP = status_bar.h stretcher.h screen_update.h menu.h ncurses_pthread.h sheets.h histograms.h
DEP_DIR=./h
DEP = $(patsubst %,$(DEP_DIR)/%,$(_DEP))


cuipet: ${OBJ}
	${CC} -o ${EXE_DIR}/$@ $^ ${LIBS}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${DEP}
	${CC}  -g -c -o $@  $< -I${DEP_DIR} 

clean:
	@rm -f ${EXES} ${OBJ_DIR}/*
