#ifndef MENU
#define MENU

#include <panel.h>
#include <sheet.h>
#include <../cdk2/include/menu.h>

extern Sheet*		Main_Sheet;		//global
extern void 		Init_Menu 		(void);
extern void 		Init_Super_Colours 		(unsigned char R,unsigned char G,unsigned char B,unsigned char From, unsigned char Count);
extern void 		Start_Menu_Menu		(void);
extern void 		Parse_Menu_Menu		(int Selection);
extern void* 		Menu_Rti 		(void* Arg1);
extern unsigned char 	Set_Entry 		(PANEL* Panel,const char* Title,const char* Actual_Data,char* Data,unsigned short int Length);
extern char* 		Set_File_Select 	(PANEL* Panel);
extern void 		Set_Slider 		(PANEL* Panel,unsigned int* Sel,unsigned int Min,unsigned int Max,unsigned int Fine_Step);
extern void 		Set_Menu 		(PANEL* Panel,const char* Menu_List[][MAX_SUB_ITEMS],unsigned char Items,int* Submenu_Size,int *Menu_Loc);
extern Sheet* 		Sheet4Panel		(PANEL* Panel);
extern Sheet* 		Sheet4Top_Panel		(void);

#endif

