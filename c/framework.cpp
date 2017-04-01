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
	Sheet* 			Framework::Inst_Buf[MAX_SHEETS]={NULL};
	unsigned char 		Framework::Actual_Sheet=0;
	unsigned char 		Framework::Full_Screen=0;

	void 	Framework::Create_Framework(void)
{
	unsigned short int i;
	for(i=0;i<MAX_SHEETS;i++) {
			char Name_Def[100];
			sprintf(Name_Def,"Instancia %d",i);
			Inst_Buf[i]=new Sheet(NULL);
 			Inst_Buf[i]->Set_Panel_User_Pointer(Inst_Buf[i]);
 			Inst_Buf[i]->Set_Name(Name_Def);
 			Inst_Buf[i]->Set_Pos(Menu::Main_Sheet->Max_Y()-(i+1)*3-1,1);
 			Inst_Buf[i]->Set_Size(3,Menu::Main_Sheet->Max_X()-2);
 			Inst_Buf[i]->Redraw_Box();
	}
	Select_Sheet(3);
}

	void 	Framework::Select_Sheet(unsigned char Sheet)
{
	unsigned char i;
	for(i=0;i<Sheet;i++) {	//para los sheets menores al seleccionado
 			Inst_Buf[i]->Set_Size(3,Menu::Main_Sheet->Max_X()-2);
 			Inst_Buf[i]->Set_Pos(Menu::Main_Sheet->Max_Y()-(i+1)*3-1,1);
	}
			//para el seleccionado
 			Inst_Buf[i]->Set_Size(1,1);
 			Inst_Buf[i]->Set_Pos(3*(MAX_SHEETS-i-1)+1,1);
 			Inst_Buf[i]->Set_Size(Menu::Main_Sheet->Max_Y()-i*3-2-3*(MAX_SHEETS-i-1),Menu::Main_Sheet->Max_X()-2);

			//para los mayores al 
	for(i++;i<MAX_SHEETS;i++) {
 			Inst_Buf[i]->Set_Size(3,Menu::Main_Sheet->Max_X()-2);
 			Inst_Buf[i]->Set_Pos(3*(MAX_SHEETS-i-1)+1,1);
	}
	Actual_Sheet=Sheet;		//este es el sheet que se supone activo.
	Inst_Buf[Sheet]->Top();		//y lo mando a top
		
}

	void 	Framework::Select_Next_Sheet(void)
{
	if(Actual_Sheet<(MAX_SHEETS-1)) {
		Select_Sheet(Actual_Sheet+1);	
		Full_Screen=0;
	}
}
	void 	Framework::Select_Prev_Sheet(void)
{
	if(Actual_Sheet>0) {
		Select_Sheet(Actual_Sheet-1);	
		Full_Screen=0;
	}
}
	void 	Framework::Toogle_Actual_Sheet_Full_Screen(void)
{
	if(Full_Screen==0)
		Inst_Buf[Actual_Sheet]->Full_Screen();
	else
		Select_Sheet(Actual_Sheet);
	Full_Screen^=0x01;
}


