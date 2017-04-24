#include <cdk.h>
#include <panel.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "sheet.hpp"
#include "welcome.hpp"
#include <iostream>
#include <thread>

//----------------------------------------------------------------------------------------------------
unsigned char 			Welcome::Printing=1;
const char* 			Welcome::Presentation= "CUIPET " VERSION ".............................";
unsigned int 			Welcome::Actual_Char=0;
unsigned int	 		Welcome::Rti_Delay=10; 
Sheet* 				Welcome::W;
//----------------------------------------------------------------------------------------------------
		Welcome::Welcome(void)
{
	W = new Sheet(NULL);
	W->Set_Panel_User_Pointer(W);
	W->Set_Name((char *)"CUIPET " VERSION);
	W->Full_Screen();
	W->Redraw_Box();
	wmove(W->Win,W->Max_Y()/3,W->Max_X()/3-sizeof(Presentation));
	update_panels();
	T = new std::thread(Print_Next_Character_Rti);
	while(Printing)
		;	
	delete W;	
}

//----------------------------------------------------------------------------------------------------
void Welcome::Print_Next_Character_Rti(void)
{
	unsigned char i=0;
	while(1) {
		std::this_thread::sleep_for(std::chrono::milliseconds(Rti_Delay));
		if(Presentation[Actual_Char]!=0) {
			update_panels();
			waddch(W->Win,Presentation[Actual_Char]|COLOR_PAIR(i+=1));
			Actual_Char++;
		}
		else {
			Printing=0;
			break;
		}
	}
}
//----------------------------------------------------------------------------------------------------

