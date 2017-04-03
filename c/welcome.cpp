#include <cdk.h>
#include <panel.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "sheet.hpp"
#include "welcome.hpp"

//----------------------------------------------------------------------------------------------------
pthread_t 			Welcome::PT_Rti;
unsigned char 			Welcome::Printing=1;
const char* 			Welcome::Presentation="CUIPET "VERSION"            .";
unsigned int 			Welcome::Actual_Char=0;
struct timespec 		Welcome::Rti_Delay={0,150000000}; 
Sheet* 				Welcome::W;
//----------------------------------------------------------------------------------------------------
	void 	Welcome::Create_Welcome(void)
{
	W = new Sheet(NULL);
	W->Set_Panel_User_Pointer(W);
	W->Set_Name((char *)"CUIPET "VERSION);
	W->Full_Screen();
	W->Redraw_Box();
	pthread_create 	(&PT_Rti, NULL, Print_Next_Character_Rti, NULL);
	wmove(W->Win,W->Max_Y()/3,W->Max_X()/3-sizeof(Presentation));
	update_panels();
	while(Printing)
		;	
	delete W;	
}

//----------------------------------------------------------------------------------------------------
void* Welcome::Print_Next_Character_Rti(void* Arg1)
{
	while(1) {
		nanosleep(&Rti_Delay,&Rti_Delay);
		if(Presentation[Actual_Char]!=0) {
			update_panels();
			waddch(W->Win,Presentation[Actual_Char]);
			Actual_Char++;
		}
		else {
			Printing=0;
			break;
		}
	}
}
//----------------------------------------------------------------------------------------------------

