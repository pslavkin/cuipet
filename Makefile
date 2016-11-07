CC=g++
LIBS= -lncurses -lpthread  -lpanel -lrt -L lib/ -lcdk_ps -lX11 -lGL -lGLU -lglut

SRC_DIR=./c
EXE_DIR=./exe


_OBJ= main.o screen_update.o menu.o sheet.o analog_clk.o ball.o
OBJ_DIR=./obj
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

_DEP = screen_update.h menu.h sheet.h analog_clk.h ball.h
DEP_DIR=./h
DEP = $(patsubst %,$(DEP_DIR)/%,$(_DEP))


sheet: ${OBJ}
	${CC} -o ${EXE_DIR}/$@ $^ ${LIBS}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${DEP}
	${CC}  -g -c -o $@  $< -I${DEP_DIR} 

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp ${DEP}
	${CC}  -g -c -o $@  $< -I${DEP_DIR} 
clean:
	@rm -f ${EXES} ${OBJ_DIR}/*
