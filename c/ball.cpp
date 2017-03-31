#include <cdk/cdk.h>
#include <panel.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "screen_update.h"
#include "sheet.hpp"
#include "menu.hpp"
#include "ball.h"
#include "analog_clk.h"
#include <pthread.h>

	struct timespec Ball::Ball_Delay={0,50000000}; //100 milis
	Ball* 		Ball::Ball_Inst;

	void Ball::Init(void)
{
	Ball_Inst = new Ball;
	Ball_Inst->Set_Panel_User_Pointer(Ball_Inst);
	Ball_Inst->Set_Size(2,2);
	Ball_Inst->Set_Pos(10,10);
	Ball_Inst->Redraw_Box();
	Ball_Inst->Vel=2;
}

	void* Ball::Move(void* Arg1)
{
	while(1) {
		nanosleep(&Ball_Delay,&Ball_Delay);
		if(Ball_Inst->Vel>0){
			if(Ball_Inst->To_Left()==-1) Ball_Inst->Vel=-2;	
		}
		else
		if(Ball_Inst->Vel<0){
			if(Ball_Inst->To_Right()==-1) Ball_Inst->Vel=2;
		}
	}

}
	Ball::Ball():Sheet(NULL)
{
	Vel=0;
	pthread_create 	(&Pt_Ball_Rti, NULL, Move, NULL);
}

	Ball::~Ball(void)
{
	pthread_exit(&Pt_Ball_Rti);
}


//----------------------------------------------------------------------------------------------------







