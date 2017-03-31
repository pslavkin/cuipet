#ifndef MENU
#define MENU

#include <panel.h>
#include <sheet.hpp>
#include <pthread.h>
#include <../cdk/include/menu.h>

//----------------------------------------------------------------------------------------------------
class Menu{
public:
	static Sheet*	Main_Sheet;		//global
	static Menu*	Menu_Inst;
	static void 	Init_Menu 		(void);
	static void* 	Menu_Rti 		(void* Arg1);
	static void	Start_Menu_Menu		(void);
	static Sheet* 	Sheet4Panel		(PANEL* Panel);
	static Sheet* 	Sheet4Top_Panel		(void);
	static void 	Set_Menu 		(PANEL* Panel,const char* Menu_List[][MAX_SUB_ITEMS],unsigned char Items,int* Submenu_Size,int *Menu_Loc);
	static void	Parse_Menu_Menu		(int Selection);
	static char*	Set_File_Select 	(PANEL* Panel);
	
	pthread_t 	PT_Menu_Rti;
			Menu	 		(void);
	void 		Init_Super_Colours 	(unsigned char R,unsigned char G,unsigned char B,unsigned char From, unsigned char Count);
	unsigned char 	Set_Entry 		(PANEL* Panel,const char* Title,const char* Actual_Data,char* Data,unsigned short int Length);
	void 		Set_Slider 		(PANEL* Panel,unsigned int* Sel,unsigned int Min,unsigned int Max,unsigned int Fine_Step);

private:
};
#endif
//----------------------------------------------------------------------------------------------------
