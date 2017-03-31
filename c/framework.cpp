#include <cdk.h>
#include <panel.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "screen_update.h"
#include "sheet.hpp"
#include "menu.hpp"
#include "analog_clk.h"
#include "framework.hpp"

////----------------------------------------------------------------------------------------------------
	unsigned short int 	Framework::Inst_Count=0;
	Sheet* 			Framework::Inst_Buf[5]={NULL};

	void 	Framework::Create_Framework(void)
{
	unsigned short int i;
	for(i=0;i<(sizeof(Inst_Buf)/sizeof(Sheet*));i++) {
			char Name_Def[100];
			sprintf(Name_Def,"Instancia %d",i);
			Inst_Buf[i]=new Sheet(NULL);
 			Inst_Buf[i]->Set_Panel_User_Pointer(Inst_Buf[i]);
 			Inst_Buf[i]->Set_Name(Name_Def);
 			Inst_Buf[i]->Set_Size(3,Menu::Main_Sheet->Max_X()-2);
 			Inst_Buf[i]->Set_Pos(Menu::Main_Sheet->Max_Y()-(i+1)*3-1,1);
 			Inst_Buf[i]->Redraw_Box();
	}
}


