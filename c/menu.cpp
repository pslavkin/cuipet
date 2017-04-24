#include <cdk.h>
#include <menu.hpp>
#include <pthread.h>
#include <panel.h>
#include <math.h>

#include "sheet.hpp"
#include "screen_update.h"
#include "analog_clk.h"

//----------------------------------------------------------------------------------------------------
Menu*	Menu::Menu_Inst;
Sheet*	Menu::Main_Sheet;

void	Menu::Init_Menu(void)
{
	Menu_Inst=new Menu();	
}
	Menu::Menu(void)
{
	Main_Sheet=new Sheet(initscr());	
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	//initCDKColor ();
	Menu::Init_Super_Colours(1,1,0, 1 ,253);
	curs_set(0);
	Main_Sheet->Set_Panel_User_Pointer(Main_Sheet);
	Main_Sheet->Set_Name((char*)"Main");
	Main_Sheet->Full_Screen();
	Main_Sheet->Redraw_Box();
}
//----------------------------------------------------------------------------------------------------
void Menu::Init_Super_Colours(unsigned char R,unsigned char G,unsigned char B,unsigned char From, unsigned char Count)
{
	unsigned short int i,Bg,Pair;
	Pair=From;	 		//los primeros 64 se los regalo a CDK en su llamada a initCDKColor
	Bg=From;				//cdk usa solo 8 colores... me agarro el resto (parece que tambien usa el 15...raaaro)
	for(i=0;i<Count;i++) 	{ 	 	//no me puedo pasar de 255 pares... no da mas la funcion PAIR_NUMBER.. si no fuera por eso podria seguir...
		init_pair (Pair,255,Bg); 	
		
		init_color(Bg,  sqrt(pow(1000,2)-pow(((Count-i)*1000)/Count,2))*R,
				sqrt(pow(1000,2)-pow(((Count-i)*1000)/Count,2))*G,
				sqrt(pow(1000,2)-pow(((Count-i)*1000)/Count,2))*B);
		Bg++;
		Pair++;
	}
}
//----------------------------------------------------------------------------------------------------
void Menu::Set_Menu (PANEL* Panel,const char *Menu_List[MAX_MENU_ITEMS][MAX_SUB_ITEMS],unsigned char Items,int* Submenu_Size,int *Menu_Loc)
{
	unsigned short int	Selection;
	CDKSCREEN *Cdk		=initCDKScreen 		(panel_window(Panel));
	CDKMENU *Menu		=newCDKMenu 		(Cdk, Menu_List, Items, Submenu_Size, Menu_Loc, TOP, A_UNDERLINE, A_REVERSE); 
 	Selection 	=activateCDKMenu 	(Menu,0); 
	if (Menu->exitType == vNORMAL) 
		Parse_Menu_Menu(Selection);
	destroyCDKMenu 		(Menu);
	destroyCDKScreen 	(Cdk);
	Main_Sheet->Redraw_Box();
	Main_Sheet->Touch_Win();
}
char* Menu::Set_File_Select (PANEL* Panel)
{
	char 				*File_Name;
	static char 			New_File_Name[1000];
	CDKSCREEN 	*Cdk		=initCDKScreen (panel_window(Panel));
	CDKFSELECT 	*File_Select 	=newCDKFselect (Cdk,CENTER,CENTER,20,65,"Select File","",A_NORMAL,'_', A_REVERSE,"</5>","</48>","</N>","</N>",TRUE,FALSE);
	
   	File_Name = copyChar(activateCDKFselect(File_Select,0));
	if (File_Select->exitType == vNORMAL) 
		strcpy(New_File_Name,File_Name);
	else strcpy(New_File_Name,"");
	destroyCDKFselect(File_Select);
	destroyCDKScreen(Cdk);
	return New_File_Name;
}

unsigned char Menu::Set_Entry (PANEL* Panel,const char* Title,const char* Actual_Data,char* Data,unsigned short int Length)
{
	char 	*Info,Ans=1;
	CDKSCREEN 	*Cdk 	=initCDKScreen 		(panel_window(Panel));
   	CDKENTRY 	*Entry 	=newCDKEntry(Cdk,CENTER,CENTER,Title,Actual_Data,A_NORMAL,'.',vMIXED,20,0,Length,TRUE,TRUE);
   	Info=activateCDKEntry(Entry, 0);
  	if (Entry->exitType == vNORMAL) {
		Ans=0;
		strcpy(Data,Info);
	}
   	destroyCDKEntry 	(Entry);
	destroyCDKScreen 	(Cdk);
	return Ans;
}

//-------------------------------------------------------------------
Sheet* Menu::Sheet4Top_Panel(void)
{
	return Sheet4Panel(panel_below(0));	
}
Sheet* Menu::Sheet4Panel(PANEL* Panel)
{
	return (Sheet*)(panel_userptr(Panel));
}
//----------------------------------------------------------------------------------------------------
void Menu::Start_Menu_Menu 	(void)/*{{{*/
{
	int 			Submenu_Size[]={3,2,4},Menu_Loc[]={LEFT,LEFT,RIGHT};
	const char 		*Menu_List[MAX_MENU_ITEMS][MAX_SUB_ITEMS]= { 
					{
						"</B>File<!B>",
						"</B>Save<!B>",
						"</B>Exit<!B>",
					},
					{
						"</B>Sheets<!B>",
						"</B>New<!B>",
					},
{
						"</B>Help<!B>",
						"</B>On Edit <!B>",
						"</B>On File <!B>",
						"</B>About...<!B>",
					},
				};
	Set_Menu (Main_Sheet->Panel,Menu_List,3,Submenu_Size,Menu_Loc);
}
void Menu::Parse_Menu_Menu 	(int Selection)
{
	switch(Selection) {	
		case 000:
			Set_File_Select(Main_Sheet->Panel);
			break;
		case 001:
			endCDK();
			exit(0);
			break;
		case 100:
			break;
		}
}/*}}}*/
//----------------------------------------------------------------------------------------------------

