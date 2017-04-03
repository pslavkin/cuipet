CC=g++
LIBS= -lncurses -lpthread  -lpanel -lrt -L lib/ -lcdk_ps_64 

#-lX11 -lGL -lGLU -lglut

SRC_DIR=./c
EXE_DIR=./exe


_OBJ= main.o screen_update.o menu.o sheet.o analog_clk.o ball.o framework.o key_capture.o welcome.o
OBJ_DIR=./obj
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

_DEP = screen_update.h menu.hpp sheet.hpp analog_clk.h ball.h framework.hpp key_capture.hpp welcome.hpp
DEP_DIR=./h
DEP = $(patsubst %,$(DEP_DIR)/%,$(_DEP))

CDK_DEP_DIR=./cdk/include/

sheet: ${OBJ}
	${CC} -o ${EXE_DIR}/$@ $^ ${LIBS}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${DEP}
	${CC}  -g -c -o $@  $< -I${DEP_DIR} -I${CDK_DEP_DIR} 
 

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp ${DEP}
	${CC}  -g -c -o $@  $< -I${DEP_DIR} -I${CDK_DEP_DIR} 

clean:
	@rm -f ${EXES} ${OBJ_DIR}/*
