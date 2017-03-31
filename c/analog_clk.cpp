#include <cdk/cdk.h>
#include <panel.h>
#include <pthread.h>

#include "sheet.hpp"
#include "menu.hpp"
#include <time.h>
#include <ball.h>

void Init_Analog_Clk(void)
{
//	Sheet::Create_New_Sheet_Inst(NULL,"Analog Clk 1");
//	Sheet::Create_New_Sheet_Inst(NULL,"Analog Clk 2");
}

unsigned short int Get_Actual_Time(void)
{
	timespec Time;
 	clock_gettime(CLOCK_MONOTONIC_RAW,&Time);
	return (Time.tv_sec*10)+(Time.tv_nsec/100000000);
//	return (Time.tv_sec&0x0FFF)<<4 | (Time.tv_nsec/100000000)&0x000F;
}
 
